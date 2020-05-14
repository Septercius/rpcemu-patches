diff --git a/src/qt5/keyboard_macosx.c b/src/qt5/keyboard_macosx.c
index 0deed64..9b57af7 100644
--- a/src/qt5/keyboard_macosx.c
+++ b/src/qt5/keyboard_macosx.c
@@ -341,13 +341,11 @@ void keyboard_configure_layout(const char *layoutName)
     }
     else
     {
-    fprintf(stderr, "Using keyboard layout '%s' (%d).\n", layoutName, keyboardType);
+        fprintf(stderr, "Using keyboard layout '%s' (%d).\n", layoutName, keyboardType);
     }
 }
 
-int keyboard_check_special_keys(unsigned scanCode, unsigned modifiers)
+int keyboard_check_special_keys()
 {
-  UNUSED(modifiers);
-  
-  return (modifierState.keyState[modifierKeyStateControl] != 0 && scanCode == kVK_End);
+    return (modifierState.keyState[modifierKeyStateControl] != 0 && modifierState.keyState[modifierKeyStateCommand] != 0);
 }
