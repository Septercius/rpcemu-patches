--- /dev/null	2021-11-02 20:38:02.000000000 +0000
+++ src/qt5/moc_rpc-qt5.cpp	2021-10-31 18:47:00.000000000 +0000
@@ -0,0 +1,766 @@
+/****************************************************************************
+** Meta object code from reading C++ file 'rpc-qt5.h'
+**
+** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
+**
+** WARNING! All changes made in this file will be lost!
+*****************************************************************************/
+
+#include "rpc-qt5.h"
+#include <QtCore/qbytearray.h>
+#include <QtCore/qmetatype.h>
+#if !defined(Q_MOC_OUTPUT_REVISION)
+#error "The header file 'rpc-qt5.h' doesn't include <QObject>."
+#elif Q_MOC_OUTPUT_REVISION != 67
+#error "This file was generated using the moc from 5.12.11. It"
+#error "cannot be used with the include files from this version of Qt."
+#error "(The moc has changed too much.)"
+#endif
+
+QT_BEGIN_MOC_NAMESPACE
+QT_WARNING_PUSH
+QT_WARNING_DISABLE_DEPRECATED
+struct qt_meta_stringdata_Emulator_t {
+    QByteArrayData data[77];
+    char stringdata0[1137];
+};
+#define QT_MOC_LITERAL(idx, ofs, len) \
+    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
+    qptrdiff(offsetof(qt_meta_stringdata_Emulator_t, stringdata0) + ofs \
+        - idx * sizeof(QByteArrayData)) \
+    )
+static const qt_meta_stringdata_Emulator_t qt_meta_stringdata_Emulator = {
+    {
+QT_MOC_LITERAL(0, 0, 8), // "Emulator"
+QT_MOC_LITERAL(1, 9, 8), // "finished"
+QT_MOC_LITERAL(2, 18, 0), // ""
+QT_MOC_LITERAL(3, 19, 20), // "video_flyback_signal"
+QT_MOC_LITERAL(4, 40, 16), // "key_press_signal"
+QT_MOC_LITERAL(5, 57, 9), // "scan_code"
+QT_MOC_LITERAL(6, 67, 18), // "key_release_signal"
+QT_MOC_LITERAL(7, 86, 28), // "modifier_keys_changed_signal"
+QT_MOC_LITERAL(8, 115, 4), // "mask"
+QT_MOC_LITERAL(9, 120, 26), // "modifier_keys_reset_signal"
+QT_MOC_LITERAL(10, 147, 17), // "mouse_move_signal"
+QT_MOC_LITERAL(11, 165, 1), // "x"
+QT_MOC_LITERAL(12, 167, 1), // "y"
+QT_MOC_LITERAL(13, 169, 26), // "mouse_move_relative_signal"
+QT_MOC_LITERAL(14, 196, 2), // "dx"
+QT_MOC_LITERAL(15, 199, 2), // "dy"
+QT_MOC_LITERAL(16, 202, 18), // "mouse_press_signal"
+QT_MOC_LITERAL(17, 221, 7), // "buttons"
+QT_MOC_LITERAL(18, 229, 20), // "mouse_release_signal"
+QT_MOC_LITERAL(19, 250, 12), // "reset_signal"
+QT_MOC_LITERAL(20, 263, 11), // "exit_signal"
+QT_MOC_LITERAL(21, 275, 18), // "load_disc_0_signal"
+QT_MOC_LITERAL(22, 294, 8), // "discname"
+QT_MOC_LITERAL(23, 303, 18), // "load_disc_1_signal"
+QT_MOC_LITERAL(24, 322, 15), // "cpu_idle_signal"
+QT_MOC_LITERAL(25, 338, 21), // "cdrom_disabled_signal"
+QT_MOC_LITERAL(26, 360, 18), // "cdrom_empty_signal"
+QT_MOC_LITERAL(27, 379, 21), // "cdrom_load_iso_signal"
+QT_MOC_LITERAL(28, 401, 18), // "cdrom_ioctl_signal"
+QT_MOC_LITERAL(29, 420, 22), // "cdrom_win_ioctl_signal"
+QT_MOC_LITERAL(30, 443, 12), // "drive_letter"
+QT_MOC_LITERAL(31, 456, 17), // "mouse_hack_signal"
+QT_MOC_LITERAL(32, 474, 22), // "mouse_twobutton_signal"
+QT_MOC_LITERAL(33, 497, 21), // "config_updated_signal"
+QT_MOC_LITERAL(34, 519, 7), // "Config*"
+QT_MOC_LITERAL(35, 527, 10), // "new_config"
+QT_MOC_LITERAL(36, 538, 5), // "Model"
+QT_MOC_LITERAL(37, 544, 9), // "new_model"
+QT_MOC_LITERAL(38, 554, 29), // "network_config_updated_signal"
+QT_MOC_LITERAL(39, 584, 11), // "NetworkType"
+QT_MOC_LITERAL(40, 596, 12), // "network_type"
+QT_MOC_LITERAL(41, 609, 10), // "bridgename"
+QT_MOC_LITERAL(42, 620, 9), // "ipaddress"
+QT_MOC_LITERAL(43, 630, 34), // "show_fullscreen_message_off_s..."
+QT_MOC_LITERAL(44, 665, 19), // "nat_rule_add_signal"
+QT_MOC_LITERAL(45, 685, 15), // "PortForwardRule"
+QT_MOC_LITERAL(46, 701, 4), // "rule"
+QT_MOC_LITERAL(47, 706, 20), // "nat_rule_edit_signal"
+QT_MOC_LITERAL(48, 727, 8), // "old_rule"
+QT_MOC_LITERAL(49, 736, 8), // "new_rule"
+QT_MOC_LITERAL(50, 745, 22), // "nat_rule_remove_signal"
+QT_MOC_LITERAL(51, 768, 11), // "mainemuloop"
+QT_MOC_LITERAL(52, 780, 13), // "video_flyback"
+QT_MOC_LITERAL(53, 794, 9), // "key_press"
+QT_MOC_LITERAL(54, 804, 11), // "key_release"
+QT_MOC_LITERAL(55, 816, 21), // "modifier_keys_changed"
+QT_MOC_LITERAL(56, 838, 19), // "modifier_keys_reset"
+QT_MOC_LITERAL(57, 858, 10), // "mouse_move"
+QT_MOC_LITERAL(58, 869, 19), // "mouse_move_relative"
+QT_MOC_LITERAL(59, 889, 11), // "mouse_press"
+QT_MOC_LITERAL(60, 901, 13), // "mouse_release"
+QT_MOC_LITERAL(61, 915, 5), // "reset"
+QT_MOC_LITERAL(62, 921, 4), // "exit"
+QT_MOC_LITERAL(63, 926, 11), // "load_disc_0"
+QT_MOC_LITERAL(64, 938, 11), // "load_disc_1"
+QT_MOC_LITERAL(65, 950, 8), // "cpu_idle"
+QT_MOC_LITERAL(66, 959, 14), // "cdrom_disabled"
+QT_MOC_LITERAL(67, 974, 11), // "cdrom_empty"
+QT_MOC_LITERAL(68, 986, 14), // "cdrom_load_iso"
+QT_MOC_LITERAL(69, 1001, 10), // "mouse_hack"
+QT_MOC_LITERAL(70, 1012, 15), // "mouse_twobutton"
+QT_MOC_LITERAL(71, 1028, 14), // "config_updated"
+QT_MOC_LITERAL(72, 1043, 22), // "network_config_updated"
+QT_MOC_LITERAL(73, 1066, 27), // "show_fullscreen_message_off"
+QT_MOC_LITERAL(74, 1094, 12), // "nat_rule_add"
+QT_MOC_LITERAL(75, 1107, 13), // "nat_rule_edit"
+QT_MOC_LITERAL(76, 1121, 15) // "nat_rule_remove"
+
+    },
+    "Emulator\0finished\0\0video_flyback_signal\0"
+    "key_press_signal\0scan_code\0"
+    "key_release_signal\0modifier_keys_changed_signal\0"
+    "mask\0modifier_keys_reset_signal\0"
+    "mouse_move_signal\0x\0y\0mouse_move_relative_signal\0"
+    "dx\0dy\0mouse_press_signal\0buttons\0"
+    "mouse_release_signal\0reset_signal\0"
+    "exit_signal\0load_disc_0_signal\0discname\0"
+    "load_disc_1_signal\0cpu_idle_signal\0"
+    "cdrom_disabled_signal\0cdrom_empty_signal\0"
+    "cdrom_load_iso_signal\0cdrom_ioctl_signal\0"
+    "cdrom_win_ioctl_signal\0drive_letter\0"
+    "mouse_hack_signal\0mouse_twobutton_signal\0"
+    "config_updated_signal\0Config*\0new_config\0"
+    "Model\0new_model\0network_config_updated_signal\0"
+    "NetworkType\0network_type\0bridgename\0"
+    "ipaddress\0show_fullscreen_message_off_signal\0"
+    "nat_rule_add_signal\0PortForwardRule\0"
+    "rule\0nat_rule_edit_signal\0old_rule\0"
+    "new_rule\0nat_rule_remove_signal\0"
+    "mainemuloop\0video_flyback\0key_press\0"
+    "key_release\0modifier_keys_changed\0"
+    "modifier_keys_reset\0mouse_move\0"
+    "mouse_move_relative\0mouse_press\0"
+    "mouse_release\0reset\0exit\0load_disc_0\0"
+    "load_disc_1\0cpu_idle\0cdrom_disabled\0"
+    "cdrom_empty\0cdrom_load_iso\0mouse_hack\0"
+    "mouse_twobutton\0config_updated\0"
+    "network_config_updated\0"
+    "show_fullscreen_message_off\0nat_rule_add\0"
+    "nat_rule_edit\0nat_rule_remove"
+};
+#undef QT_MOC_LITERAL
+
+static const uint qt_meta_data_Emulator[] = {
+
+ // content:
+       8,       // revision
+       0,       // classname
+       0,    0, // classinfo
+      54,   14, // methods
+       0,    0, // properties
+       0,    0, // enums/sets
+       0,    0, // constructors
+       0,       // flags
+      28,       // signalCount
+
+ // signals: name, argc, parameters, tag, flags
+       1,    0,  284,    2, 0x06 /* Public */,
+       3,    0,  285,    2, 0x06 /* Public */,
+       4,    1,  286,    2, 0x06 /* Public */,
+       6,    1,  289,    2, 0x06 /* Public */,
+       7,    1,  292,    2, 0x06 /* Public */,
+       9,    0,  295,    2, 0x06 /* Public */,
+      10,    2,  296,    2, 0x06 /* Public */,
+      13,    2,  301,    2, 0x06 /* Public */,
+      16,    1,  306,    2, 0x06 /* Public */,
+      18,    1,  309,    2, 0x06 /* Public */,
+      19,    0,  312,    2, 0x06 /* Public */,
+      20,    0,  313,    2, 0x06 /* Public */,
+      21,    1,  314,    2, 0x06 /* Public */,
+      23,    1,  317,    2, 0x06 /* Public */,
+      24,    0,  320,    2, 0x06 /* Public */,
+      25,    0,  321,    2, 0x06 /* Public */,
+      26,    0,  322,    2, 0x06 /* Public */,
+      27,    1,  323,    2, 0x06 /* Public */,
+      28,    0,  326,    2, 0x06 /* Public */,
+      29,    1,  327,    2, 0x06 /* Public */,
+      31,    0,  330,    2, 0x06 /* Public */,
+      32,    0,  331,    2, 0x06 /* Public */,
+      33,    2,  332,    2, 0x06 /* Public */,
+      38,    3,  337,    2, 0x06 /* Public */,
+      43,    0,  344,    2, 0x06 /* Public */,
+      44,    1,  345,    2, 0x06 /* Public */,
+      47,    2,  348,    2, 0x06 /* Public */,
+      50,    1,  353,    2, 0x06 /* Public */,
+
+ // slots: name, argc, parameters, tag, flags
+      51,    0,  356,    2, 0x0a /* Public */,
+      52,    0,  357,    2, 0x0a /* Public */,
+      53,    1,  358,    2, 0x0a /* Public */,
+      54,    1,  361,    2, 0x0a /* Public */,
+      55,    1,  364,    2, 0x0a /* Public */,
+      56,    0,  367,    2, 0x0a /* Public */,
+      57,    2,  368,    2, 0x0a /* Public */,
+      58,    2,  373,    2, 0x0a /* Public */,
+      59,    1,  378,    2, 0x0a /* Public */,
+      60,    1,  381,    2, 0x0a /* Public */,
+      61,    0,  384,    2, 0x0a /* Public */,
+      62,    0,  385,    2, 0x0a /* Public */,
+      63,    1,  386,    2, 0x0a /* Public */,
+      64,    1,  389,    2, 0x0a /* Public */,
+      65,    0,  392,    2, 0x0a /* Public */,
+      66,    0,  393,    2, 0x0a /* Public */,
+      67,    0,  394,    2, 0x0a /* Public */,
+      68,    1,  395,    2, 0x0a /* Public */,
+      69,    0,  398,    2, 0x0a /* Public */,
+      70,    0,  399,    2, 0x0a /* Public */,
+      71,    2,  400,    2, 0x0a /* Public */,
+      72,    3,  405,    2, 0x0a /* Public */,
+      73,    0,  412,    2, 0x0a /* Public */,
+      74,    1,  413,    2, 0x0a /* Public */,
+      75,    2,  416,    2, 0x0a /* Public */,
+      76,    1,  421,    2, 0x0a /* Public */,
+
+ // signals: parameters
+    QMetaType::Void,
+    QMetaType::Void,
+    QMetaType::Void, QMetaType::UInt,    5,
+    QMetaType::Void, QMetaType::UInt,    5,
+    QMetaType::Void, QMetaType::UInt,    8,
+    QMetaType::Void,
+    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
+    QMetaType::Void, QMetaType::Int, QMetaType::Int,   14,   15,
+    QMetaType::Void, QMetaType::Int,   17,
+    QMetaType::Void, QMetaType::Int,   17,
+    QMetaType::Void,
+    QMetaType::Void,
+    QMetaType::Void, QMetaType::QString,   22,
+    QMetaType::Void, QMetaType::QString,   22,
+    QMetaType::Void,
+    QMetaType::Void,
+    QMetaType::Void,
+    QMetaType::Void, QMetaType::QString,   22,
+    QMetaType::Void,
+    QMetaType::Void, QMetaType::Char,   30,
+    QMetaType::Void,
+    QMetaType::Void,
+    QMetaType::Void, 0x80000000 | 34, 0x80000000 | 36,   35,   37,
+    QMetaType::Void, 0x80000000 | 39, QMetaType::QString, QMetaType::QString,   40,   41,   42,
+    QMetaType::Void,
+    QMetaType::Void, 0x80000000 | 45,   46,
+    QMetaType::Void, 0x80000000 | 45, 0x80000000 | 45,   48,   49,
+    QMetaType::Void, 0x80000000 | 45,   46,
+
+ // slots: parameters
+    QMetaType::Void,
+    QMetaType::Void,
+    QMetaType::Void, QMetaType::UInt,    5,
+    QMetaType::Void, QMetaType::UInt,    5,
+    QMetaType::Void, QMetaType::UInt,    8,
+    QMetaType::Void,
+    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
+    QMetaType::Void, QMetaType::Int, QMetaType::Int,   14,   15,
+    QMetaType::Void, QMetaType::Int,   17,
+    QMetaType::Void, QMetaType::Int,   17,
+    QMetaType::Void,
+    QMetaType::Void,
+    QMetaType::Void, QMetaType::QString,   22,
+    QMetaType::Void, QMetaType::QString,   22,
+    QMetaType::Void,
+    QMetaType::Void,
+    QMetaType::Void,
+    QMetaType::Void, QMetaType::QString,   22,
+    QMetaType::Void,
+    QMetaType::Void,
+    QMetaType::Void, 0x80000000 | 34, 0x80000000 | 36,   35,   37,
+    QMetaType::Void, 0x80000000 | 39, QMetaType::QString, QMetaType::QString,   40,   41,   42,
+    QMetaType::Void,
+    QMetaType::Void, 0x80000000 | 45,   46,
+    QMetaType::Void, 0x80000000 | 45, 0x80000000 | 45,   48,   49,
+    QMetaType::Void, 0x80000000 | 45,   46,
+
+       0        // eod
+};
+
+void Emulator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
+{
+    if (_c == QMetaObject::InvokeMetaMethod) {
+        auto *_t = static_cast<Emulator *>(_o);
+        Q_UNUSED(_t)
+        switch (_id) {
+        case 0: _t->finished(); break;
+        case 1: _t->video_flyback_signal(); break;
+        case 2: _t->key_press_signal((*reinterpret_cast< uint(*)>(_a[1]))); break;
+        case 3: _t->key_release_signal((*reinterpret_cast< uint(*)>(_a[1]))); break;
+        case 4: _t->modifier_keys_changed_signal((*reinterpret_cast< uint(*)>(_a[1]))); break;
+        case 5: _t->modifier_keys_reset_signal(); break;
+        case 6: _t->mouse_move_signal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
+        case 7: _t->mouse_move_relative_signal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
+        case 8: _t->mouse_press_signal((*reinterpret_cast< int(*)>(_a[1]))); break;
+        case 9: _t->mouse_release_signal((*reinterpret_cast< int(*)>(_a[1]))); break;
+        case 10: _t->reset_signal(); break;
+        case 11: _t->exit_signal(); break;
+        case 12: _t->load_disc_0_signal((*reinterpret_cast< QString(*)>(_a[1]))); break;
+        case 13: _t->load_disc_1_signal((*reinterpret_cast< QString(*)>(_a[1]))); break;
+        case 14: _t->cpu_idle_signal(); break;
+        case 15: _t->cdrom_disabled_signal(); break;
+        case 16: _t->cdrom_empty_signal(); break;
+        case 17: _t->cdrom_load_iso_signal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
+        case 18: _t->cdrom_ioctl_signal(); break;
+        case 19: _t->cdrom_win_ioctl_signal((*reinterpret_cast< char(*)>(_a[1]))); break;
+        case 20: _t->mouse_hack_signal(); break;
+        case 21: _t->mouse_twobutton_signal(); break;
+        case 22: _t->config_updated_signal((*reinterpret_cast< Config*(*)>(_a[1])),(*reinterpret_cast< Model(*)>(_a[2]))); break;
+        case 23: _t->network_config_updated_signal((*reinterpret_cast< NetworkType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
+        case 24: _t->show_fullscreen_message_off_signal(); break;
+        case 25: _t->nat_rule_add_signal((*reinterpret_cast< PortForwardRule(*)>(_a[1]))); break;
+        case 26: _t->nat_rule_edit_signal((*reinterpret_cast< PortForwardRule(*)>(_a[1])),(*reinterpret_cast< PortForwardRule(*)>(_a[2]))); break;
+        case 27: _t->nat_rule_remove_signal((*reinterpret_cast< PortForwardRule(*)>(_a[1]))); break;
+        case 28: _t->mainemuloop(); break;
+        case 29: _t->video_flyback(); break;
+        case 30: _t->key_press((*reinterpret_cast< uint(*)>(_a[1]))); break;
+        case 31: _t->key_release((*reinterpret_cast< uint(*)>(_a[1]))); break;
+        case 32: _t->modifier_keys_changed((*reinterpret_cast< uint(*)>(_a[1]))); break;
+        case 33: _t->modifier_keys_reset(); break;
+        case 34: _t->mouse_move((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
+        case 35: _t->mouse_move_relative((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
+        case 36: _t->mouse_press((*reinterpret_cast< int(*)>(_a[1]))); break;
+        case 37: _t->mouse_release((*reinterpret_cast< int(*)>(_a[1]))); break;
+        case 38: _t->reset(); break;
+        case 39: _t->exit(); break;
+        case 40: _t->load_disc_0((*reinterpret_cast< QString(*)>(_a[1]))); break;
+        case 41: _t->load_disc_1((*reinterpret_cast< QString(*)>(_a[1]))); break;
+        case 42: _t->cpu_idle(); break;
+        case 43: _t->cdrom_disabled(); break;
+        case 44: _t->cdrom_empty(); break;
+        case 45: _t->cdrom_load_iso((*reinterpret_cast< QString(*)>(_a[1]))); break;
+        case 46: _t->mouse_hack(); break;
+        case 47: _t->mouse_twobutton(); break;
+        case 48: _t->config_updated((*reinterpret_cast< Config*(*)>(_a[1])),(*reinterpret_cast< Model(*)>(_a[2]))); break;
+        case 49: _t->network_config_updated((*reinterpret_cast< NetworkType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
+        case 50: _t->show_fullscreen_message_off(); break;
+        case 51: _t->nat_rule_add((*reinterpret_cast< PortForwardRule(*)>(_a[1]))); break;
+        case 52: _t->nat_rule_edit((*reinterpret_cast< PortForwardRule(*)>(_a[1])),(*reinterpret_cast< PortForwardRule(*)>(_a[2]))); break;
+        case 53: _t->nat_rule_remove((*reinterpret_cast< PortForwardRule(*)>(_a[1]))); break;
+        default: ;
+        }
+    } else if (_c == QMetaObject::IndexOfMethod) {
+        int *result = reinterpret_cast<int *>(_a[0]);
+        {
+            using _t = void (Emulator::*)();
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::finished)) {
+                *result = 0;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)();
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::video_flyback_signal)) {
+                *result = 1;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)(unsigned  );
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::key_press_signal)) {
+                *result = 2;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)(unsigned  );
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::key_release_signal)) {
+                *result = 3;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)(unsigned  );
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::modifier_keys_changed_signal)) {
+                *result = 4;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)();
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::modifier_keys_reset_signal)) {
+                *result = 5;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)(int , int );
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::mouse_move_signal)) {
+                *result = 6;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)(int , int );
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::mouse_move_relative_signal)) {
+                *result = 7;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)(int );
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::mouse_press_signal)) {
+                *result = 8;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)(int );
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::mouse_release_signal)) {
+                *result = 9;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)();
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::reset_signal)) {
+                *result = 10;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)();
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::exit_signal)) {
+                *result = 11;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)(QString );
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::load_disc_0_signal)) {
+                *result = 12;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)(QString );
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::load_disc_1_signal)) {
+                *result = 13;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)();
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::cpu_idle_signal)) {
+                *result = 14;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)();
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::cdrom_disabled_signal)) {
+                *result = 15;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)();
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::cdrom_empty_signal)) {
+                *result = 16;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)(const QString & );
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::cdrom_load_iso_signal)) {
+                *result = 17;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)();
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::cdrom_ioctl_signal)) {
+                *result = 18;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)(char );
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::cdrom_win_ioctl_signal)) {
+                *result = 19;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)();
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::mouse_hack_signal)) {
+                *result = 20;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)();
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::mouse_twobutton_signal)) {
+                *result = 21;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)(Config * , Model );
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::config_updated_signal)) {
+                *result = 22;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)(NetworkType , QString , QString );
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::network_config_updated_signal)) {
+                *result = 23;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)();
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::show_fullscreen_message_off_signal)) {
+                *result = 24;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)(PortForwardRule );
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::nat_rule_add_signal)) {
+                *result = 25;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)(PortForwardRule , PortForwardRule );
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::nat_rule_edit_signal)) {
+                *result = 26;
+                return;
+            }
+        }
+        {
+            using _t = void (Emulator::*)(PortForwardRule );
+            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Emulator::nat_rule_remove_signal)) {
+                *result = 27;
+                return;
+            }
+        }
+    }
+}
+
+QT_INIT_METAOBJECT const QMetaObject Emulator::staticMetaObject = { {
+    &QObject::staticMetaObject,
+    qt_meta_stringdata_Emulator.data,
+    qt_meta_data_Emulator,
+    qt_static_metacall,
+    nullptr,
+    nullptr
+} };
+
+
+const QMetaObject *Emulator::metaObject() const
+{
+    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
+}
+
+void *Emulator::qt_metacast(const char *_clname)
+{
+    if (!_clname) return nullptr;
+    if (!strcmp(_clname, qt_meta_stringdata_Emulator.stringdata0))
+        return static_cast<void*>(this);
+    return QObject::qt_metacast(_clname);
+}
+
+int Emulator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
+{
+    _id = QObject::qt_metacall(_c, _id, _a);
+    if (_id < 0)
+        return _id;
+    if (_c == QMetaObject::InvokeMetaMethod) {
+        if (_id < 54)
+            qt_static_metacall(this, _c, _id, _a);
+        _id -= 54;
+    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
+        if (_id < 54)
+            *reinterpret_cast<int*>(_a[0]) = -1;
+        _id -= 54;
+    }
+    return _id;
+}
+
+// SIGNAL 0
+void Emulator::finished()
+{
+    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
+}
+
+// SIGNAL 1
+void Emulator::video_flyback_signal()
+{
+    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
+}
+
+// SIGNAL 2
+void Emulator::key_press_signal(unsigned  _t1)
+{
+    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
+    QMetaObject::activate(this, &staticMetaObject, 2, _a);
+}
+
+// SIGNAL 3
+void Emulator::key_release_signal(unsigned  _t1)
+{
+    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
+    QMetaObject::activate(this, &staticMetaObject, 3, _a);
+}
+
+// SIGNAL 4
+void Emulator::modifier_keys_changed_signal(unsigned  _t1)
+{
+    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
+    QMetaObject::activate(this, &staticMetaObject, 4, _a);
+}
+
+// SIGNAL 5
+void Emulator::modifier_keys_reset_signal()
+{
+    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
+}
+
+// SIGNAL 6
+void Emulator::mouse_move_signal(int _t1, int _t2)
+{
+    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
+    QMetaObject::activate(this, &staticMetaObject, 6, _a);
+}
+
+// SIGNAL 7
+void Emulator::mouse_move_relative_signal(int _t1, int _t2)
+{
+    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
+    QMetaObject::activate(this, &staticMetaObject, 7, _a);
+}
+
+// SIGNAL 8
+void Emulator::mouse_press_signal(int _t1)
+{
+    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
+    QMetaObject::activate(this, &staticMetaObject, 8, _a);
+}
+
+// SIGNAL 9
+void Emulator::mouse_release_signal(int _t1)
+{
+    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
+    QMetaObject::activate(this, &staticMetaObject, 9, _a);
+}
+
+// SIGNAL 10
+void Emulator::reset_signal()
+{
+    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
+}
+
+// SIGNAL 11
+void Emulator::exit_signal()
+{
+    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
+}
+
+// SIGNAL 12
+void Emulator::load_disc_0_signal(QString _t1)
+{
+    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
+    QMetaObject::activate(this, &staticMetaObject, 12, _a);
+}
+
+// SIGNAL 13
+void Emulator::load_disc_1_signal(QString _t1)
+{
+    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
+    QMetaObject::activate(this, &staticMetaObject, 13, _a);
+}
+
+// SIGNAL 14
+void Emulator::cpu_idle_signal()
+{
+    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
+}
+
+// SIGNAL 15
+void Emulator::cdrom_disabled_signal()
+{
+    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
+}
+
+// SIGNAL 16
+void Emulator::cdrom_empty_signal()
+{
+    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
+}
+
+// SIGNAL 17
+void Emulator::cdrom_load_iso_signal(const QString & _t1)
+{
+    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
+    QMetaObject::activate(this, &staticMetaObject, 17, _a);
+}
+
+// SIGNAL 18
+void Emulator::cdrom_ioctl_signal()
+{
+    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
+}
+
+// SIGNAL 19
+void Emulator::cdrom_win_ioctl_signal(char _t1)
+{
+    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
+    QMetaObject::activate(this, &staticMetaObject, 19, _a);
+}
+
+// SIGNAL 20
+void Emulator::mouse_hack_signal()
+{
+    QMetaObject::activate(this, &staticMetaObject, 20, nullptr);
+}
+
+// SIGNAL 21
+void Emulator::mouse_twobutton_signal()
+{
+    QMetaObject::activate(this, &staticMetaObject, 21, nullptr);
+}
+
+// SIGNAL 22
+void Emulator::config_updated_signal(Config * _t1, Model _t2)
+{
+    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
+    QMetaObject::activate(this, &staticMetaObject, 22, _a);
+}
+
+// SIGNAL 23
+void Emulator::network_config_updated_signal(NetworkType _t1, QString _t2, QString _t3)
+{
+    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
+    QMetaObject::activate(this, &staticMetaObject, 23, _a);
+}
+
+// SIGNAL 24
+void Emulator::show_fullscreen_message_off_signal()
+{
+    QMetaObject::activate(this, &staticMetaObject, 24, nullptr);
+}
+
+// SIGNAL 25
+void Emulator::nat_rule_add_signal(PortForwardRule _t1)
+{
+    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
+    QMetaObject::activate(this, &staticMetaObject, 25, _a);
+}
+
+// SIGNAL 26
+void Emulator::nat_rule_edit_signal(PortForwardRule _t1, PortForwardRule _t2)
+{
+    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
+    QMetaObject::activate(this, &staticMetaObject, 26, _a);
+}
+
+// SIGNAL 27
+void Emulator::nat_rule_remove_signal(PortForwardRule _t1)
+{
+    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
+    QMetaObject::activate(this, &staticMetaObject, 27, _a);
+}
+QT_WARNING_POP
+QT_END_MOC_NAMESPACE
