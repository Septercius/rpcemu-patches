--- original/rpcemu.h	2020-05-06 20:19:23.000000000 +0100
+++ src/rpcemu.h	2020-05-07 21:14:11.000000000 +0100
@@ -72,7 +72,7 @@
 /* Note that networking is currently supported on Mac OS X with the Cocoa GUI
    version but not with the Allegro GUI. */
 #if defined __linux || defined __linux__ || defined WIN32 || defined _WIN32 || \
-    defined RPCEMU_COCOA_GUI
+    defined RPCEMU_COCOA_GUI || __APPLE__
 #define RPCEMU_NETWORKING
 #endif
 
@@ -169,6 +169,10 @@
 extern uint32_t inscount;
 extern int cyccount;
 
+#ifdef __APPLE__
+extern int rpcemu_set_datadir(const char *path);
+#endif
+
 /* These functions can optionally be overridden by a platform. If not
    needed to be overridden, there is a generic version in rpc-machdep.c */
 extern const char *rpcemu_get_datadir(void);
