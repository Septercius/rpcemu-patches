diff --git a/src/qt5/main_window.cpp b/src/qt5/main_window.cpp
index 362054c..6bda8a3 100644
--- a/src/qt5/main_window.cpp
+++ b/src/qt5/main_window.cpp
@@ -504,52 +504,9 @@ MainWindow::keyPressEvent(QKeyEvent *event)
 	}
 
 	// Special case, check for Ctrl-End, our multi purpose do clever things key
-    #if defined(Q_OS_MACOS)
-      if (keyboard_check_special_keys(event->nativeVirtualKey(), event->nativeModifiers())) {
-    #else
-        if((Qt::Key_End == event->key()) && (event->modifiers() & Qt::ControlModifier)) {
-    #endif
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
+    if((Qt::Key_End == event->key()) && (event->modifiers() & Qt::ControlModifier))
+    {
+        processMagicKeys();
 	}
 
 	// Regular case pass key press onto the emulator
@@ -1387,7 +1344,13 @@ MainWindow::mips_timer_timeout()
 
 	if(!pconfig_copy->mousehackon) {
 		if(mouse_captured) {
+            
+#if defined(Q_OS_MACOS)
+            capture_text = " Press CTRL-COMMAND to release mouse";
+#else
 			capture_text = " Press CTRL-END to release mouse";
+#endif
+            
 		} else {
 			capture_text = " Click to capture mouse";
 		}
@@ -1490,6 +1453,52 @@ MainWindow::cdrom_menu_selection_update(const QAction *cdrom_action)
 	}
 }
 
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
+
 #if defined(Q_OS_WIN32)
 /**
  * windows pre event handler used by us to modify some default behaviour
@@ -1576,6 +1585,13 @@ MainWindow::nativeEvent(const QByteArray &eventType, void *message, long *result
     {
         // Modifier key state has changed.
         emit this->emulator.modifier_keys_changed_signal(event->modifierMask);
+        
+        if (keyboard_check_special_keys())
+        {
+            // Magic key combination to release mouse capture.
+            processMagicKeys();
+        }
+        
         free(event);
     }
     
