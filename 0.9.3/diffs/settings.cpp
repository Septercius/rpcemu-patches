--- original/qt5/settings.cpp	2020-05-06 20:19:23.000000000 +0100
+++ src/qt5/settings.cpp	2020-05-07 21:14:11.000000000 +0100
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
 
