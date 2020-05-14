--- qt5/main_window.cpp.orig	2019-10-23 17:19:38.000000000 +0100
+++ qt5/main_window.cpp	2019-10-26 14:49:41.000000000 +0100
@@ -31,7 +31,12 @@
 
 #if defined(Q_OS_WIN32)
 #include "Windows.h"
-#endif /* Q_OS_WIN32 */ 
+#endif /* Q_OS_WIN32 */
+
+#if defined(Q_OS_MACOS)
+#include "macosx/events-macosx.h"
+#include "keyboard_macosx.h"
+#endif /* Q_OS_MACOS */
 
 #include "rpcemu.h"
 #include "keyboard.h"
@@ -66,6 +71,9 @@
 void
 MainDisplay::mouseMoveEvent(QMouseEvent *event)
 {
+    // Ignore mouse events if the application is terminating.
+    if (quited) return;
+    
 	if((!pconfig_copy->mousehackon && mouse_captured) || full_screen) {
 		QPoint middle;
 
@@ -90,6 +98,9 @@
 void
 MainDisplay::mousePressEvent(QMouseEvent *event)
 {
+    // Ignore mouse events if the application is terminating.
+    if (quited) return;
+    
 	// Handle turning on mouse capture in capture mouse mode
 	if(!pconfig_copy->mousehackon) {
 		if(!mouse_captured) {
@@ -110,6 +121,9 @@
 void
 MainDisplay::mouseReleaseEvent(QMouseEvent *event)
 {
+    // Ignore mouse events if the application is terminating.
+    if (quited) return;
+    
 	if (event->button() & 7) {
 		emit this->emulator.mouse_release_signal(event->button() & 7);
 	}
@@ -423,6 +437,11 @@
 
 	// Clear the list of keys considered to be held in the host
 	held_keys.clear();
+    
+#if defined(Q_OS_MACOS)
+    emit this->emulator.modifier_keys_reset_signal();
+#endif /* Q_OS_MACOS */
+    
 }
 
 /**
@@ -485,7 +504,11 @@
 	}
 
 	// Special case, check for Ctrl-End, our multi purpose do clever things key
-	if((Qt::Key_End == event->key()) && (event->modifiers() & Qt::ControlModifier)) {
+    #if defined(Q_OS_MACOS)
+      if (keyboard_check_special_keys(event->nativeVirtualKey(), event->nativeModifiers())) {
+    #else
+        if((Qt::Key_End == event->key()) && (event->modifiers() & Qt::ControlModifier)) {
+    #endif
 		if(full_screen) {
 			// Change Full Screen -> Windowed
 
@@ -531,7 +554,11 @@
 
 	// Regular case pass key press onto the emulator
 	if (!event->isAutoRepeat()) {
-		native_keypress_event(event->nativeScanCode());
+        #if defined(Q_OS_MACOS)
+                native_keypress_event(event->nativeVirtualKey(), event->nativeModifiers());
+        #else
+                native_keypress_event(event->nativeScanCode(), event->nativeModifiers());
+        #endif    /* Q_OS_MACOS */
 	}
 }
 
@@ -551,7 +578,11 @@
 
 	// Regular case pass key release onto the emulator
 	if (!event->isAutoRepeat()) {
-		native_keyrelease_event(event->nativeScanCode());
+#if defined(Q_OS_MACOS)
+        native_keyrelease_event(event->nativeVirtualKey(), event->nativeModifiers());
+#else
+        native_keyrelease_event(event->nativeScanCode(), event->nativeModifiers());
+#endif    /* Q_OS_MACOS */
 	}
 }
 
@@ -561,8 +592,25 @@
  * @param scan_code Native scan code of key
  */
 void
-MainWindow::native_keypress_event(unsigned scan_code)
+MainWindow::native_keypress_event(unsigned scan_code, unsigned modifiers)
 {
+#if defined(Q_OS_MACOS)
+    if (!(scan_code == 0 && modifiers == 0))
+    {
+        // Check the key isn't already marked as held down (else ignore)
+        // (to deal with potentially inconsistent host messages)
+        bool found = (std::find(held_keys.begin(), held_keys.end(), scan_code) != held_keys.end());
+
+        if (!found) {
+            // Add the key to the list of held_keys, that will be released
+            // when the window loses the focus
+            held_keys.insert(held_keys.end(), scan_code);
+
+            emit this->emulator.key_press_signal(scan_code);
+        }
+    }
+#else
+    
 	// Check the key isn't already marked as held down (else ignore)
 	// (to deal with potentially inconsistent host messages)
 	bool found = (std::find(held_keys.begin(), held_keys.end(), scan_code) != held_keys.end());
@@ -572,8 +620,9 @@
 		// when the window loses the focus
 		held_keys.insert(held_keys.end(), scan_code);
 
-		emit this->emulator.key_press_signal(scan_code);
+
 	}
+#endif
 }
 
 /**
@@ -582,8 +631,26 @@
  * @param scan_code Native scan code of key
  */
 void
-MainWindow::native_keyrelease_event(unsigned scan_code)
+MainWindow::native_keyrelease_event(unsigned scan_code, unsigned modifiers)
 {
+#if defined(Q_OS_MACOS)
+    
+    if (!(scan_code == 0 && modifiers == 0))
+    {
+        // Check the key is marked as held down (else ignore)
+        // (to deal with potentially inconsistent host messages)
+        bool found = (std::find(held_keys.begin(), held_keys.end(), scan_code) != held_keys.end());
+
+        if (found) {
+            // Remove the key from the list of held_keys, that will be released
+            // when the window loses the focus
+            held_keys.remove(scan_code);
+
+            emit this->emulator.key_release_signal(scan_code);
+        }
+    }
+
+#else
 	// Check the key is marked as held down (else ignore)
 	// (to deal with potentially inconsistent host messages)
 	bool found = (std::find(held_keys.begin(), held_keys.end(), scan_code) != held_keys.end());
@@ -595,6 +662,7 @@
 
 		emit this->emulator.key_release_signal(scan_code);
 	}
+#endif
 }
 
 void
@@ -1480,3 +1548,39 @@
 	return false;
 }
 #endif // Q_OS_WIN32
+
+#if defined(Q_OS_MACOS)
+/**
+ * On OS X, handle additional events for modifier keys.  The normal key press/release
+ * events do not differentiate between left and right.
+ *
+ * @param eventType unused
+ * @param message window event NSEvent data
+ * @param result unused
+ * @return bool of whether we've handled the event (true) or OS X/QT should deal with it (false)
+ */
+bool
+MainWindow::nativeEvent(const QByteArray &eventType, void *message, long *result)
+{
+    Q_UNUSED(eventType);
+    Q_UNUSED(result);
+    
+    NativeEvent *event = handle_native_event(message);
+    if (!event->processed)
+    {
+        free(event);
+        return false;
+    }
+    
+    if (event->eventType == nativeEventTypeModifiersChanged)
+    {
+        // Modifier key state has changed.
+        emit this->emulator.modifier_keys_changed_signal(event->modifierMask);
+        free(event);
+    }
+    
+    return true;
+}
+
+#endif /* Q_OS_MACOS */
+
