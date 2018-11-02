#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtWidgets>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

//=========MenuBar Slots==============

    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionExit_triggered();

//====================================

//=========Button Slots===============

    void on_showDB_clicked();
    void on_buttQueryEdit_clicked();
    void on_buttQueryDell_clicked();
    void on_buttQuery_clicked();




private:
   Ui::MainWindow *ui;

   QSqlDatabase db;

//=======Check Clicked Button====

   bool checkbtnQry;
   bool checkbtnDell;
   bool checkbtnEdit;
   bool checkNewDB;

//====================================
   QString nameTable;

};

#endif // MAINWINDOW_H
