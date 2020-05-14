--- hostfs.c.orig	2019-10-23 17:19:38.000000000 +0100
+++ hostfs.c	2019-10-26 15:00:09.000000000 +0100
@@ -273,6 +273,9 @@
     case '>':
       *host_path++ = '^';
       break;
+    case (char) 160:
+      *host_path++ = ' ';
+      break;
     default:
       *host_path++ = *path;
       break;
@@ -539,7 +542,7 @@
   while ((entry = readdir(d)) != NULL) {
     char entry_path[PATH_MAX], ro_leaf[PATH_MAX];
 
-    /* Ignore the current directory and it's parent */
+    /* Ignore the current directory and its parent */
     if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
       continue;
     }
@@ -1650,7 +1653,7 @@
     char entry_path[PATH_MAX], ro_leaf[PATH_MAX];
     unsigned string_space;
 
-    /* Ignore the current directory and it's parent */
+    /* Ignore the current directory and its parent */
     if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
       continue;
     }
