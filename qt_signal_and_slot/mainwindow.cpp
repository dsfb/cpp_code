#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    one = new FormOne();
    two = new FormTwo();
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::showWindows);
    connect(one, &FormOne::textChanged, two, &FormTwo::setText);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showWindows()
{
    one->show();
    two->show();
}
