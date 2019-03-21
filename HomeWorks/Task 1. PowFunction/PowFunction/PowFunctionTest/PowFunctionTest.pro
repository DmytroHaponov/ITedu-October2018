include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

INCLUDEPATH += ../PowFunction

HEADERS += \
    ../PowFunction/functions.h\
    pow_function_tests.h

SOURCES += \
        ../PowFunction/functions.cpp\
        main.cpp
