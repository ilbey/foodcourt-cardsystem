#include "yonetimpanel.h"
#include "ui_yonetimpanel.h"
#include "depourunkayit.h"
#include "personelkayit.h"
#include "yemekhane.h"
#include "pastane.h"

yonetimpanel::yonetimpanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::yonetimpanel)
{
    ui->setupUi(this);
}

yonetimpanel::~yonetimpanel()
{
    delete ui;
}

void yonetimpanel::on_pushButton_6_clicked()
{
    depourunkayit depourunkayit;
    depourunkayit.setModal(true);
    depourunkayit.exec();
}

void yonetimpanel::on_pushButton_3_clicked()
{
    personelkayit personelkayit;
    personelkayit.setModal(true);
    personelkayit.exec();
}

void yonetimpanel::on_pushButton_7_clicked()
{
    yemekhane yemekhane;
    yemekhane.setModal(true);
    yemekhane.exec();
}

void yonetimpanel::on_pushButton_9_clicked()
{
    pastane pastane;
    pastane.setModal(true);
    pastane.exec();
}
