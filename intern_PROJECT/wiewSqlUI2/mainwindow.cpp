#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


     ui->setupUi(this);
     db = QSqlDatabase::addDatabase("QSQLITE");
     this->setFixedSize(1068,506);
     ui->editStatus->setReadOnly(true);
     checkbtnQry = false;
     checkbtnEdit = false;
     checkbtnDell = false;
     checkNewDB=false;
     ui->edit1->hide();
     ui->edit2->hide();
     ui->edit3->hide();
     ui->labelname->hide();
     ui->Editname->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionNew_triggered()
{
    checkNewDB=true;
    ui->labelname->show();
    ui->Editname->show();
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Открыть файл БД"), "F:/", " Data based(*.db)(*.sl3);; All files (*.*) ") ;
    db.setDatabaseName(filename);
    if(!db.open()){
        QString non = db.lastError().text();
        ui->editStatus->setText(non);
    }
    else ui->editStatus->setText("База даных подключена... "+filename+"");
    ui->labelname->hide();
    ui->Editname->hide();
}

void MainWindow::on_showDB_clicked()
{
    ui->edit1->clear();
    ui->edit2->clear();
    ui->edit3->clear();
    nameTable = ui->editNameTb->text();


    QSqlQueryModel *model =new QSqlQueryModel();
    QSqlQuery *sq = new QSqlQuery(db);
    sq->prepare("select * from '"+nameTable+"'");
    if(!sq->exec()){
        QMessageBox::critical(this,tr("Ошибка"),tr("Вы неверно задали имя"));
    }
    model->setQuery(*sq);
    ui->tableView->setModel(model);
    ui->labelname->hide();
    ui->Editname->hide();
}



void MainWindow::on_actionSave_triggered()
{
    if(checkbtnDell == false && checkbtnEdit == false && checkbtnQry == false) {
        ui->editStatus->setText("Все сохранено");
    }


    if(checkNewDB == true){ //Check what you need to keep
        QString name;
        name = ui->Editname->text();
        if(name ==""){
            QMessageBox::critical(this,tr("Ошибка"),tr("Вы неверно задали имя"));
        }
        else{
           db.setDatabaseName(name +".sl3");
           if(!db.open()){
               QString non = db.lastError().text();
               ui->editStatus->setText(non);
           }
           else ui->editStatus->setText("База даных подключена... "+name+"");
        }
    }


    if(checkbtnDell ==true){//Check what you need to keep
       QString row;
       row = ui->edit1->text();
       QSqlQuery sqdll;
       sqdll.prepare("Delete from '"+nameTable+"' where ID = '"+row+"'");
       if(sqdll.exec()){
                   ui->editStatus->setText("Успешно сохранено... Удалена строка ID->"+row+"");

               }
               else ui->editStatus->setText("Не сохранилось... '"+sqdll.lastError().text()+"'");
    }

    if(checkbtnEdit == true){//Check what you need to keep
        QString colum, write,row;
        colum =ui->edit1->text();
        row = ui->edit2->text();
        write = ui->edit3->text();

        QSqlQuery sqed;
        sqed.prepare("update '"+nameTable+"' set '"+colum+"' = '"+write+"' where ID = '"+row+"'");
        if(sqed.exec()){
            ui->editStatus->setText("Успешно сохранено... Изменено");
        }
        else ui->editStatus->setText("Не сохранилось... '"+sqed.lastError().text()+"'");
    }


    if(checkbtnQry == true){//Check what you need to keep
        QString column;
        column = ui->edit1->text();


        QSqlQueryModel *model =new QSqlQueryModel();
        QSqlQuery *sq = new QSqlQuery(db);


        sq->prepare("Select "+column+" from '"+nameTable+"'");
        if(sq->exec()){
                    ui->editStatus->setText("Успешно сохранено... Столбик->"+column+"");
                    model->setQuery(*sq);
                    ui->tableView->setModel(model);
                }
                else ui->editStatus->setText("Не сохранилось... '"+sq->lastError().text()+"'");
    }
    ui->labelname->hide();
    ui->Editname->hide();
    checkNewDB=false;
}



void MainWindow::on_buttQueryEdit_clicked()
{
    checkbtnDell = false;
    checkbtnQry = false;
    checkbtnEdit = true;



    ui->labQuery1->setText("Введите название столбика");
    ui->labQuery2->setText("Введите ID строчки");
    ui->labQuery3->setText("Редактировать");

    ui->edit1->show();
    ui->labQuery2->show();
    ui->edit2->show();
    ui->labQuery3->show();
    ui->edit3->show();
    ui->edit1->clear();
    ui->edit2->clear();
    ui->edit3->clear();
    ui->labelname->hide();
    ui->Editname->hide();
}

void MainWindow::on_buttQueryDell_clicked()
{
    checkbtnDell = true;
    checkbtnQry = false;
    checkbtnEdit = false;



    ui->labQuery1->setText("Введите ID строчки");
    ui->labQuery2->hide();
    ui->edit2->hide();
    ui->labQuery3->hide();
    ui->edit3->hide();
    ui->edit1->clear();
    ui->edit2->clear();
    ui->edit3->clear();
    ui->edit1->show();
    ui->labelname->hide();
    ui->Editname->hide();
}

void MainWindow::on_buttQuery_clicked()
{
    checkbtnEdit = false;
    checkbtnDell =  false;
    checkbtnQry = true;



    ui->labQuery1->setText("Введите название столбика");
    ui->labQuery2->hide();
    ui->labQuery3->hide();
    ui->edit3->hide();
    ui->edit2->hide();
    ui->edit1->clear();
    ui->edit2->clear();
    ui->edit1->show();
    ui->edit3->clear();
    ui->labelname->hide();
    ui->Editname->hide();
}




void MainWindow::on_actionExit_triggered()
{
    close();
}
