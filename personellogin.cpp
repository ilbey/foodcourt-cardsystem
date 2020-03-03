#include "personellogin.h"
#include "ui_personellogin.h"
#include "personelpanel.h"
#include "depourunkayit.h"
#include <QMessageBox>

personellogin::personellogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::personellogin)
{
    ui->setupUi(this);

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/SQL/setras_envanter_yemekhane.db");

    if(mydb.open())
        ui->label_6->setText("Bağlandı");
    else
        ui->label_6->setText("Bağlanamadı");
}

personellogin::~personellogin()
{
    delete ui;
}


void personellogin::on_buttonBox_accepted()
{
    QString username,password,combo,user,pass;
    username = ui->lineEdit->text();
    password = ui->lineEdit_2->text();
    combo = ui->comboBox->currentText();

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



    if(qry.exec("select * from personel where nickname='"+user+"' and sifre='"+pass+"' and dep='"+combo+"'")){
        int count = 0;
        while(qry.next())
            count++;

        if(count==1){
            if(combo == "Depo" or combo == "Yonetim"){
                depourunkayit depourunkayit;
                depourunkayit.setModal(true);
                depourunkayit.exec();
            }
        }
        else {
            QMessageBox::warning(this, "Hata!", "Kullanıcı adı, şifreniz veya bölüm bilgileriniz yanlış!");
            qDebug()<<"Kullanıcı adı, şifreniz veya bölüm bilgileriniz yanlış!";
            return;
        }

        mydb.close();
    }

}
