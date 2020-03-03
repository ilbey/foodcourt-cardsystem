#ifndef DEPOURUNEKLE_H
#define DEPOURUNEKLE_H

#include <QDialog>

#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

namespace Ui {
class depourunekle;
}

class depourunekle : public QDialog
{
    Q_OBJECT

public:
    explicit depourunekle(QWidget *parent = nullptr);
    ~depourunekle();

private slots:
    void on_pushButton_tamam_clicked();

    void on_pushButton_iptal_clicked();

private:
    Ui::depourunekle *ui;
    QSqlDatabase mydb;
};

#endif // DEPOURUNEKLE_H
