--- /dev/null	2021-11-02 20:38:02.000000000 +0000
+++ src/qt5/moc_nat_list_dialog.cpp	2021-10-31 18:47:00.000000000 +0000
@@ -0,0 +1,132 @@
+/****************************************************************************
+** Meta object code from reading C++ file 'nat_list_dialog.h'
+**
+** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
+**
+** WARNING! All changes made in this file will be lost!
+*****************************************************************************/
+
+#include "nat_list_dialog.h"
+#include <QtCore/qbytearray.h>
+#include <QtCore/qmetatype.h>
+#if !defined(Q_MOC_OUTPUT_REVISION)
+#error "The header file 'nat_list_dialog.h' doesn't include <QObject>."
+#elif Q_MOC_OUTPUT_REVISION != 67
+#error "This file was generated using the moc from 5.12.11. It"
+#error "cannot be used with the include files from this version of Qt."
+#error "(The moc has changed too much.)"
+#endif
+
+QT_BEGIN_MOC_NAMESPACE
+QT_WARNING_PUSH
+QT_WARNING_DISABLE_DEPRECATED
+struct qt_meta_stringdata_NatListDialog_t {
+    QByteArrayData data[6];
+    char stringdata0[89];
+};
+#define QT_MOC_LITERAL(idx, ofs, len) \
+    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
+    qptrdiff(offsetof(qt_meta_stringdata_NatListDialog_t, stringdata0) + ofs \
+        - idx * sizeof(QByteArrayData)) \
+    )
+static const qt_meta_stringdata_NatListDialog_t qt_meta_stringdata_NatListDialog = {
+    {
+QT_MOC_LITERAL(0, 0, 13), // "NatListDialog"
+QT_MOC_LITERAL(1, 14, 15), // "dialog_accepted"
+QT_MOC_LITERAL(2, 30, 0), // ""
+QT_MOC_LITERAL(3, 31, 15), // "dialog_rejected"
+QT_MOC_LITERAL(4, 47, 21), // "delete_button_clicked"
+QT_MOC_LITERAL(5, 69, 19) // "edit_button_clicked"
+
+    },
+    "NatListDialog\0dialog_accepted\0\0"
+    "dialog_rejected\0delete_button_clicked\0"
+    "edit_button_clicked"
+};
+#undef QT_MOC_LITERAL
+
+static const uint qt_meta_data_NatListDialog[] = {
+
+ // content:
+       8,       // revision
+       0,       // classname
+       0,    0, // classinfo
+       4,   14, // methods
+       0,    0, // properties
+       0,    0, // enums/sets
+       0,    0, // constructors
+       0,       // flags
+       0,       // signalCount
+
+ // slots: name, argc, parameters, tag, flags
+       1,    0,   34,    2, 0x08 /* Private */,
+       3,    0,   35,    2, 0x08 /* Private */,
+       4,    0,   36,    2, 0x08 /* Private */,
+       5,    0,   37,    2, 0x08 /* Private */,
+
+ // slots: parameters
+    QMetaType::Void,
+    QMetaType::Void,
+    QMetaType::Void,
+    QMetaType::Void,
+
+       0        // eod
+};
+
+void NatListDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
+{
+    if (_c == QMetaObject::InvokeMetaMethod) {
+        auto *_t = static_cast<NatListDialog *>(_o);
+        Q_UNUSED(_t)
+        switch (_id) {
+        case 0: _t->dialog_accepted(); break;
+        case 1: _t->dialog_rejected(); break;
+        case 2: _t->delete_button_clicked(); break;
+        case 3: _t->edit_button_clicked(); break;
+        default: ;
+        }
+    }
+    Q_UNUSED(_a);
+}
+
+QT_INIT_METAOBJECT const QMetaObject NatListDialog::staticMetaObject = { {
+    &QDialog::staticMetaObject,
+    qt_meta_stringdata_NatListDialog.data,
+    qt_meta_data_NatListDialog,
+    qt_static_metacall,
+    nullptr,
+    nullptr
+} };
+
+
+const QMetaObject *NatListDialog::metaObject() const
+{
+    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
+}
+
+void *NatListDialog::qt_metacast(const char *_clname)
+{
+    if (!_clname) return nullptr;
+    if (!strcmp(_clname, qt_meta_stringdata_NatListDialog.stringdata0))
+        return static_cast<void*>(this);
+    return QDialog::qt_metacast(_clname);
+}
+
+int NatListDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
+{
+    _id = QDialog::qt_metacall(_c, _id, _a);
+    if (_id < 0)
+        return _id;
+    if (_c == QMetaObject::InvokeMetaMethod) {
+        if (_id < 4)
+            qt_static_metacall(this, _c, _id, _a);
+        _id -= 4;
+    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
+        if (_id < 4)
+            *reinterpret_cast<int*>(_a[0]) = -1;
+        _id -= 4;
+    }
+    return _id;
+}
+QT_WARNING_POP
+QT_END_MOC_NAMESPACE
