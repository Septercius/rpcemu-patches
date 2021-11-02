--- original/qt5/rpc-qt5.h	2021-10-28 16:57:41.000000000 +0100
+++ src/qt5/rpc-qt5.h	2021-11-01 19:29:13.000000000 +0000
@@ -51,7 +51,12 @@
 	void key_press_signal(unsigned scan_code);
 
 	void key_release_signal(unsigned scan_code);
-
+    
+#if defined(Q_OS_MACOS)
+    void modifier_keys_changed_signal(unsigned mask);
+    void modifier_keys_reset_signal();
+#endif /* Q_OS_MACOS */
+    
 	void mouse_move_signal(int x, int y);
 	void mouse_move_relative_signal(int dx, int dy);
 	void mouse_press_signal(int buttons);
@@ -85,7 +90,12 @@
 	void key_press(unsigned scan_code);
 
 	void key_release(unsigned scan_code);
-
+   
+#if defined(Q_OS_MACOS)
+    void modifier_keys_changed(unsigned mask);
+    void modifier_keys_reset();
+#endif /* Q_OS_MACOS */
+    
 	void mouse_move(int x, int y);
 	void mouse_move_relative(int dx, int dy);
 	void mouse_press(int buttons);
