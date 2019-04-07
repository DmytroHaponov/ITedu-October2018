#include "BufferNames.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>
#include <QDebug>

BufferNames::BufferNames() :
    listAllNames {new QStringList},
    listPalindromeNames {new QStringList}
{
}

BufferNames::~BufferNames()
{
    delete listAllNames;
    delete listPalindromeNames;
}

void BufferNames::readFileNames(const QString strNameFile)
{
    QFile file(strNameFile);
    if(!file.open(QIODevice::ReadOnly)) {
//        QMessageBox::information(nullptr, "error", file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        listAllNames->push_back(line);
    }

    if(listAllNames->isEmpty()){
        listAllNames->push_back("Not found the names.");
    }

    file.close();
}

QStringList *BufferNames::getStringListAllNames()
{
    return listAllNames;
}

QStringList *BufferNames::getStringListPalindromeNames()
{
    searchPalindromeNames();
    return listPalindromeNames;
}

void BufferNames::searchPalindromeNames()
{
    if(!listPalindromeNames->isEmpty()){
        return;
    }
    for(const QString &str: *listAllNames){
        if(isPalindrome(str)){
            listPalindromeNames->push_back(str);
        }
    }
    if(listPalindromeNames->isEmpty()){
        listPalindromeNames->push_back("Not found the Palindrome names.");
    }
}

bool BufferNames::isPalindrome(const QString &str)
{
    if(str.isEmpty() || str.size() <= 1) return false;

    for (int var {0}; var < str.size() / 2; ++var) {
        if(str.at(var) != str.at(str.size() - var -1)){
            return false;
        }
    }
    return true;
}

int BufferNames::getNumberAllNames()
{
    return listAllNames->size();
}
