/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MorseCodeGame/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "submitTextInput",
    "",
    "text",
    "textEditingComplete",
    "playDotSound",
    "playDashSound",
    "recieveMorseChar",
    "std::string",
    "s",
    "clearMorseBox",
    "toggleCaptain",
    "showCaptainText",
    "showRefrenceSheet",
    "showEntireMessage"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[30];
    char stringdata0[11];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[20];
    char stringdata5[13];
    char stringdata6[14];
    char stringdata7[17];
    char stringdata8[12];
    char stringdata9[2];
    char stringdata10[14];
    char stringdata11[14];
    char stringdata12[16];
    char stringdata13[18];
    char stringdata14[18];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 15),  // "submitTextInput"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 4),  // "text"
        QT_MOC_LITERAL(33, 19),  // "textEditingComplete"
        QT_MOC_LITERAL(53, 12),  // "playDotSound"
        QT_MOC_LITERAL(66, 13),  // "playDashSound"
        QT_MOC_LITERAL(80, 16),  // "recieveMorseChar"
        QT_MOC_LITERAL(97, 11),  // "std::string"
        QT_MOC_LITERAL(109, 1),  // "s"
        QT_MOC_LITERAL(111, 13),  // "clearMorseBox"
        QT_MOC_LITERAL(125, 13),  // "toggleCaptain"
        QT_MOC_LITERAL(139, 15),  // "showCaptainText"
        QT_MOC_LITERAL(155, 17),  // "showRefrenceSheet"
        QT_MOC_LITERAL(173, 17)   // "showEntireMessage"
    },
    "MainWindow",
    "submitTextInput",
    "",
    "text",
    "textEditingComplete",
    "playDotSound",
    "playDashSound",
    "recieveMorseChar",
    "std::string",
    "s",
    "clearMorseBox",
    "toggleCaptain",
    "showCaptainText",
    "showRefrenceSheet",
    "showEntireMessage"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   77,    2, 0x0a,    3 /* Public */,
       5,    0,   78,    2, 0x0a,    4 /* Public */,
       6,    0,   79,    2, 0x0a,    5 /* Public */,
       7,    1,   80,    2, 0x0a,    6 /* Public */,
      10,    0,   83,    2, 0x0a,    8 /* Public */,
      11,    0,   84,    2, 0x0a,    9 /* Public */,
      12,    1,   85,    2, 0x0a,   10 /* Public */,
      13,    0,   88,    2, 0x0a,   12 /* Public */,
      14,    0,   89,    2, 0x0a,   13 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'submitTextInput'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'textEditingComplete'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'playDotSound'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'playDashSound'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'recieveMorseChar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'clearMorseBox'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'toggleCaptain'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showCaptainText'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'showRefrenceSheet'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showEntireMessage'
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
        case 0: _t->submitTextInput((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->textEditingComplete(); break;
        case 2: _t->playDotSound(); break;
        case 3: _t->playDashSound(); break;
        case 4: _t->recieveMorseChar((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 5: _t->clearMorseBox(); break;
        case 6: _t->toggleCaptain(); break;
        case 7: _t->showCaptainText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->showRefrenceSheet(); break;
        case 9: _t->showEntireMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QString );
            if (_t _q_method = &MainWindow::submitTextInput; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
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
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::submitTextInput(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
