--- original/rpcemu.h	2021-10-31 13:22:31.000000000 +0000
+++ src/rpcemu.h	2021-11-01 19:29:13.000000000 +0000
@@ -72,8 +72,8 @@
 /* Note that networking is currently supported on Mac OS X with the Cocoa GUI
    version but not with the Allegro GUI. */
 #if defined __linux || defined __linux__ || defined WIN32 || defined _WIN32 || \
-    defined RPCEMU_COCOA_GUI
-// #define RPCEMU_NETWORKING
+    defined RPCEMU_COCOA_GUI || __APPLE__
+#define RPCEMU_NETWORKING
 #endif
 
 /*This makes the RISC OS mouse pointer follow the host pointer exactly. Useful
@@ -183,6 +183,10 @@
 
 extern uint32_t inscount;
 
+#ifdef __APPLE__
+extern int rpcemu_set_datadir(const char *path);
+#endif
+
 /* These functions can optionally be overridden by a platform. If not
    needed to be overridden, there is a generic version in rpc-machdep.c */
 extern const char *rpcemu_get_datadir(void);
