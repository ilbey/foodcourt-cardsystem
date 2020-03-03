#ifndef PERSONELEKLE_H
#define PERSONELEKLE_H

#include <QDialog>

#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

namespace Ui {
class personelekle;
}

class personelekle : public QDialog
{
    Q_OBJECT

public:
    explicit personelekle(QWidget *parent = nullptr);
    ~personelekle();

private slots:

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::personelekle *ui;
    QSqlDatabase mydb;
};

#endif // PERSONELEKLE_H

