--- original/qt5/rpc-qt5.cpp	2021-10-31 13:25:34.000000000 +0000
+++ src/qt5/rpc-qt5.cpp	2021-11-01 19:29:13.000000000 +0000
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
 
@@ -416,6 +425,23 @@
 
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
+      return rpcemu_set_datadir(path);
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
@@ -434,6 +460,20 @@
 
 	// Add a program icon
 	QApplication::setWindowIcon(QIcon(":/rpcemu_icon.png"));
+    
+#if defined(Q_OS_MACOS)
+    init_preferences();
+
+    // If there is not a data directory in the application preferences, prompt for one.
+    // This will also prompt if the "Shift" key is held down while the application loads.
+    if (promptForDataDirectory || (QApplication::queryKeyboardModifiers() & Qt::ShiftModifier) != 0)
+    {
+        if (!rpcemu_choose_datadirectory())
+        {
+            return 0;
+        }
+    }
+#endif
 	
 	// start enough of the emulator system to allow
 	// the GUI to initialise (e.g. load the config to init
@@ -457,6 +497,11 @@
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
@@ -495,6 +540,14 @@
 
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
@@ -584,7 +637,7 @@
 		if (config.network_type == NetworkType_NAT) {
 			network_nat_rate++;
 			if ((network_nat_rate & 0x3) == 0) {
-//				network_nat_poll();
+				network_nat_poll();
 			}
 		}
 	}
@@ -667,6 +720,27 @@
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
@@ -961,9 +1035,9 @@
 	QByteArray ba_ipaddress = ipaddress.toUtf8();
 	const char *ip_address = ba_ipaddress.constData();
 
-//	if (network_config_changed(network_type, bridge_name, ip_address)) {
-//		this->reset();
-//	}
+	if (network_config_changed(network_type, bridge_name, ip_address)) {
+		this->reset();
+	}
 }
 
 /**
@@ -987,10 +1061,10 @@
 Emulator::nat_rule_add(PortForwardRule rule)
 {
 	// Activate the rule changes
-//	network_nat_forward_add(rule);
+	network_nat_forward_add(rule);
 
 	// Update the stored list of rules
-//	rpcemu_nat_forward_add(rule);
+	rpcemu_nat_forward_add(rule);
 
 	// Save the settings to the rpc.cfg file
 	config_save(&config);
@@ -1006,14 +1080,14 @@
 Emulator::nat_rule_edit(PortForwardRule old_rule, PortForwardRule new_rule)
 {
 	// Activate the rule changes
-//	network_nat_forward_edit(old_rule, new_rule);
+	network_nat_forward_edit(old_rule, new_rule);
 
 	// Update the stored list of rules
-//	rpcemu_nat_forward_remove(old_rule);
-//	rpcemu_nat_forward_add(new_rule);
+	rpcemu_nat_forward_remove(old_rule);
+	rpcemu_nat_forward_add(new_rule);
 
 	// Save the settings to the rpc.cfg file
-//	config_save(&config);
+	config_save(&config);
 }
 
 /**
@@ -1025,13 +1099,13 @@
 Emulator::nat_rule_remove(PortForwardRule rule)
 {
 	// Activate the rule changes
-//	network_nat_forward_remove(rule);
+	network_nat_forward_remove(rule);
 
 	// Update the stored list of rules
-//	rpcemu_nat_forward_remove(rule);
+	rpcemu_nat_forward_remove(rule);
 
 	// Save the settings to the rpc.cfg file
-//	config_save(&config);
+	config_save(&config);
 }
 
 #ifdef __cplusplus
