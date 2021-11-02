--- original/qt5/settings.cpp	2021-10-28 16:57:41.000000000 +0100
+++ src/qt5/settings.cpp	2021-11-01 19:29:13.000000000 +0000
@@ -106,7 +106,7 @@
 
 	snprintf(filename, sizeof(filename), "%srpc.cfg", rpcemu_get_datadir());
 
-	QSettings settings("rpc.cfg", QSettings::IniFormat);
+	QSettings settings(filename, QSettings::IniFormat);
 
 	/* Copy the contents of the configfile to the log */
 	QStringList keys = settings.childKeys();
@@ -265,7 +265,7 @@
 
 	snprintf(filename, sizeof(filename), "%srpc.cfg", rpcemu_get_datadir());
 
-	QSettings settings("rpc.cfg", QSettings::IniFormat);
+	QSettings settings(filename, QSettings::IniFormat);
 	settings.clear();
 
 	char s[256];
