--- qt5/main_window.h.orig	2019-10-23 17:19:38.000000000 +0100
+++ qt5/main_window.h	2019-10-26 14:46:01.000000000 +0100
@@ -107,7 +107,7 @@
 	void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;
 	void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
 	void keyReleaseEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
-#if defined(Q_OS_WIN32)
+#if defined(Q_OS_WIN32) || defined(Q_OS_MACOS)
 	bool nativeEvent(const QByteArray &eventType, void *message, long *result) Q_DECL_OVERRIDE;
 #endif /* Q_OS_WIN32 */
 	
@@ -163,8 +163,8 @@
 
 	void cdrom_menu_selection_update(const QAction *cdrom_action);
 
-	void native_keypress_event(unsigned scan_code);
-	void native_keyrelease_event(unsigned scan_code);
+	void native_keypress_event(unsigned scan_code, unsigned modifiers);
+	void native_keyrelease_event(unsigned scan_code, unsigned modifiers);
 	void release_held_keys();
 
 	bool full_screen;
