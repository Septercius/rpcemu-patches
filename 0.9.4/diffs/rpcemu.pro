--- original/qt5/rpcemu.pro	2021-10-31 13:22:03.000000000 +0000
+++ src/qt5/rpcemu.pro	2021-11-01 19:29:13.000000000 +0000
@@ -6,6 +6,10 @@
 QT += core widgets gui multimedia
 INCLUDEPATH += ../
 
+macx {
+  INCLUDEPATH += ../macosx
+}
+
 # -Werror=switch
 #	Ensures that using switch with enum requires every value to be handled
 # -fno-common
@@ -74,7 +78,7 @@
 		plt_sound.cpp
 
 # NAT Networking
-linux | win32 {
+linux | win32 | macx {
 	HEADERS +=	../network-nat.h \
 			nat_edit_dialog.h \
 			nat_list_dialog.h
@@ -158,10 +162,37 @@
 			network_dialog.h
 }
 
-unix {
+!macx {
+  unix {
 	SOURCES +=	keyboard_x.c \
 			../hostfs-unix.c \
 			../rpc-linux.c
+  }
+}
+
+macx {
+  SOURCES +=		../network.c \
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
+  HEADERS +=		../network.h \
+			network_dialog.h \
+			keyboard_macosx.h \
+			../macosx/hid-macosx.h \
+			../macosx/events-macosx.h \
+			../macosx/preferences-macosx.h \
+			../macosx/system-macosx.h \
+			choose_dialog.h
+
+  ICON =		../macosx/rpcemu.icns
 }
 
 # Place exes in top level directory
@@ -206,4 +237,14 @@
 	TARGET = $$join(TARGET, , , -debug)
 }
 
-LIBS +=
+!macx {
+  LIBS +=
+}
+
+macx {
+	LIBS += -framework coreFoundation -framework IOKit -framework Foundation -framework Carbon
+
+	QMAKE_INFO_PLIST = ../macosx/Info.plist
+	QMAKE_BUNDLE = rpcemu
+	QMAKE_TARGET_BUNDLE_PREFIX = org.marutan.
+}
