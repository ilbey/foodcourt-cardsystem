#ifndef YEMEKHANEURUNEKLE_H
#define YEMEKHANEURUNEKLE_H

#include <QDialog>

#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

namespace Ui {
class yemekhaneurunekle;
}

class yemekhaneurunekle : public QDialog
{
    Q_OBJECT

public:
    explicit yemekhaneurunekle(QWidget *parent = nullptr);
    ~yemekhaneurunekle();

private slots:
    void on_pushButton_tamam_clicked();

    void on_pushButton_iptal_clicked();

private:
    Ui::yemekhaneurunekle *ui;
    QSqlDatabase mydb;
};

#endif // YEMEKHANEURUNEKLE_H

