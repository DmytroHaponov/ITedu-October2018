include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

INCLUDEPATH += ../HasVectorOdd

HEADERS += \
        ../HasVectorOdd/vector_functions.h\
        vector_functions_test.h

SOURCES += \
        ../HasVectorOdd/vector_functions.cpp\
        main.cpp
