/****************************************************************************
** Meta object code from reading C++ file 'GxMainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gxbdev/GxMainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GxMainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GxMainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      32,   13,   13,   13, 0x08,
      66,   13,   13,   13, 0x08,
     105,   99,   13,   13, 0x08,
     144,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GxMainWindow[] = {
    "GxMainWindow\0\0on_exec_pressed()\0"
    "on_actionAdd_New_Item_triggered()\0"
    "on_actionNew_Project_triggered()\0index\0"
    "on_projtree_doubleClicked(QModelIndex)\0"
    "on_actionAbout_triggered()\0"
};

void GxMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GxMainWindow *_t = static_cast<GxMainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_exec_pressed(); break;
        case 1: _t->on_actionAdd_New_Item_triggered(); break;
        case 2: _t->on_actionNew_Project_triggered(); break;
        case 3: _t->on_projtree_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->on_actionAbout_triggered(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GxMainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GxMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GxMainWindow,
      qt_meta_data_GxMainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GxMainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GxMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GxMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GxMainWindow))
        return static_cast<void*>(const_cast< GxMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int GxMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
