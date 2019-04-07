#ifndef BUFFERNAMES_H
#define BUFFERNAMES_H

#include <QStringList>
#include <QString>


class BufferNames
{

    QStringList *listAllNames;
    QStringList *listPalindromeNames;

    void searchPalindromeNames();
    bool isPalindrome(const QString &str);
public:
    BufferNames();
    ~BufferNames();
    void readFileNames(const QString strNameFile);
    QStringList *getStringListAllNames();
    QStringList *getStringListPalindromeNames();
    int getNumberAllNames();
};

#endif // BUFFERNAMES_H
