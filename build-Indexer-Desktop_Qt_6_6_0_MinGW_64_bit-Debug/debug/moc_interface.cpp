/****************************************************************************
** Meta object code from reading C++ file 'interface.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../IndexerResult v1/interface.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
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
struct qt_meta_stringdata_CLASSInterfaceENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSInterfaceENDCLASS = QtMocHelpers::stringData(
    "Interface",
    "on_StartIndexingButton_clicked",
    "",
    "on_PauseIndexingButton_clicked",
    "on_StopIndexingButton_clicked",
    "on_SearchButton_clicked",
    "on_ClearResult_clicked",
    "on_ExitButton_clicked",
    "on_ResumeIndexingButton_clicked",
    "handleSearchResults",
    "std::vector<std::string>",
    "results"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSInterfaceENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[10];
    char stringdata1[31];
    char stringdata2[1];
    char stringdata3[31];
    char stringdata4[30];
    char stringdata5[24];
    char stringdata6[23];
    char stringdata7[22];
    char stringdata8[32];
    char stringdata9[20];
    char stringdata10[25];
    char stringdata11[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSInterfaceENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSInterfaceENDCLASS_t qt_meta_stringdata_CLASSInterfaceENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "Interface"
        QT_MOC_LITERAL(10, 30),  // "on_StartIndexingButton_clicked"
        QT_MOC_LITERAL(41, 0),  // ""
        QT_MOC_LITERAL(42, 30),  // "on_PauseIndexingButton_clicked"
        QT_MOC_LITERAL(73, 29),  // "on_StopIndexingButton_clicked"
        QT_MOC_LITERAL(103, 23),  // "on_SearchButton_clicked"
        QT_MOC_LITERAL(127, 22),  // "on_ClearResult_clicked"
        QT_MOC_LITERAL(150, 21),  // "on_ExitButton_clicked"
        QT_MOC_LITERAL(172, 31),  // "on_ResumeIndexingButton_clicked"
        QT_MOC_LITERAL(204, 19),  // "handleSearchResults"
        QT_MOC_LITERAL(224, 24),  // "std::vector<std::string>"
        QT_MOC_LITERAL(249, 7)   // "results"
    },
    "Interface",
    "on_StartIndexingButton_clicked",
    "",
    "on_PauseIndexingButton_clicked",
    "on_StopIndexingButton_clicked",
    "on_SearchButton_clicked",
    "on_ClearResult_clicked",
    "on_ExitButton_clicked",
    "on_ResumeIndexingButton_clicked",
    "handleSearchResults",
    "std::vector<std::string>",
    "results"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSInterfaceENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x08,    1 /* Private */,
       3,    0,   63,    2, 0x08,    2 /* Private */,
       4,    0,   64,    2, 0x08,    3 /* Private */,
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    0,   66,    2, 0x08,    5 /* Private */,
       7,    0,   67,    2, 0x08,    6 /* Private */,
       8,    0,   68,    2, 0x08,    7 /* Private */,
       9,    1,   69,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

Q_CONSTINIT const QMetaObject Interface::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSInterfaceENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSInterfaceENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSInterfaceENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Interface, std::true_type>,
        // method 'on_StartIndexingButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_PauseIndexingButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_StopIndexingButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SearchButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ClearResult_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ExitButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ResumeIndexingButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleSearchResults'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<std::string> &, std::false_type>
    >,
    nullptr
} };

void Interface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Interface *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_StartIndexingButton_clicked(); break;
        case 1: _t->on_PauseIndexingButton_clicked(); break;
        case 2: _t->on_StopIndexingButton_clicked(); break;
        case 3: _t->on_SearchButton_clicked(); break;
        case 4: _t->on_ClearResult_clicked(); break;
        case 5: _t->on_ExitButton_clicked(); break;
        case 6: _t->on_ResumeIndexingButton_clicked(); break;
        case 7: _t->handleSearchResults((*reinterpret_cast< std::add_pointer_t<std::vector<std::string>>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *Interface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Interface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSInterfaceENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Interface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
