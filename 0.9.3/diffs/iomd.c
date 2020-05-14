--- original/iomd.c	2020-05-06 20:19:23.000000000 +0100
+++ src/iomd.c	2020-05-07 21:05:20.000000000 +0100
@@ -840,19 +840,28 @@
 	}
 	/* Middle */
 	if (mouse_buttons & 4) {
+        
+#ifdef __APPLE__
+        temp |= 0x20;
+#else
 		if (config.mousetwobutton) {
 			temp |= 0x10; // bit 4
 		} else {
 			temp |= 0x20; // bit 5
 		}
+#endif
 	}
 	/* Right */
 	if (mouse_buttons & 2) {
+#ifdef __APPLE__
+        temp |= 0x10;
+#else
 		if (config.mousetwobutton) {
 			temp |= 0x20; // bit 5
 		} else {
 			temp |= 0x10; // bit 4
 		}
+#endif
 	}
 
 	/* bit 0 contains the monitor id bit, 0 for VGA, 1 for TV type monitors.
