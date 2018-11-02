#include "secondwindow.h"
#include "mainwindow.h"

SecondWindow::SecondWindow(QWidget *parent)
    : QDialog (parent)
    , statusLabel (new QLabel)
    , statusBar (new QStatusBar)
    , menuBar(new QMenuBar)
    , sqlView(new QTableView)
    , sqlEdit(new QTextEdit)
    , sqlResults(new QTextEdit)
    , sqlModel(new QSqlQueryModel(sqlView))
    , fileSystemModel(new QFileSystemModel)
    , treeView(new QTreeView)
    , hintBox(new QMessageBox)
    , aboutBox(new QMessageBox)

{
    setInterfaceStyle();

    fileSystemModel->mkdir(mIndex,"SQliteDatabases");

    connect(treeView,&QTreeView::clicked,this,&SecondWindow::chooseDb);
    connect(treeView,&QTreeView::doubleClicked,this,&SecondWindow::chooseDb);
    connect(treeView,&QTreeView::doubleClicked,this,&SecondWindow::connOpen);
}

//connects to SQLite database and checks is the connection open and show connection status//

bool SecondWindow::connOpen(){
    connClose();

    auto mydb = QSqlDatabase::addDatabase("QSQLITE", nameDb);
    mydb.setDatabaseName(pathToDb);

    if(!mydb.open()){
        statusLabel->setText(nameDb + " not connected");
        statusBar->addWidget(statusLabel);
        return false;
    }
    else{
        sqlModel->setQuery("SELECT * from sqlite_master WHERE type = 'table'", mydb);
        statusLabel->setText(nameDb + " connected");
        statusBar->addWidget(statusLabel);
        return true;
    }
}

//closes connection and shows connection status//

void SecondWindow::connClose(){
    {
    auto mydb = QSqlDatabase::database(nameDb, false);
        if(mydb.isValid()){
            if(mydb.isOpen()){
                mydb.close();
                statusLabel->setText("Disconnected");
                statusBar->addWidget(statusLabel);
            }
        }
    }
    QSqlDatabase::removeDatabase(nameDb);
}

void SecondWindow::chooseDb(const QModelIndex & index){
    pathToDb = fileSystemModel->filePath(index);
    nameDb = fileSystemModel->fileName(index);
        for(int i = 0; i < nameDb.length(); ++i){
            if(nameDb[i] == '.'){
                nameDb.remove(i,nameDb.length());
            }
        }
}

//shows some hints in popup window//

void SecondWindow::hints(){
    hintBox->setText("To show all tables, insert: SELECT * from sqlite_master WHERE type = 'table'\n\n"
                     "To create new table, insert comand like: CREATE TABLE table_name"
                     "(column1 datatype, column2 datatype, column3 datatype);\n\n\n"
                     "To start working with database, choose your SQLite database file with one click and "
                     "push connect in 'file' menu, or double click to open auto-connection with your database. "
                     "After successful connection, to start working with database, insert sql command to "
                     "line edit and push run command in 'build' menu or push F2 button. "
                     "You also can create new database, SQLite database file will be create "
                     "in 'SQliteDatabases' folder in current directory.");
    hintBox->show();
}

//shows information about software//

void SecondWindow::about(){
    aboutBox->setText("Version 1.0\n"
                      "Qt Version 5.11.2\n"
                      "SQLite Version 3\n\n"
                      "SQlite DB Viewer is an open source, freeware visual tool used to create and edit "
                      "SQLite database files.\n\n\n"
                      "This software uses  (L)GPL v3 license Qt Toollkit from "
                      "Visit the https://www1.qt.io/licensing/ for licensing terms and information\n\n"
                      "Source code is availible on GitHub");
    aboutBox->show();
}

//creates new SQLite database//

bool SecondWindow::createNewDb(){
    connClose();

    nameDb = sqlEdit->document()->toPlainText();

    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE",nameDb);
    mydb.setDatabaseName("SQliteDatabases/"+nameDb);
    mydb.open();
        if(!mydb.open()){
            if(nameDb == ""){
                statusLabel->setText("Please enter name of database");
                statusBar->addWidget(statusLabel);
            }
            else{
                statusLabel->setText(nameDb + " not connected");
                statusBar->addWidget(statusLabel);
            }
            return false;
        }
        else{
            statusLabel->setText(nameDb + " connected");
            statusBar->addWidget(statusLabel);
            return true;
        }
}

//runs sql query to database from edit form and shows last error, if something gone wrong.//

void SecondWindow::onRunning(){
    auto mydb = QSqlDatabase::database(nameDb, false);

    sqlModel->setQuery(sqlEdit->document()->toPlainText(), mydb);

    sqlResults->append(sqlModel->lastError().text());
}

// inits style of interface and adds some menus//

void SecondWindow::setInterfaceStyle(){

    this->resize(960,600);
    this->setGeometry(200,100,960,600);

    sqlResults->setReadOnly(true);

    sqlView->setModel(sqlModel);

    sqlEdit->setUndoRedoEnabled(true);

    mIndex = fileSystemModel->index(QDir::currentPath());
    fileSystemModel->setRootPath(QDir::rootPath());

    treeView->setModel(fileSystemModel);
    treeView->hideColumn(1);
    treeView->hideColumn(2);
    treeView->hideColumn(3);
    treeView->setAnimated(true);
    treeView->setHeaderHidden(true);
    treeView->resizeColumnToContents(0);

    auto menuDatabase = menuBar->addMenu("File");
    menuDatabase->addAction("Create new database",this,&SecondWindow::createNewDb);
    menuDatabase->addSeparator();
    menuDatabase->addAction("Open database",this, &SecondWindow::connOpen);
    menuDatabase->addAction("Close database", this, &SecondWindow::connClose);
    menuDatabase->addSeparator();
    menuDatabase->addAction("Exit",this,&SecondWindow::close);

    auto menuQuery = menuBar->addMenu("Build");
    menuQuery->addAction("Run", this, &SecondWindow::onRunning, Qt::Key_F2);

    auto menuInfo = menuBar->addMenu("Help");
    menuInfo->addAction("About SQLite DB Viewer",this,&SecondWindow::about);
    menuInfo->addAction("Hint",this,&SecondWindow::hints);

    this->setWindowFlags((Qt::WindowMinMaxButtonsHint)|(Qt::WindowCloseButtonHint));

    QPalette widgetPal(palette());
    widgetPal.setColor(QPalette::Background,Qt::darkGray);
    hintBox->setAutoFillBackground(true);
    hintBox->setPalette(widgetPal);
    aboutBox->setAutoFillBackground(true);
    aboutBox->setPalette(widgetPal);
    this->setAutoFillBackground(true);
    this->setPalette(widgetPal);

    QPalette viewPal(palette());
    viewPal.setColor(QPalette::Base,Qt::gray);
    sqlEdit->setAutoFillBackground(true);
    sqlEdit->setPalette(viewPal);
    sqlResults->setAutoFillBackground(true);
    sqlResults->setPalette(viewPal);
    sqlView->setAutoFillBackground(true);
    sqlView->setPalette(viewPal);
    treeView->setAutoFillBackground(true);
    treeView->setPalette(viewPal);

    QSplitter* vSplitter = new QSplitter(Qt::Vertical);
    vSplitter->addWidget(sqlView);
    vSplitter->addWidget(sqlEdit);
    vSplitter->addWidget(sqlResults);
    vSplitter->setStretchFactor(0, 9);
    vSplitter->setStretchFactor(1, 3);
    vSplitter->setStretchFactor(2, 1);

    QSplitter* hSplitter = new QSplitter(Qt::Horizontal);
    hSplitter->addWidget(treeView);
    hSplitter->addWidget(vSplitter);
    hSplitter->setStretchFactor(0, 1);
    hSplitter->setStretchFactor(1, 3);
    hSplitter->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    QVBoxLayout* vlayo = new QVBoxLayout;
    vlayo->setMargin(0);
    vlayo->setSpacing(5);
    vlayo->addWidget(menuBar);
    vlayo->addWidget(hSplitter);
    vlayo->addWidget(statusBar);

    this->setLayout(vlayo);
}
