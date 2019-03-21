include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

INCLUDEPATH += ../ListOfNames

HEADERS += \
        ../ListOfNames/Element.h\
        ../ListOfNames/List.h\
        list_of_names_tests.h

SOURCES += \
        ../ListOfNames/Element.cpp\
        ../ListOfNames/List.cpp\
        main.cpp
