--- /dev/null	2021-11-02 20:38:02.000000000 +0000
+++ src/qt5/moc_network_dialog.cpp	2021-10-31 18:47:01.000000000 +0000
@@ -0,0 +1,127 @@
+/****************************************************************************
+** Meta object code from reading C++ file 'network_dialog.h'
+**
+** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
+**
+** WARNING! All changes made in this file will be lost!
+*****************************************************************************/
+
+#include "network_dialog.h"
+#include <QtCore/qbytearray.h>
+#include <QtCore/qmetatype.h>
+#if !defined(Q_MOC_OUTPUT_REVISION)
+#error "The header file 'network_dialog.h' doesn't include <QObject>."
+#elif Q_MOC_OUTPUT_REVISION != 67
+#error "This file was generated using the moc from 5.12.11. It"
+#error "cannot be used with the include files from this version of Qt."
+#error "(The moc has changed too much.)"
+#endif
+
+QT_BEGIN_MOC_NAMESPACE
+QT_WARNING_PUSH
+QT_WARNING_DISABLE_DEPRECATED
+struct qt_meta_stringdata_NetworkDialog_t {
+    QByteArrayData data[5];
+    char stringdata0[61];
+};
+#define QT_MOC_LITERAL(idx, ofs, len) \
+    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
+    qptrdiff(offsetof(qt_meta_stringdata_NetworkDialog_t, stringdata0) + ofs \
+        - idx * sizeof(QByteArrayData)) \
+    )
+static const qt_meta_stringdata_NetworkDialog_t qt_meta_stringdata_NetworkDialog = {
+    {
+QT_MOC_LITERAL(0, 0, 13), // "NetworkDialog"
+QT_MOC_LITERAL(1, 14, 13), // "radio_clicked"
+QT_MOC_LITERAL(2, 28, 0), // ""
+QT_MOC_LITERAL(3, 29, 15), // "dialog_accepted"
+QT_MOC_LITERAL(4, 45, 15) // "dialog_rejected"
+
+    },
+    "NetworkDialog\0radio_clicked\0\0"
+    "dialog_accepted\0dialog_rejected"
+};
+#undef QT_MOC_LITERAL
+
+static const uint qt_meta_data_NetworkDialog[] = {
+
+ // content:
+       8,       // revision
+       0,       // classname
+       0,    0, // classinfo
+       3,   14, // methods
+       0,    0, // properties
+       0,    0, // enums/sets
+       0,    0, // constructors
+       0,       // flags
+       0,       // signalCount
+
+ // slots: name, argc, parameters, tag, flags
+       1,    0,   29,    2, 0x08 /* Private */,
+       3,    0,   30,    2, 0x08 /* Private */,
+       4,    0,   31,    2, 0x08 /* Private */,
+
+ // slots: parameters
+    QMetaType::Void,
+    QMetaType::Void,
+    QMetaType::Void,
+
+       0        // eod
+};
+
+void NetworkDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
+{
+    if (_c == QMetaObject::InvokeMetaMethod) {
+        auto *_t = static_cast<NetworkDialog *>(_o);
+        Q_UNUSED(_t)
+        switch (_id) {
+        case 0: _t->radio_clicked(); break;
+        case 1: _t->dialog_accepted(); break;
+        case 2: _t->dialog_rejected(); break;
+        default: ;
+        }
+    }
+    Q_UNUSED(_a);
+}
+
+QT_INIT_METAOBJECT const QMetaObject NetworkDialog::staticMetaObject = { {
+    &QDialog::staticMetaObject,
+    qt_meta_stringdata_NetworkDialog.data,
+    qt_meta_data_NetworkDialog,
+    qt_static_metacall,
+    nullptr,
+    nullptr
+} };
+
+
+const QMetaObject *NetworkDialog::metaObject() const
+{
+    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
+}
+
+void *NetworkDialog::qt_metacast(const char *_clname)
+{
+    if (!_clname) return nullptr;
+    if (!strcmp(_clname, qt_meta_stringdata_NetworkDialog.stringdata0))
+        return static_cast<void*>(this);
+    return QDialog::qt_metacast(_clname);
+}
+
+int NetworkDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
+{
+    _id = QDialog::qt_metacall(_c, _id, _a);
+    if (_id < 0)
+        return _id;
+    if (_c == QMetaObject::InvokeMetaMethod) {
+        if (_id < 3)
+            qt_static_metacall(this, _c, _id, _a);
+        _id -= 3;
+    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
+        if (_id < 3)
+            *reinterpret_cast<int*>(_a[0]) = -1;
+        _id -= 3;
+    }
+    return _id;
+}
+QT_WARNING_POP
+QT_END_MOC_NAMESPACE
