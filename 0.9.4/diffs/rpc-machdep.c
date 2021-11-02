--- original/rpc-machdep.c	2021-10-31 13:28:31.000000000 +0000
+++ src/rpc-machdep.c	2021-11-01 19:29:13.000000000 +0000
@@ -26,7 +26,39 @@
    be, but currently this version is used by Linux, all the other autoconf
    based builds and Windows. Only Mac OS X GUI version needs to override */
 
-static char datadir[512] = "/Users/Timothy/Public/Projects/RPCEmu/originals/0.9.4/";
+#ifdef __APPLE__
+#include <dirent.h>
+
+static char datadir[512] = "";
+
+int rpcemu_set_datadir(const char *path)
+{
+  int len = strlen(path);
+  if (len == 0) return 0;
+
+  if (path[len - 1] != '/')
+  {
+    snprintf(datadir, 512, "%s/", path);
+  }
+  else
+  {
+    strncpy(datadir, path, 512);
+  }
+
+  DIR *ptr = opendir(datadir);
+  if (ptr)
+  {
+    closedir(ptr);
+    return 1;
+  }
+
+  return 0;
+}
+
+#else
+static char datadir[512] = "./";
+#endif
+
 static char logpath[1024] = "";
 
 /**
