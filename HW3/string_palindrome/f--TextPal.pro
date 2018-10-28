include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        tst_test_pal.h \
    is_palindrome.h

SOURCES += \
        main.cpp \
    is_palindrome.cpp
