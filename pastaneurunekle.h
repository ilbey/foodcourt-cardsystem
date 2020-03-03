#ifndef PASTANEURUNEKLE_H
#define PASTANEURUNEKLE_H

#include <QDialog>

#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

namespace Ui {
class pastaneurunekle;
}

class pastaneurunekle : public QDialog
{
    Q_OBJECT

public:
    explicit pastaneurunekle(QWidget *parent = nullptr);
    ~pastaneurunekle();

private slots:
    void on_pushButton_tamam_clicked();

    void on_pushButton_iptal_clicked();

private:
    Ui::pastaneurunekle *ui;
    QSqlDatabase mydb;
};

#endif // PASTANEURUNEKLE_H
