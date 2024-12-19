/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../mainwindow.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[28];
    char stringdata0[11];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[7];
    char stringdata5[14];
    char stringdata6[17];
    char stringdata7[22];
    char stringdata8[19];
    char stringdata9[18];
    char stringdata10[20];
    char stringdata11[32];
    char stringdata12[14];
    char stringdata13[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 17),  // "showPacketDetails"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 3),  // "row"
        QT_MOC_LITERAL(34, 6),  // "column"
        QT_MOC_LITERAL(41, 13),  // "filterPackets"
        QT_MOC_LITERAL(55, 16),  // "filterBySourceIP"
        QT_MOC_LITERAL(72, 21),  // "filterByDestinationIP"
        QT_MOC_LITERAL(94, 18),  // "filterBySourcePort"
        QT_MOC_LITERAL(113, 17),  // "stopPacketCapture"
        QT_MOC_LITERAL(131, 19),  // "resumePacketCapture"
        QT_MOC_LITERAL(151, 31),  // "startPacketCaptureFromInterface"
        QT_MOC_LITERAL(183, 13),  // "interfaceName"
        QT_MOC_LITERAL(197, 21)   // "loadNetworkInterfaces"
    },
    "MainWindow",
    "showPacketDetails",
    "",
    "row",
    "column",
    "filterPackets",
    "filterBySourceIP",
    "filterByDestinationIP",
    "filterBySourcePort",
    "stopPacketCapture",
    "resumePacketCapture",
    "startPacketCaptureFromInterface",
    "interfaceName",
    "loadNetworkInterfaces"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   68,    2, 0x08,    1 /* Private */,
       5,    0,   73,    2, 0x08,    4 /* Private */,
       6,    0,   74,    2, 0x08,    5 /* Private */,
       7,    0,   75,    2, 0x08,    6 /* Private */,
       8,    0,   76,    2, 0x08,    7 /* Private */,
       9,    0,   77,    2, 0x08,    8 /* Private */,
      10,    0,   78,    2, 0x08,    9 /* Private */,
      11,    1,   79,    2, 0x08,   10 /* Private */,
      13,    0,   82,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'showPacketDetails'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'filterPackets'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'filterBySourceIP'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'filterByDestinationIP'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'filterBySourcePort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stopPacketCapture'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resumePacketCapture'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'startPacketCaptureFromInterface'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'loadNetworkInterfaces'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showPacketDetails((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->filterPackets(); break;
        case 2: _t->filterBySourceIP(); break;
        case 3: _t->filterByDestinationIP(); break;
        case 4: _t->filterBySourcePort(); break;
        case 5: _t->stopPacketCapture(); break;
        case 6: _t->resumePacketCapture(); break;
        case 7: _t->startPacketCaptureFromInterface((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->loadNetworkInterfaces(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
