#include "mainwindows.h"
#include "ui_mainwindows.h"

MainWindows::MainWindows(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindows)
{
    ui->setupUi(this);
}

MainWindows::~MainWindows()
{
    delete ui;
}
