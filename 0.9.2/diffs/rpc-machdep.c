--- rpc-machdep.c.orig	2019-10-23 17:19:38.000000000 +0100
+++ rpc-machdep.c	2019-10-26 14:50:33.000000000 +0100
@@ -26,7 +26,39 @@
    be, but currently this version is used by Linux, all the other autoconf
    based builds and Windows. Only Mac OS X GUI version needs to override */
 
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
 static char datadir[512] = "./";
+#endif
+
 static char logpath[1024] = "";
 
 /**
