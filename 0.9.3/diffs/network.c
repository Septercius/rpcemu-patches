--- original/network.c	2020-05-06 20:19:23.000000000 +0100
+++ src/network.c	2020-05-07 21:14:11.000000000 +0100
@@ -80,8 +80,13 @@
 	filebase = chunkbase + (8 * 2) + 4; // required size for two entries
 	poduleromsize = filebase + ((sizeof(description) + 3) & ~3u); // Word align description string
 
-	// Add on size for driver module if it can be opened successfully
-	f = fopen("netroms/EtherRPCEm,ffa", "rb");
+    char filename[512];
+    snprintf(filename,sizeof(filename), "%snetroms/EtherRPCEm,ffa", rpcemu_get_datadir());
+    
+    rpclog("network_rom_init: Attempting to load Ethernet ROM from '%s'\n", filename);
+    
+    // Add on size for driver module if it can be opened successfully
+    f = fopen(filename, "rb");
 	if (f != NULL) {
 		long len;
 
@@ -124,6 +129,8 @@
 		if (len == module_file_size) { // Load was OK
 			len = (len + 3) & ~3u;
 			makechunk(0x81, filebase, (uint32_t) len); // 0x81 = RISC OS, ROM
+            
+            rpclog("network_rom_init: Successfuly loaded 'EtherRPCEm,ffa' into podulerom\n");
 		}
 	}
 }
