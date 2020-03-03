#ifndef PASTANE_H
#define PASTANE_H

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
class pastane;
}

class pastane : public QDialog
{
    Q_OBJECT

public:
    explicit pastane(QWidget *parent = nullptr);
    ~pastane();

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_table_cellChanged(int row, int column);

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::pastane *ui;
    QSqlDatabase mydb;

    bool loading;

    void FillTable();
};

#endif // PASTANE_H
