--- original/qt5/main_window.cpp	2021-10-31 13:26:13.000000000 +0000
+++ src/qt5/main_window.cpp	2021-11-01 19:29:13.000000000 +0000
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
@@ -366,7 +380,7 @@
 #ifdef RPCEMU_NETWORKING
 	network_dialog = new NetworkDialog(emulator, &config_copy, this);
 #endif /* RPCEMU_NETWORKING */
-//	nat_list_dialog = new NatListDialog(emulator, this);
+	nat_list_dialog = new NatListDialog(emulator, this);
 	about_dialog = new AboutDialog(this);
 
 	// MIPS counting
@@ -445,6 +459,10 @@
 
 	// Clear the list of keys considered to be held in the host
 	held_keys.clear();
+    
+#if defined(Q_OS_MACOS)
+    emit this->emulator.modifier_keys_reset_signal();
+#endif
 }
 
 /**
@@ -507,53 +525,18 @@
 	}
 
 	// Special case, check for Ctrl-End, our multi purpose do clever things key
-	if((Qt::Key_End == event->key()) && (event->modifiers() & Qt::ControlModifier)) {
-		if(full_screen) {
-			// Change Full Screen -> Windowed
-
-			display->set_full_screen(false);
-
-			int host_xsize, host_ysize;
-			display->get_host_size(host_xsize, host_ysize);
-			display->setFixedSize(host_xsize, host_ysize);
-
-			menuBar()->setVisible(true);
-			this->showNormal();
-			this->setFixedSize(this->sizeHint());
-
-			full_screen = false;
-
-			// Request redraw of display
-			display->update();
-			
-			// If we were in mousehack mode before entering fullscreen
-			// return to it now
-			if(reenable_mousehack) {
-				emit this->emulator.mouse_hack_signal();	
-			}
-			reenable_mousehack = false;
-			
-			// If we were in mouse capture mode before entering fullscreen
-			// and we hadn't captured the mouse, display the host cursor now
-			if(!config_copy.mousehackon && !mouse_captured) {
-				this->display->setCursor(Qt::ArrowCursor);
-			}
-			
-			return;
-		} else if(!pconfig_copy->mousehackon && mouse_captured) {
-			// Turn off mouse capture
-			mouse_captured = 0;
-
-			// show pointer in mouse capture mode when it's not been captured
-			this->display->setCursor(Qt::ArrowCursor);
-
-			return;
-		}
-	}
+	if((Qt::Key_End == event->key()) && (event->modifiers() & Qt::ControlModifier))
+	{
+        processMagicKeys();
+    }
 
 	// Regular case pass key press onto the emulator
 	if (!event->isAutoRepeat()) {
-		native_keypress_event(event->nativeScanCode());
+#if defined(Q_OS_MACOS)
+        native_keypress_event(event->nativeVirtualKey(), event->nativeModifiers());
+#else
+        native_keypress_event(event->nativeScanCode(), event->nativeModifiers());
+#endif
 	}
 }
 
@@ -573,7 +556,11 @@
 
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
 
@@ -583,8 +570,24 @@
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
 	// Check the key isn't already marked as held down (else ignore)
 	// (to deal with potentially inconsistent host messages)
 	bool found = (std::find(held_keys.begin(), held_keys.end(), scan_code) != held_keys.end());
@@ -596,6 +599,7 @@
 
 		emit this->emulator.key_press_signal(scan_code);
 	}
+#endif
 }
 
 /**
@@ -604,8 +608,24 @@
  * @param scan_code Native scan code of key
  */
 void
-MainWindow::native_keyrelease_event(unsigned scan_code)
+MainWindow::native_keyrelease_event(unsigned scan_code, unsigned modifiers)
 {
+#if defined(Q_OS_MACOS)
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
+#else
 	// Check the key is marked as held down (else ignore)
 	// (to deal with potentially inconsistent host messages)
 	bool found = (std::find(held_keys.begin(), held_keys.end(), scan_code) != held_keys.end());
@@ -617,6 +637,7 @@
 
 		emit this->emulator.key_release_signal(scan_code);
 	}
+#endif
 }
 
 void
@@ -1309,7 +1330,7 @@
 void
 MainWindow::send_nat_rule_to_gui(PortForwardRule rule)
 {
-//	nat_list_dialog->add_nat_rule(rule);
+	nat_list_dialog->add_nat_rule(rule);
 }
 
 /**
@@ -1341,7 +1362,11 @@
 
 	if(!pconfig_copy->mousehackon) {
 		if(mouse_captured) {
+#if defined(Q_OS_MACOS)
+            capture_text = " Press CTRL-COMMAND to release mouse";
+#else
 			capture_text = " Press CTRL-END to release mouse";
+#endif
 		} else {
 			capture_text = " Click to capture mouse";
 		}
@@ -1443,6 +1468,52 @@
 #endif
 	}
 }
+    
+void
+MainWindow::processMagicKeys()
+{
+    if(full_screen) {
+        // Change Full Screen -> Windowed
+
+        display->set_full_screen(false);
+
+        int host_xsize, host_ysize;
+        display->get_host_size(host_xsize, host_ysize);
+        display->setFixedSize(host_xsize, host_ysize);
+
+        menuBar()->setVisible(true);
+        this->showNormal();
+        this->setFixedSize(this->sizeHint());
+
+        full_screen = false;
+
+        // Request redraw of display
+        display->update();
+
+        // If we were in mousehack mode before entering fullscreen
+        // return to it now
+        if(reenable_mousehack) {
+            emit this->emulator.mouse_hack_signal();
+        }
+        reenable_mousehack = false;
+
+        // If we were in mouse capture mode before entering fullscreen
+        // and we hadn't captured the mouse, display the host cursor now
+        if(!config_copy.mousehackon && !mouse_captured) {
+            this->display->setCursor(Qt::ArrowCursor);
+        }
+
+        return;
+    } else if(!pconfig_copy->mousehackon && mouse_captured) {
+        // Turn off mouse capture
+        mouse_captured = 0;
+
+        // show pointer in mouse capture mode when it's not been captured
+        this->display->setCursor(Qt::ArrowCursor);
+
+        return;
+    }
+}
 
 #if defined(Q_OS_WIN32)
 /**
@@ -1502,3 +1573,46 @@
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
+
+        if (keyboard_check_special_keys())
+        {
+            // Magic key combination to release mouse capture.
+            processMagicKeys();
+        }
+
+        free(event);
+    }
+
+    return true;
+}
+
+#endif /* Q_OS_MACOS */
+    
