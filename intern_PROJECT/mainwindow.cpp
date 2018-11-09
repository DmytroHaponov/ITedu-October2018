#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_create_table()
{
    QSqlQuery query;
    QString str = "CREATE TABLE Products (ID INTEGER UNIQUE NOT NULL, "
                                         "Name VARCHAR(255) NOT NULL, "
                                         "Quantity VARCHAR(10) NOT NULL, "
                                         "Price VARCHAR(10));";

    if(!query.exec(str))
    {
        qDebug() << query.lastError();
    }
}

void MainWindow::on_actionNew_database_triggered()
{
    Dialog dialog;
    dialog.exec();

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dialog.databasePath);

    if(!db.open())
    {
        qDebug() << db.lastError();
    }
    else
    {
        ui->sqlLog->append("Database created at: " + dialog.databasePath);
    }

    on_create_table();

    tableModel = new QSqlTableModel(nullptr,db);
    tableModel->setTable("Products");
    ui->sqlTableView->setModel(tableModel);
    tableModel->select();
    ui->sqlTableView->show();
}

void MainWindow::on_btnAddItem_clicked()
{
    QSqlQuery query;
    QString query_add = "INSERT INTO Products (ID, Name, Quantity, Price) VALUES ('%1', '%2', '%3', '%4');";
    QString str = query_add.arg(ui->prodID->text())
                           .arg(ui->prodName->text())
                           .arg(ui->prodQty->text())
                           .arg(ui->prodPrice->text());

    if(!query.exec(str))
    {
        qDebug() << "Unable to make insertion: " <<query.lastError();
    }
    else
    {
        ui->sqlLog->append("Item inserted, id: " + ui->prodID->text());
    }

    if(!query.exec("SELECT * FROM Products;"))
    {
        qDebug() << "Uable to execute query: " <<query.lastError();
    }

    tableModel->select();
    ui->sqlTableView->show();
}

void MainWindow::on_btnDeleteItem_clicked()
{
    QSqlQuery query;
    QString str = "DELETE FROM Products WHERE ID = '" + ui->prodID->text() + "';";

    if(!query.exec(str))
    {
        qDebug() << "Unable to delete row: " << query.lastError();
    }
    else
    {
        ui->sqlLog->append("Item deleted, id: " + ui->prodID->text());
    }

    tableModel->select();
    ui->sqlTableView->show();
}

void MainWindow::on_actionConnect_to_database_triggered()
{
    QFileDialog fileDialog(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(fileDialog.getOpenFileName());

    if(!db.open())
    {
        qDebug() << db.lastError();
    }
    else
    {
        ui->sqlLog->append("Database opened at: " + fileDialog.getOpenFileName());
    }

    tableModel = new QSqlTableModel(nullptr,db);
    tableModel->setTable("Products");
    ui->sqlTableView->setModel(tableModel);
    tableModel->select();
    ui->sqlTableView->show();
}
