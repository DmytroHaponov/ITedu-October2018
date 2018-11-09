#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dialog.h>
#include <QtSql>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void on_create_table();

private slots:

    void on_actionNew_database_triggered();

    void on_btnAddItem_clicked();

    void on_btnDeleteItem_clicked();

    void on_actionConnect_to_database_triggered();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    Dialog dialog;
    QSqlTableModel *tableModel;

};

#endif // MAINWINDOW_H
