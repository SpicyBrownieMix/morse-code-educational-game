/****************************************************************************
** Meta object code from reading C++ file 'model.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MorseCodeGame/model.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'model.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSModelENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSModelENDCLASS = QtMocHelpers::stringData(
    "Model",
    "sendMorseChar",
    "",
    "std::string",
    "s",
    "playDotSound",
    "playDashSound",
    "clearMorseBox",
    "toggleCaptain",
    "sendCaptainText",
    "text",
    "updateStreak",
    "streak",
    "textInputEntered",
    "resetStreak",
    "startNewGame"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSModelENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[6];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[2];
    char stringdata5[13];
    char stringdata6[14];
    char stringdata7[14];
    char stringdata8[14];
    char stringdata9[16];
    char stringdata10[5];
    char stringdata11[13];
    char stringdata12[7];
    char stringdata13[17];
    char stringdata14[12];
    char stringdata15[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSModelENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSModelENDCLASS_t qt_meta_stringdata_CLASSModelENDCLASS = {
    {
        QT_MOC_LITERAL(0, 5),  // "Model"
        QT_MOC_LITERAL(6, 13),  // "sendMorseChar"
        QT_MOC_LITERAL(20, 0),  // ""
        QT_MOC_LITERAL(21, 11),  // "std::string"
        QT_MOC_LITERAL(33, 1),  // "s"
        QT_MOC_LITERAL(35, 12),  // "playDotSound"
        QT_MOC_LITERAL(48, 13),  // "playDashSound"
        QT_MOC_LITERAL(62, 13),  // "clearMorseBox"
        QT_MOC_LITERAL(76, 13),  // "toggleCaptain"
        QT_MOC_LITERAL(90, 15),  // "sendCaptainText"
        QT_MOC_LITERAL(106, 4),  // "text"
        QT_MOC_LITERAL(111, 12),  // "updateStreak"
        QT_MOC_LITERAL(124, 6),  // "streak"
        QT_MOC_LITERAL(131, 16),  // "textInputEntered"
        QT_MOC_LITERAL(148, 11),  // "resetStreak"
        QT_MOC_LITERAL(160, 12)   // "startNewGame"
    },
    "Model",
    "sendMorseChar",
    "",
    "std::string",
    "s",
    "playDotSound",
    "playDashSound",
    "clearMorseBox",
    "toggleCaptain",
    "sendCaptainText",
    "text",
    "updateStreak",
    "streak",
    "textInputEntered",
    "resetStreak",
    "startNewGame"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSModelENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x06,    1 /* Public */,
       5,    0,   77,    2, 0x06,    3 /* Public */,
       6,    0,   78,    2, 0x06,    4 /* Public */,
       7,    0,   79,    2, 0x06,    5 /* Public */,
       8,    0,   80,    2, 0x06,    6 /* Public */,
       9,    1,   81,    2, 0x06,    7 /* Public */,
      11,    1,   84,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      13,    1,   87,    2, 0x0a,   11 /* Public */,
      14,    0,   90,    2, 0x0a,   13 /* Public */,
      15,    0,   91,    2, 0x0a,   14 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Int,   12,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Model::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSModelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSModelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSModelENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Model, std::true_type>,
        // method 'sendMorseChar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'playDotSound'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'playDashSound'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearMorseBox'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'toggleCaptain'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendCaptainText'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'updateStreak'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'textInputEntered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'resetStreak'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'startNewGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Model::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Model *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendMorseChar((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 1: _t->playDotSound(); break;
        case 2: _t->playDashSound(); break;
        case 3: _t->clearMorseBox(); break;
        case 4: _t->toggleCaptain(); break;
        case 5: _t->sendCaptainText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->updateStreak((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->textInputEntered((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->resetStreak(); break;
        case 9: _t->startNewGame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Model::*)(std::string );
            if (_t _q_method = &Model::sendMorseChar; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Model::*)();
            if (_t _q_method = &Model::playDotSound; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Model::*)();
            if (_t _q_method = &Model::playDashSound; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Model::*)();
            if (_t _q_method = &Model::clearMorseBox; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Model::*)();
            if (_t _q_method = &Model::toggleCaptain; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Model::*)(QString );
            if (_t _q_method = &Model::sendCaptainText; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Model::*)(int );
            if (_t _q_method = &Model::updateStreak; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject *Model::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Model::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSModelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Model::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Model::sendMorseChar(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Model::playDotSound()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Model::playDashSound()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Model::clearMorseBox()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Model::toggleCaptain()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Model::sendCaptainText(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Model::updateStreak(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
