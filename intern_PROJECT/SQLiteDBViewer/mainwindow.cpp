#include "mainwindow.h"
#include "secondwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
     setStyle();
     QTimer::singleShot(5000,this,&MainWindow::start);
}

void MainWindow::start(){
        this->hide();
        SecondWindow obj;
        obj.setModal(true);
        obj.exec();
}

void MainWindow::setStyle(){
    this->setFixedSize(960,600);
    this->setGeometry(200,100,960,600);

    QLabel *picLabel = new QLabel;
    picLabel->setPixmap(QPixmap(":/img/index.png"));

    QVBoxLayout *vlayo = new QVBoxLayout;
    vlayo->setMargin(0);
    vlayo->addWidget(picLabel);
    this->setLayout(vlayo);

    this->setWindowFlags(Qt::CustomizeWindowHint);
}

