include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        tst_dd.h \
    polindrom.h

SOURCES += \
        main.cpp \
    polindrom.cpp
