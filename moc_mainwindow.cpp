/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon Apr 5 16:06:08 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      33,   11,   11,   11, 0x08,
      67,   11,   11,   11, 0x08,
      93,   11,   11,   11, 0x08,
     119,   11,   11,   11, 0x08,
     148,   11,   11,   11, 0x08,
     188,   11,   11,   11, 0x08,
     217,   11,   11,   11, 0x08,
     250,  243,   11,   11, 0x08,
     310,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_btnLink_clicked()\0"
    "on_ScanWirelessAction_triggered()\0"
    "on_QuitAction_triggered()\0"
    "on_HideAction_triggered()\0"
    "on_VersionAction_triggered()\0"
    "on_RestartNetworkCardAction_triggered()\0"
    "on_RefreshAction_triggered()\0"
    "on_SaveAction_triggered()\0reason\0"
    "trayIconAction_triggered(QSystemTrayIcon::ActivationReason)\0"
    "trayIconTimerAction_triggered()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btnLink_clicked(); break;
        case 1: on_ScanWirelessAction_triggered(); break;
        case 2: on_QuitAction_triggered(); break;
        case 3: on_HideAction_triggered(); break;
        case 4: on_VersionAction_triggered(); break;
        case 5: on_RestartNetworkCardAction_triggered(); break;
        case 6: on_RefreshAction_triggered(); break;
        case 7: on_SaveAction_triggered(); break;
        case 8: trayIconAction_triggered((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 9: trayIconTimerAction_triggered(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
