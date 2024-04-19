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
    "refrenceOpened",
    "timerTimeout",
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
    "showEntireMessage",
    "showCurrentStreak",
    "streak",
    "moveCaptain",
    "yPos",
    "startNewGame",
    "receiveFullMessage"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[46];
    char stringdata0[11];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[15];
    char stringdata5[13];
    char stringdata6[20];
    char stringdata7[13];
    char stringdata8[14];
    char stringdata9[17];
    char stringdata10[12];
    char stringdata11[2];
    char stringdata12[14];
    char stringdata13[14];
    char stringdata14[16];
    char stringdata15[18];
    char stringdata16[18];
    char stringdata17[18];
    char stringdata18[7];
    char stringdata19[12];
    char stringdata20[5];
    char stringdata21[13];
    char stringdata22[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 15),  // "submitTextInput"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 4),  // "text"
        QT_MOC_LITERAL(33, 14),  // "refrenceOpened"
        QT_MOC_LITERAL(48, 12),  // "timerTimeout"
        QT_MOC_LITERAL(61, 19),  // "textEditingComplete"
        QT_MOC_LITERAL(81, 12),  // "playDotSound"
        QT_MOC_LITERAL(94, 13),  // "playDashSound"
        QT_MOC_LITERAL(108, 16),  // "recieveMorseChar"
        QT_MOC_LITERAL(125, 11),  // "std::string"
        QT_MOC_LITERAL(137, 1),  // "s"
        QT_MOC_LITERAL(139, 13),  // "clearMorseBox"
        QT_MOC_LITERAL(153, 13),  // "toggleCaptain"
        QT_MOC_LITERAL(167, 15),  // "showCaptainText"
        QT_MOC_LITERAL(183, 17),  // "showRefrenceSheet"
        QT_MOC_LITERAL(201, 17),  // "showEntireMessage"
        QT_MOC_LITERAL(219, 17),  // "showCurrentStreak"
        QT_MOC_LITERAL(237, 6),  // "streak"
        QT_MOC_LITERAL(244, 11),  // "moveCaptain"
        QT_MOC_LITERAL(256, 4),  // "yPos"
        QT_MOC_LITERAL(261, 12),  // "startNewGame"
        QT_MOC_LITERAL(274, 18)   // "receiveFullMessage"
    },
    "MainWindow",
    "submitTextInput",
    "",
    "text",
    "refrenceOpened",
    "timerTimeout",
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
    "showEntireMessage",
    "showCurrentStreak",
    "streak",
    "moveCaptain",
    "yPos",
    "startNewGame",
    "receiveFullMessage"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  110,    2, 0x06,    1 /* Public */,
       4,    0,  113,    2, 0x06,    3 /* Public */,
       5,    0,  114,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,  115,    2, 0x0a,    5 /* Public */,
       7,    0,  116,    2, 0x0a,    6 /* Public */,
       8,    0,  117,    2, 0x0a,    7 /* Public */,
       9,    1,  118,    2, 0x0a,    8 /* Public */,
      12,    0,  121,    2, 0x0a,   10 /* Public */,
      13,    0,  122,    2, 0x0a,   11 /* Public */,
      14,    1,  123,    2, 0x0a,   12 /* Public */,
      15,    0,  126,    2, 0x0a,   14 /* Public */,
      16,    0,  127,    2, 0x0a,   15 /* Public */,
      17,    1,  128,    2, 0x0a,   16 /* Public */,
      19,    1,  131,    2, 0x0a,   18 /* Public */,
      21,    0,  134,    2, 0x0a,   20 /* Public */,
      22,    1,  135,    2, 0x0a,   21 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,

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
        // method 'refrenceOpened'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'timerTimeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
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
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showCurrentStreak'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'moveCaptain'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'startNewGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'receiveFullMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>
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
        case 1: _t->refrenceOpened(); break;
        case 2: _t->timerTimeout(); break;
        case 3: _t->textEditingComplete(); break;
        case 4: _t->playDotSound(); break;
        case 5: _t->playDashSound(); break;
        case 6: _t->recieveMorseChar((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 7: _t->clearMorseBox(); break;
        case 8: _t->toggleCaptain(); break;
        case 9: _t->showCaptainText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->showRefrenceSheet(); break;
        case 11: _t->showEntireMessage(); break;
        case 12: _t->showCurrentStreak((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->moveCaptain((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->startNewGame(); break;
        case 15: _t->receiveFullMessage((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
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
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::refrenceOpened; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::timerTimeout; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::submitTextInput(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::refrenceOpened()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::timerTimeout()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
