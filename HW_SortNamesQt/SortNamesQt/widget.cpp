#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      labelAll {new QLabel("All names", this)},
      labelPalindrome {new QLabel("Palindromic names", this)},
      listWidgetAll {new QListWidget(this)},
      listWidgetPalindrome {new QListWidget(this)},
      listWidgetItem {nullptr}

{
    buffer.readFileNames(qApp->applicationDirPath() + "/namesRusOutput=UTF-8.txt");

    setNamesOnlistWidgetAll();
    setNamesOnlistWidgetPalindrome();

    QGridLayout *lay = new QGridLayout(this);
    lay->addWidget(labelAll, 0, 0);
    lay->addWidget(labelPalindrome, 0, 1);
    lay->addWidget(listWidgetAll, 1, 0);
    lay->addWidget(listWidgetPalindrome, 1, 1);

}

void Widget::setNamesOnlistWidgetAll()
{
    for (int var = 0; var < buffer.getNumberAllNames(); ++var) {

        listWidgetItem = new QListWidgetItem((buffer.getStringListAllNames())->at(var), listWidgetAll);
    }
}

void Widget::setNamesOnlistWidgetPalindrome()
{
    QListWidgetItem *listWidgetItemPalindrome = {nullptr};
    for (const QString &str: *(buffer.getStringListPalindromeNames())) {
        listWidgetItemPalindrome = new QListWidgetItem(str, listWidgetPalindrome);
    }

}

Widget::~Widget()
{

}
