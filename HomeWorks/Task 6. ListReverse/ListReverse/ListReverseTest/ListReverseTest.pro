include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

INCLUDEPATH += ../ListReverse

HEADERS += \
        ../ListReverse/node.h \
        ../ListReverse/list.h \
        nodeTests.h \
        listTests.h

SOURCES += \
        ../ListReverse/node.cpp \
        ../ListReverse/list.cpp \
        main.cpp
