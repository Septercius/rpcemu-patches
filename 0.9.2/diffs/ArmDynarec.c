--- ../../original/src/ArmDynarec.c	2019-10-23 17:19:38.000000000 +0100
+++ ArmDynarec.c	2020-03-02 21:09:17.000000000 +0000
@@ -571,12 +571,39 @@
 {
 	const long page_size = sysconf(_SC_PAGESIZE);
 	const long page_mask = ~(page_size - 1);
-	void *start;
+	void *start, *addr;
 	long end;
+    int mmap_flags = 0;
 
 	start = (void *) ((long) ptr & page_mask);
 	end = ((long) ptr + len + page_size - 1) & page_mask;
 	len = (size_t) (end - (long) start);
+    
+#if __APPLE__
+    // More up-to-date versions of OS X require "mmap" to be called prior to "mprotect".
+    // Certain versions also require the MAP_JIT flag as well.
+    // Try without first, and if that fails, add the flag in.    
+    mmap_flags = MAP_PRIVATE | MAP_ANON | MAP_FIXED;
+    
+    addr = mmap(NULL, page_size, PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANON, -1, 0);
+    if (addr == MAP_FAILED)
+    {
+        mmap_flags |= MAP_JIT;
+    }
+    else
+    {
+        munmap(addr, page_size);
+    }
+    
+    addr = mmap(start, len, PROT_READ | PROT_WRITE | PROT_EXEC, mmap_flags, -1, 0);
+    
+    if (addr == MAP_FAILED)
+    {
+        perror("mmap");
+        exit(1);
+    }
+
+#endif
 
 	if (mprotect(start, len, PROT_READ | PROT_WRITE | PROT_EXEC) != 0) {
 		perror("mprotect");
