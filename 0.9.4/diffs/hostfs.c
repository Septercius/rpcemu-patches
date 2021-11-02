--- original/hostfs.c	2021-10-28 16:57:41.000000000 +0100
+++ src/hostfs.c	2021-11-01 19:29:13.000000000 +0000
@@ -270,6 +270,9 @@
     case '<':
       *host_path++ = '$';
       break;
+    case (char) 160:
+      *host_path++ = ' ';
+      break;
     case '>':
       *host_path++ = '^';
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
