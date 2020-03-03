#include "personelpanel.h"
#include "ui_personelpanel.h"

personelpanel::personelpanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::personelpanel)
{
    ui->setupUi(this);
}

personelpanel::~personelpanel()
{
    delete ui;
}
