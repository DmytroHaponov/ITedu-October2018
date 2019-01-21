include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        tst_testsort.h \
    functor_sort.h

SOURCES += \
        main.cpp \
    functor_sort.cpp
