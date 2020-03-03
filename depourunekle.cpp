#include "depourunekle.h"
#include "ui_depourunekle.h"
#include <QMessageBox>

depourunekle::depourunekle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::depourunekle)
{
    ui->setupUi(this);

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/SQL/setras_envanter_yemekhane.db");
    mydb.open();
}

depourunekle::~depourunekle()
{
    delete ui;
}

void depourunekle::on_pushButton_tamam_clicked()
{
    QString speid,barkod,isim,fiyat,miktar,skt,garanti,cal,time;

    QTime tme = QTime::currentTime();
    QDate date = QDate::currentDate();
    QString timetext = tme.toString("hh:mm:ss");
    QString datetext = date.toString("dd/MM/yyyy");
    if((tme.second() % 2) == 0){
        timetext[3] = ' ';
        timetext[8] = ' ';
    }

    barkod = ui->lineEdit_1->text();
    isim = ui->lineEdit_2->text();
    fiyat = ui->lineEdit_3->text();
    miktar = ui->lineEdit_4->text();
    skt = ui->lineEdit_5->text();
    garanti = ui->lineEdit_6->text();
    cal = datetext;
    time = timetext;

    timetext = tme.toString("hhmmss");
    datetext = date.toString("ddMMyyyy");
    speid = datetext + timetext;


    if(barkod == nullptr or isim == nullptr or fiyat == nullptr or miktar == nullptr or (skt == nullptr or garanti ==nullptr)){
        QMessageBox::StandardButton reply;
          reply = QMessageBox::warning(this, "Hata!", "Lütfen tüm alanları doldurunuz!",
                                        QMessageBox::Ok);
          if (reply == QMessageBox::Ok)
            qDebug() << "Ok was clicked";
    }

    else{

        QSqlQuery qry;

        qry = QSqlQuery("INSERT INTO depo (speid, id, isim, fiyat, miktar, tarih, garanti, cal, time) VALUES ('"+speid+"','"+barkod+"','"+isim+"','"+fiyat+"','"+miktar+"','"+skt+"','"+garanti+"','"+cal+"','"+time+"')");

        this->close();
    }


    if(!mydb.isOpen()){
        qDebug()<<"Veritabanına ulaşılamıyor!";
        return;
    }

}

void depourunekle::on_pushButton_iptal_clicked()
{
    this->close();
}

