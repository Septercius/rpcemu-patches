--- qt5/rpc-qt5.h.orig	2019-10-23 17:19:38.000000000 +0100
+++ qt5/rpc-qt5.h	2019-10-26 14:58:14.000000000 +0100
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
@@ -77,6 +82,11 @@
 	void key_press(unsigned scan_code);
 
 	void key_release(unsigned scan_code);
+    
+#if defined(Q_OS_MACOS)
+    void modifier_keys_changed(unsigned mask);
+    void modifier_keys_reset();
+#endif /* Q_OS_MACOS */
 
 	void mouse_move(int x, int y);
 	void mouse_move_relative(int dx, int dy);
