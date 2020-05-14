--- qt5/settings.cpp.orig	2019-10-23 17:19:38.000000000 +0100
+++ qt5/settings.cpp	2019-10-26 14:30:25.000000000 +0100
@@ -42,7 +42,7 @@
 
 	snprintf(filename, sizeof(filename), "%srpc.cfg", rpcemu_get_datadir());
 
-	QSettings settings("rpc.cfg", QSettings::IniFormat);
+	QSettings settings(filename, QSettings::IniFormat);
 
 	/* Copy the contents of the configfile to the log */
 	QStringList keys = settings.childKeys();
@@ -199,7 +199,7 @@
 
 	snprintf(filename, sizeof(filename), "%srpc.cfg", rpcemu_get_datadir());
 
-	QSettings settings("rpc.cfg", QSettings::IniFormat);
+	QSettings settings(filename, QSettings::IniFormat);
 
 	char s[256];
 
