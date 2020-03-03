#include "personelkayit.h"
#include "ui_personelkayit.h"
#include "personelekle.h"
#include <QMessageBox>
#include <QApplication>

#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>

personelkayit::personelkayit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::personelkayit)
{
    ui->setupUi(this);
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/SQL/setras_envanter_yemekhane.db");

    if(!mydb.open())
        qDebug() << mydb.lastError().text();

    ui->table->hideColumn(0);

    FillTable();

}

personelkayit::~personelkayit()
{
    delete ui;
}

void personelkayit::on_pushButton_8_clicked()
{
    personelekle personelekle;
    personelekle.setModal(true);
    personelekle.exec();

    FillTable();
}


void personelkayit::on_pushButton_5_clicked()
{
    QPrinter printer;
    QPrintDialog dialog(&printer);
    if(dialog.exec() == QDialog::Accepted){
        QPainter painter(&printer);
        ui->table->render(&painter);
    }
}


void personelkayit::FillTable(){
    loading = true;
    int num_rows, r, c;
    QSqlQuery q(mydb);
    if(!q.exec("SELECT count(isim) as num_rows FROM personel")) qDebug() << q.lastError().text();
    q.first();
    num_rows = q.value(0).toInt();
    ui->table->setRowCount(num_rows);

    if(!q.exec("SELECT speid, isim, soyisim, telefon, nickname, sifre, dep, cal, time FROM personel ORDER BY isim")) qDebug() << q.lastError().text();
    for(r=0, q.first(); q.isValid(); q.next(), ++r){
        for(c=0; c<10; ++c){
            ui->table->setItem(r, c, new QTableWidgetItem(q.value(c).toString()));
        }
    }
    loading = false;
}

void personelkayit::on_table_cellChanged(int row, int column)
{
    if (loading) return;

    QSqlQuery q(mydb);

    q.prepare("UPDATE depo SET isim = :i, soyisim = :soy, telefon = :t, nickname = :n, sifre = :s, dep = :d, cal = :cal, time = :time WHERE speid = :spe");
    q.bindValue(":i", ui->table->item(row, 1)->text().toInt());
    q.bindValue(":soy", ui->table->item(row, 2)->text());
    q.bindValue(":t", ui->table->item(row, 3)->text());
    q.bindValue(":n", ui->table->item(row, 4)->text());
    q.bindValue(":s", ui->table->item(row, 5)->text());
    q.bindValue(":d", ui->table->item(row, 6)->text());
    q.bindValue(":cal", ui->table->item(row, 7)->text());
    q.bindValue(":time", ui->table->item(row, 8)->text());
    q.bindValue(":spe", ui->table->item(row, 0)->text().toInt());


    if(!q.exec()) qDebug() << q.lastError().text();

    FillTable();
}

void personelkayit::on_pushButton_6_clicked()
{
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Kontrol", "Silmek istediğinizden emin misiniz?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
        qDebug() << "Yes was clicked";
        QString del = ui->table->item(ui->table->currentRow(), 0)->text();
        QSqlQuery q(mydb);
        q.prepare("DELETE FROM personel WHERE speid = :spe");
        q.bindValue(":spe", del);
        if(!q.exec()) qDebug() << q.lastError().text();

        FillTable();
      }
      else {
        qDebug() << "Yes was *not* clicked";
      }

}

void personelkayit::on_pushButton_7_clicked()
{
    FillTable();
}


