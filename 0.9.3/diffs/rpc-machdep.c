--- original/rpc-machdep.c	2020-05-06 20:19:23.000000000 +0100
+++ src/rpc-machdep.c	2020-05-07 21:05:20.000000000 +0100
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
