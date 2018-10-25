include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        tst_sortingtest.h \
    sorting_module.h

SOURCES += \
        main.cpp \
    sorting_module.cpp
