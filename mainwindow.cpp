#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "yonetimlogin.h"
#include "personellogin.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    yonetimlogin yonetimlogin;
    yonetimlogin.setModal(true);
    yonetimlogin.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    personellogin personellogin;
    personellogin.setModal(true);
    personellogin.exec();
}
