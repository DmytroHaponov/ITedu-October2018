#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "reTextedit.h"
#include <QtSql>

class MainWindow : public QWidget
{
    Q_OBJECT
protected:
    QString CONNECTION_NAME = "";
    QString database_name;
    QString button_style = ("QPushButton"
                            "{ "
                           "background-color: darkgray;"
                           ///"border-style: outset;"
                           ///"border-width: 2px;"
                           ///"border-radius: 10px;"
                           ///"border-color: white;"
                           "font: 14px;"
                           "min-width: 5em;"///10
                           "padding: 5px;"
                           "}"
                           "QPushButton:hover"
                            "{"
                            "background-color: rgb(211, 211, 211);"
                            "}"
                            "QPushButton:pressed"
                            "{ "
                            "background-color: rgb(255,255,255);"
                            "border-style: inset;"
                            "}"
                            );


    QString throw_msg;
    ///QString current_db_name;////

    QMenuBar *menu_bar;
    QPushButton *button;
    RETextEdit *text_edit;
    QLineEdit *line_edit;
    QTextEdit *output_msg;

    QTableView *view;
    QSqlQueryModel *model;

    QString output_history_str;
    QString input_history_str;
    QTextEdit *output_history_edit;
    QTextEdit *input_history_edit;

    QToolBar *tool_bar;

    QMainWindow *tool_window;

    void create_tool_bar();
    void quit();
    void init_menu();

    void on_disconnection(bool notify);
    void on_connection();

    void ask_database_name();
    bool is_on_connection();
    void show_help();
    void construct_window();
    void throw_err_window(QSqlDatabase& db);
    void change_text_color(QString color);
    void set_output_msg(QString str, QString color = "black");
    void show_output_history();
    void show_input_history();

    void show_file_mng();

    void exec_output_msg();
    void output_help_instructions(QTextEdit *how2qry);
    void output_help_lables(QGroupBox *lables_groupbox);

public:
    MainWindow(QWidget *parent = 0);

    void insert();
    void remove();
    void show_elements();
    void create_table();

    void on_read();
    void send_query();
    void show_db();


    ~MainWindow();
};

#endif // MAINWINDOW_H
