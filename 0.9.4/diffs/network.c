--- original/network.c	2021-10-28 16:57:41.000000000 +0100
+++ src/network.c	2021-11-01 19:29:13.000000000 +0000
@@ -74,6 +74,7 @@
 {
 	FILE *f;
 	size_t module_file_size = 0;
+    char filename[512];
 
 	// Build podule header
 	chunkbase = 0x10;
@@ -81,7 +82,10 @@
 	poduleromsize = filebase + ((sizeof(description) + 3) & ~3u); // Word align description string
 
 	// Add on size for driver module if it can be opened successfully
-	f = fopen("netroms/EtherRPCEm,ffa", "rb");
+    snprintf(filename,sizeof(filename), "%snetroms/EtherRPCEm,ffa", rpcemu_get_datadir());
+    rpclog("network_rom_init: Attempting to load Ethernet ROM from '%s'\n", filename);
+    
+	f = fopen(filename, "rb");
 	if (f != NULL) {
 		long len;
 
@@ -125,6 +129,8 @@
 			len = (len + 3) & ~3u;
 			makechunk(0x81, filebase, (uint32_t) len); // 0x81 = RISC OS, ROM
 		}
+        
+        rpclog("network_rom_init: Successfuly loaded 'EtherRPCEm,ffa' into podulerom\n");
 	}
 }
 
