--- qt5/rpc-qt5.cpp.orig	2019-10-23 17:19:38.000000000 +0100
+++ qt5/rpc-qt5.cpp	2019-10-26 14:57:30.000000000 +0100
@@ -47,6 +47,15 @@
 #include "network.h"
 #include "network-nat.h"
 
+#if defined(Q_OS_MACOS)
+#include "choose_dialog.h"
+
+#include "macosx/preferences-macosx.h"
+#include "macosx/hid-macosx.h"
+
+#include "keyboard_macosx.h"
+#endif /* Q_OS_MACOS */
+
 #if defined(Q_OS_WIN32)
 #include "cdrom-ioctl.h"
 
@@ -398,6 +407,23 @@
 
 } // extern "C"
 
+#if defined(Q_OS_MACOS)
+
+int rpcemu_choose_datadirectory()
+{
+  ChooseDialog dialog;
+  if (dialog.exec() == QDialog::Accepted)
+  {
+    const char *path = preferences_get_data_directory();
+
+    return rpcemu_set_datadir(path);
+  }
+
+  return 0;
+}
+
+#endif
+
 /**
  * Program entry point
  *
@@ -416,6 +442,20 @@
 
 	// Add a program icon
 	QApplication::setWindowIcon(QIcon(":/rpcemu_icon.png"));
+    
+#if defined(Q_OS_MACOS)
+    init_preferences();
+    
+    // If there is not a data directory in the application preferences, prompt for one.
+    // This will also prompt if the "Command" key is held down while the application loads.
+    if (promptForDataDirectory || (QApplication::queryKeyboardModifiers() & Qt::ControlModifier) != 0)
+    {
+        if (!rpcemu_choose_datadirectory())
+        {
+            return 0;
+        }
+    }
+#endif
 	
 	// start enough of the emulator system to allow
 	// the GUI to initialise (e.g. load the config to init
@@ -438,6 +478,11 @@
 	QThread::connect(emulator, &Emulator::finished, emu_thread, &QThread::quit);
 	QThread::connect(emulator, &Emulator::finished, emulator, &Emulator::deleteLater);
 	QThread::connect(emu_thread, &QThread::finished, emu_thread, &QThread::deleteLater);
+    
+#if defined(Q_OS_MACOS)
+    // Initialise the HID manager for CAPS LOCK key events.
+    init_hid_manager();
+#endif
 
 	// Create Main Window
 	MainWindow main_window(*emulator);
@@ -473,6 +518,14 @@
 
 	connect(this, &Emulator::key_release_signal,
 	        this, &Emulator::key_release);
+    
+#if defined(Q_OS_MACOS)
+    // Modifier keys on a Mac must be handled separately, as there is no way of telling
+    // left or right from the key press and key release events due to a lack of scan codes.
+
+    connect(this, &Emulator::modifier_keys_changed_signal, this, &Emulator::modifier_keys_changed);
+    connect(this, &Emulator::modifier_keys_reset_signal, this, &Emulator::modifier_keys_reset);
+#endif /* Q_OS_MACOS */
 
 	connect(this, &Emulator::mouse_move_signal, this, &Emulator::mouse_move);
 	connect(this, &Emulator::mouse_move_relative_signal, this, &Emulator::mouse_move_relative);
@@ -629,6 +682,27 @@
 	keyboard_key_release(scan_codes);
 }
 
+#if defined(Q_OS_MACOS)
+    
+/**
+ * Modifier keys changed
+ * @param mask The modifier key mask from the original NSEvent
+ */
+void Emulator::modifier_keys_changed(unsigned mask)
+{
+    keyboard_handle_modifier_keys(mask);
+}
+
+/**
+ * Modifier keys reset
+ */
+void Emulator::modifier_keys_reset()
+{
+    keyboard_reset_modifiers(true);
+}
+    
+#endif /* Q_OS_MACOS */
+
 /**
  * Mouse has moved in absolute position (mousehack mode)
  * 
