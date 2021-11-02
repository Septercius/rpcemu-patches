--- original/keyboard.c	2021-10-28 16:57:41.000000000 +0100
+++ src/keyboard.c	2021-11-01 19:29:13.000000000 +0000
@@ -44,6 +44,10 @@
 #include "arm.h"
 #include "i8042.h"
 
+#ifdef __APPLE__
+#include "keyboard_macosx.h"
+#endif
+
 /* Keyboard Commands */
 #define KBD_CMD_ENABLE		0xf4
 #define KBD_CMD_RESET		0xff
@@ -257,6 +261,10 @@
 	/* Mousehack reset */
 	mouse_hack.pointer = 0;
 	mouse_hack.cursor_linked = 1;
+    
+#ifdef __APPLE__
+    keyboard_reset_modifiers(0);
+#endif
 }
 
 static uint8_t
@@ -734,6 +742,7 @@
 	{
 		uint8_t tmp;
 
+#ifndef __APPLE__
 		if (config.mousetwobutton) {
 			/* To help people with only two buttons on their mouse,
 			   swap the behaviour of middle and right buttons */
@@ -743,6 +752,7 @@
 
 			mouseb = mousel | (mousem << 1) | (mouser << 2);
 		}
+#endif
 
 		tmp = (mouseb & 7) | 8;
 
@@ -1195,6 +1205,17 @@
 	if (mouse.buttons & 1) { 
 		buttons |= 4;			/* Left button */
 	}
+    
+#ifdef __APPLE__
+    if (mouse.buttons & 2)
+    {
+        buttons |= 1;        /* Right button */
+    }
+    if (mouse.buttons & 4)
+    {
+        buttons |= 2;        /* Middle button */
+    }
+#else
 	if (config.mousetwobutton) {
 		/* To help people with only two buttons on their mouse, swap
 		   the behaviour of middle and right buttons */
@@ -1212,6 +1233,8 @@
 			buttons |= 2; 		/* Middle button */
 		}
 	}
+#endif
+    
 	arm.reg[2] = buttons;
 
 	arm.reg[3] = 0; /* R3 = time of button change */
