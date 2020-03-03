#include "personelekle.h"
#include "ui_personelekle.h"
#include <QMessageBox>

personelekle::personelekle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::personelekle)
{
    ui->setupUi(this);

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/SQL/setras_envanter_yemekhane.db");
    mydb.open();
}

personelekle::~personelekle()
{
    delete ui;
}

void personelekle::on_pushButton_9_clicked()
{
    QString speid,isim,soyisim,telefon,nickname,sifre,dep,cal,time,nick,pass;

    QTime tme = QTime::currentTime();
    QDate date = QDate::currentDate();
    QString timetext = tme.toString("hh:mm:ss");
    QString datetext = date.toString("dd/MM/yyyy");
    if((tme.second() % 2) == 0){
        timetext[3] = ' ';
        timetext[8] = ' ';
    }

    isim = ui->lineEdit_1->text();
    soyisim = ui->lineEdit_2->text();
    telefon = ui->lineEdit_3->text();
    nickname = ui->lineEdit_4->text();
    sifre = ui->lineEdit_5->text();
    dep = ui->comboBox->currentText();
    cal = datetext;
    time = timetext;

    timetext = tme.toString("hhmmss");
    datetext = date.toString("ddMMyyyy");
    speid = datetext + timetext;


    QCryptographicHash CalculateMD5(QCryptographicHash::Md5);
    QByteArray aa = nickname.toLatin1();
    CalculateMD5.addData(aa);
    nick=CalculateMD5.result().toHex();


    QCryptographicHash CalculateMD5_2(QCryptographicHash::Md5);
    QByteArray bb=sifre.toLatin1();
    CalculateMD5.addData(bb);
    pass=CalculateMD5.result().toHex();



    if(isim == nullptr or soyisim == nullptr or telefon == nullptr or nickname == nullptr or sifre ==nullptr){
        QMessageBox::StandardButton reply;
          reply = QMessageBox::warning(this, "Hata!", "Lütfen tüm alanları doldurunuz!",
                                        QMessageBox::Ok);
          if (reply == QMessageBox::Ok)
            qDebug() << "Ok was clicked";
    }

    else{

        QSqlQuery qry;

        qry = QSqlQuery("INSERT INTO personel (speid, isim, soyisim, telefon, nickname, sifre, dep, cal, time) VALUES ('"+speid+"','"+isim+"','"+soyisim+"','"+telefon+"','"+nick+"','"+pass+"','"+dep+"','"+cal+"','"+time+"')");

        this->close();
    }


    if(!mydb.isOpen()){
        qDebug()<<"Veritabanına ulaşılamıyor!";
        return;
    }

}

void personelekle::on_pushButton_10_clicked()
{
    this->close();
}

