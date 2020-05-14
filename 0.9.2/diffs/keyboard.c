--- keyboard.c.orig	2019-10-23 17:19:38.000000000 +0100
+++ keyboard.c	2019-10-26 14:40:35.000000000 +0100
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
@@ -254,6 +258,10 @@
 	/* Mousehack reset */
 	mouse_hack.pointer = 0;
 	mouse_hack.cursor_linked = 1;
+    
+#ifdef __APPLE__
+    keyboard_reset_modifiers(0);
+#endif
 }
 
 static uint8_t
@@ -731,6 +739,7 @@
 	{
 		uint8_t tmp;
 
+#ifndef __APPLE__
 		if (config.mousetwobutton) {
 			/* To help people with only two buttons on their mouse,
 			   swap the behaviour of middle and right buttons */
@@ -740,6 +749,7 @@
 
 			mouseb = mousel | (mousem << 1) | (mouser << 2);
 		}
+#endif
 
 		tmp = (mouseb & 7) | 8;
 
@@ -1192,6 +1202,15 @@
 	if (mouse.buttons & 1) { 
 		buttons |= 4;			/* Left button */
 	}
+    
+#ifdef __APPLE__
+    if (mouse.buttons & 2) {
+        buttons |= 1;        /* Right button */
+    }
+    if (mouse.buttons & 4) {
+        buttons |= 2;         /* Middle button */
+    }
+#else
 	if (config.mousetwobutton) {
 		/* To help people with only two buttons on their mouse, swap
 		   the behaviour of middle and right buttons */
@@ -1209,6 +1228,8 @@
 			buttons |= 2; 		/* Middle button */
 		}
 	}
+#endif
+    
 	arm.reg[2] = buttons;
 
 	arm.reg[3] = 0; /* R3 = time of button change */
@@ -1258,4 +1279,4 @@
 	mouse_osunits_to_host(osx, osy, &x, &y);
 
 	rpcemu_move_host_mouse(x, y);
-}
\ No newline at end of file
+}
