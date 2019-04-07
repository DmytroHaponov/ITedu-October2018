#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWidgets>
#include "BufferNames.h"

class Widget : public QWidget
{
    Q_OBJECT
    BufferNames buffer;
public:
    Widget(QWidget *parent = nullptr);

    QLabel *labelAll;
    QLabel *labelPalindrome;
    QListWidget *listWidgetAll;
    QListWidget *listWidgetPalindrome;
    QListWidgetItem *listWidgetItem;

    void setNamesOnlistWidgetAll();
    void setNamesOnlistWidgetPalindrome();


    ~Widget();
};

#endif // WIDGET_H
