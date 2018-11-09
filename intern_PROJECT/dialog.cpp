#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->db_name_edit->setText("database.db");
    ui->db_path_edit->setText(QDir::currentPath());

    connect(ui->btn_ok, &QPushButton::clicked, this, &Dialog::close);

}
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btn_open_clicked()
{
    ui->db_path_edit->setText(QFileDialog::getExistingDirectory(this, tr("Chahge folder"), QDir::currentPath(), QFileDialog::ShowDirsOnly));
}

void Dialog::on_btn_ok_clicked()
{
    databasePath = ui->db_path_edit->text() + "/" + ui->db_name_edit->text();
}
