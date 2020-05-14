diff --git a/src/qt5/keyboard_macosx.h b/src/qt5/keyboard_macosx.h
index 12121b8..a46956a 100644
--- a/src/qt5/keyboard_macosx.h
+++ b/src/qt5/keyboard_macosx.h
@@ -30,7 +30,7 @@ extern "C" {
 extern void keyboard_handle_modifier_keys(uint32_t mask);
 extern void keyboard_reset_modifiers(int sendReleaseEvent);
 extern void keyboard_configure_layout(const char *layoutName);
-extern int keyboard_check_special_keys(unsigned scan_code, unsigned modifiers);
+extern int keyboard_check_special_keys();
     
 #ifdef __cplusplus
 }
