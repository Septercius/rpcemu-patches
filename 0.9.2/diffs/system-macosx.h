--- /dev/null	2019-11-03 13:46:16.000000000 +0000
+++ macosx/system-macosx.h	2019-11-02 20:09:34.000000000 +0000
@@ -0,0 +1,34 @@
+/*
+RPCEmu - An Acorn system emulator
+
+Copyright (C) 2017 Peter Howkins
+
+This program is free software; you can redistribute it and/or modify
+it under the terms of the GNU General Public License as published by
+the Free Software Foundation; either version 2 of the License, or
+(at your option) any later version.
+
+This program is distributed in the hope that it will be useful,
+but WITHOUT ANY WARRANTY; without even the implied warranty of
+MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+GNU General Public License for more details.
+
+You should have received a copy of the GNU General Public License
+along with this program; if not, write to the Free Software
+Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
+*/
+
+#ifndef __SYSTEM_MACOSX_H__
+#define __SYSTEM_MACOSX_H__
+
+#ifdef __cplusplus
+extern "C" {
+#endif
+
+extern unsigned int get_macosx_version(void);
+
+#ifdef __cplusplus
+}
+#endif
+
+#endif
