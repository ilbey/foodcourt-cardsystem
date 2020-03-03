#include "pastane.h"
#include "ui_pastane.h"
#include "pastaneurunekle.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QApplication>
#include <QMessageBox>


pastane::pastane(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pastane)
{
    ui->setupUi(this);
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/SQL/setras_envanter_yemekhane.db");

    if(!mydb.open())
        qDebug() << mydb.lastError().text();

    ui->table->hideColumn(0);

    FillTable();

}

pastane::~pastane()
{
    delete ui;
}

void pastane::on_pushButton_8_clicked()
{
    pastaneurunekle pastaneurunekle;
    pastaneurunekle.setModal(true);
    pastaneurunekle.exec();

    FillTable();
}

void pastane::on_pushButton_5_clicked()
{
    QPrinter printer;
    QPrintDialog dialog(&printer);
    if(dialog.exec() == QDialog::Accepted){
        QPainter painter(&printer);
        ui->table->render(&painter);
    }
}

void pastane::FillTable(){
    loading = true;
    int num_rows, r, c;
    QSqlQuery q(mydb);
    if(!q.exec("SELECT count(cal) as num_rows FROM pastane")) qDebug() << q.lastError().text();
    q.first();
    num_rows = q.value(0).toInt();
    ui->table->setRowCount(num_rows);

    if(!q.exec("SELECT speid, id, isim, fiyat, miktar, tarih, garanti, cal, time FROM pastane ORDER BY speid")) qDebug() << q.lastError().text();
    for(r=0, q.first(); q.isValid(); q.next(), ++r){
        for(c=0; c<9; ++c){
            ui->table->setItem(r, c, new QTableWidgetItem(q.value(c).toString()));
        }
    }
    loading = false;
}

void pastane::on_table_cellChanged(int row, int column)
{
    if (loading) return;

    QSqlQuery q(mydb);

    q.prepare("UPDATE pastane SET id = :id, isim = :i, fiyat = :f, miktar = :m, tarih = :t, garanti = :g, cal = :cal, time = :time WHERE speid = :spe");
    q.bindValue(":id", ui->table->item(row, 1)->text().toInt());
    q.bindValue(":i", ui->table->item(row, 2)->text());
    q.bindValue(":f", ui->table->item(row, 3)->text());
    q.bindValue(":m", ui->table->item(row, 4)->text());
    q.bindValue(":t", ui->table->item(row, 5)->text());
    q.bindValue(":g", ui->table->item(row, 6)->text());
    q.bindValue(":cal", ui->table->item(row, 7)->text());
    q.bindValue(":time", ui->table->item(row, 8)->text());
    q.bindValue(":spe", ui->table->item(row, 0)->text().toInt());


    if(!q.exec()) qDebug() << q.lastError().text();

    FillTable();
}

void pastane::on_pushButton_6_clicked()
{
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Kontrol", "Silmek istediğinizden emin misiniz?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
        qDebug() << "Yes was clicked";
        QString del = ui->table->item(ui->table->currentRow(), 0)->text();
        QSqlQuery q(mydb);
        q.prepare("DELETE FROM pastane WHERE speid = :spe");
        q.bindValue(":spe", del);
        if(!q.exec()) qDebug() << q.lastError().text();

        FillTable();
      }
      else {
        qDebug() << "Yes was *not* clicked";
      }

}

void pastane::on_pushButton_7_clicked()
{
    FillTable();
}
