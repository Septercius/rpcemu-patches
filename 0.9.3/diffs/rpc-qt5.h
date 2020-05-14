--- original/qt5/rpc-qt5.h	2020-05-06 20:19:23.000000000 +0100
+++ src/qt5/rpc-qt5.h	2020-05-07 21:14:11.000000000 +0100
@@ -49,6 +49,11 @@
 	void key_press_signal(unsigned scan_code);
 
 	void key_release_signal(unsigned scan_code);
+    
+#if defined(Q_OS_MACOS)
+    void modifier_keys_changed_signal(unsigned mask);
+    void modifier_keys_reset_signal();
+#endif /* Q_OS_MACOS */
 
 	void mouse_move_signal(int x, int y);
 	void mouse_move_relative_signal(int dx, int dy);
@@ -78,6 +83,11 @@
 	void key_press(unsigned scan_code);
 
 	void key_release(unsigned scan_code);
+    
+#if defined(Q_OS_MACOS)
+    void modifier_keys_changed(unsigned mask);
+    void modifier_keys_reset();
+#endif /* Q_OS_MACOS */
 
 	void mouse_move(int x, int y);
 	void mouse_move_relative(int dx, int dy);
