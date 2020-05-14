diff --git a/src/qt5/main_window.h b/src/qt5/main_window.h
index 4b02b3c..e079b00 100644
--- a/src/qt5/main_window.h
+++ b/src/qt5/main_window.h
@@ -166,6 +166,8 @@ private:
 	void native_keypress_event(unsigned scan_code, unsigned modifiers);
 	void native_keyrelease_event(unsigned scan_code, unsigned modifiers);
 	void release_held_keys();
+    
+    void processMagicKeys();
 
 	bool full_screen;
 	bool reenable_mousehack; ///< Did we disable mousehack entering fullscreen and have to reenable it on leaving fullscreen?
