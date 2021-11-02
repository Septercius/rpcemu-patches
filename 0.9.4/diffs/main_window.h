--- original/qt5/main_window.h	2021-10-28 16:57:41.000000000 +0100
+++ src/qt5/main_window.h	2021-11-01 19:29:13.000000000 +0000
@@ -110,7 +110,7 @@
 	void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;
 	void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
 	void keyReleaseEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
-#if defined(Q_OS_WIN32)
+#if defined(Q_OS_WIN32) || defined(Q_OS_MACOS)
 	bool nativeEvent(const QByteArray &eventType, void *message, long *result) Q_DECL_OVERRIDE;
 #endif /* Q_OS_WIN32 */
 	
@@ -169,9 +169,11 @@
 
 	void cdrom_menu_selection_update(const QAction *cdrom_action);
 
-	void native_keypress_event(unsigned scan_code);
-	void native_keyrelease_event(unsigned scan_code);
+	void native_keypress_event(unsigned scan_code, unsigned modifiers);
+	void native_keyrelease_event(unsigned scan_code, unsigned modifiers);
 	void release_held_keys();
+    
+    void processMagicKeys();
 
 	bool full_screen;
 	bool reenable_mousehack; ///< Did we disable mousehack entering fullscreen and have to reenable it on leaving fullscreen?
