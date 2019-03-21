include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

INCLUDEPATH += ../Palindrom

HEADERS += \
    palindrom_tests.h \
    ../Palindrom/functions.h

SOURCES += \
        main.cpp \
	../Palindrom/functions.cpp
