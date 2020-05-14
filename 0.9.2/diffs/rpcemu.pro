--- qt5/rpcemu.pro.orig	2019-10-23 17:19:38.000000000 +0100
+++ qt5/rpcemu.pro	2019-11-03 13:56:33.000000000 +0000
@@ -6,6 +6,10 @@
 QT += core widgets gui multimedia
 INCLUDEPATH += ../
 
+macx {
+	INCLUDEPATH += ../macosx
+}
+
 # This ensures that using switch with enum requires every value to be handled
 QMAKE_CFLAGS += -Werror=switch
 QMAKE_CXXFLAGS += -Werror=switch
@@ -61,7 +65,7 @@
 		plt_sound.cpp
 
 # NAT Networking
-linux | win32 {
+linux | win32 | macx {
 	HEADERS +=	../network-nat.h
 	SOURCES += 	../network-nat.c
 
@@ -141,10 +145,38 @@
 			network_dialog.h
 }
 
-unix {
-	SOURCES +=	keyboard_x.c \
-			../hostfs-unix.c \
-			../rpc-linux.c
+!macx {
+	unix {
+		SOURCES +=	keyboard_x.c \
+				../hostfs-unix.c \
+				../rpc-linux.c
+	}
+}
+
+macx {
+	SOURCES +=	../network.c \
+			network_dialog.cpp \
+			keyboard_macosx.c \
+			../hostfs-macosx.c \
+			../rpc-macosx.c \
+			../macosx/hid-macosx.m \
+			../macosx/events-macosx.m \
+			../macosx/preferences-macosx.m \
+			../macosx/network-macosx.c \
+			../macosx/system-macosx.m \
+			choose_dialog.cpp
+
+	HEADERS +=	../network.h \
+			network_dialog.h \
+			keyboard_macosx.h \
+			../macosx/hid-macosx.h \
+			../macosx/events-macosx.h \
+			../macosx/preferences-macosx.h \
+			../macosx/system-macosx.h \
+			choose_dialog.h
+
+	ICON =		../macosx/rpcemu.icns
+			
 }
 
 # Place exes in top level directory
@@ -189,4 +221,13 @@
 	TARGET = $$join(TARGET, , , -debug)
 }
 
-LIBS +=
+!macx {
+	LIBS +=
+}
+
+macx {
+	LIBS += -framework coreFoundation -framework IOKit -framework Foundation -framework Carbon
+
+	QMAKE_INFO_PLIST = ../macosx/Info.plist
+}
+
