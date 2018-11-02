#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <mainwindow.h>


class SecondWindow : public QDialog{
    Q_OBJECT
public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow() = default;
protected:
    void connClose();
    bool connOpen();
    void onRunning();
    void setInterfaceStyle();
    void chooseDb(const QModelIndex & index);
    void hints();
    void about();
    bool createNewDb();

protected:
    QLabel *statusLabel;
    QString pathToDb;
    QString nameDb;
    QStatusBar *statusBar;
    QMenuBar* menuBar;
    QTableView* sqlView;
    QTextEdit* sqlEdit;
    QTextEdit* sqlResults;
    QSqlQueryModel* sqlModel;
    QFileSystemModel* fileSystemModel;
    QTreeView* treeView;
    QModelIndex mIndex;
    QMessageBox* hintBox;
    QMessageBox* aboutBox;
};

#endif // SECONDWINDOW_H
