#ifndef DEPOURUNKAYIT_H
#define DEPOURUNKAYIT_H

#include <QDialog>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QDebug>
#include <QVariant>

namespace Ui {
class depourunkayit;
}

class depourunkayit : public QDialog
{
    Q_OBJECT

public:
    explicit depourunkayit(QWidget *parent = nullptr);
    ~depourunkayit();

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_table_cellChanged(int row, int column);

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();


    void on_table_cellClicked(int row, int column);

private:
    Ui::depourunkayit *ui;
    QSqlDatabase mydb;

    bool loading;

    void FillTable();

    QString speid,barkod,isim,fiyat,miktar,skt,garanti,cal,time;


};

#endif // DEPOURUNKAYIT_H
