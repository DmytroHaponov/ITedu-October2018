#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDir>
#include <QFileDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    QString databaseName;
    QString databasePath;

private slots:
    void on_btn_open_clicked();

    void on_btn_ok_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
