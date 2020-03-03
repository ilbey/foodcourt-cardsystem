#ifndef PERSONELKAYIT_H
#define PERSONELKAYIT_H
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
class personelkayit;
}

class personelkayit : public QDialog
{
    Q_OBJECT

public:
    explicit personelkayit(QWidget *parent = nullptr);
    ~personelkayit();

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_table_cellChanged(int row, int column);

    void on_pushButton_7_clicked();

private:
    Ui::personelkayit *ui;
    QSqlDatabase mydb;

    bool loading;

    void FillTable();
};

#endif // PERSONELKAYIT_H
