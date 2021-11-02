--- original/iomd.c	2021-10-28 16:57:41.000000000 +0100
+++ src/iomd.c	2021-11-01 19:29:13.000000000 +0000
@@ -840,19 +840,27 @@
 	}
 	/* Middle */
 	if (mouse_buttons & 4) {
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
