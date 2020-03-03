#include "yonetimlogin.h"
#include "ui_yonetimlogin.h"
#include "yonetimpanel.h"
#include <QMessageBox>

yonetimlogin::yonetimlogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::yonetimlogin)
{
    ui->setupUi(this);

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/SQL/setras_envanter_yemekhane.db");

    if(mydb.open())
        ui->label->setText("Bağlandı");
    else
        ui->label->setText("Bağlanamadı");

}

yonetimlogin::~yonetimlogin()
{
    delete ui;
}

void yonetimlogin::on_buttonBox_accepted()
{
    QString username,password,dep,user,pass;
    username = ui->lineEdit->text();
    password = ui->lineEdit_2->text();

    if(!mydb.isOpen()){
        qDebug()<<"Veritabanına ulaşılamıyor!";
        return;
    }

    QSqlQuery qry;


    QCryptographicHash CalculateMD5(QCryptographicHash::Md5);
    QByteArray aa = username.toLatin1();
    CalculateMD5.addData(aa);
    user=CalculateMD5.result().toHex();

    QCryptographicHash CalculateMD5_2(QCryptographicHash::Md5);
    QByteArray bb = password.toLatin1();
    CalculateMD5.addData(bb);
    pass=CalculateMD5.result().toHex();



    if(qry.exec("select * from personel where nickname='"+user+"' and sifre='"+pass+"'")){
        int count = 0;
        while(qry.next())
            count++;

        //dep = qry.exec("select dep from personel");

        //qDebug() << dep;

        if(count==1){
            //if(dep == "Yonetim"){
               yonetimpanel yonetimpanel;
               yonetimpanel.setModal(true);
               yonetimpanel.exec();
            //}
        }
        else {
            QMessageBox::warning(this, "Hata!", "Buraya giriş yetkiniz bulunmamaktadır!");
            qDebug()<<"Yonetim paneline yetkisiz giris istegi!";
            return;
        }

        mydb.close();
    }

}

