include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        tst_testcase.h \
    h8.h

SOURCES += \
        main.cpp \
    h8.cpp
