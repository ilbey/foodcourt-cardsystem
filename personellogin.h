#ifndef PERSONELLOGIN_H
#define PERSONELLOGIN_H

#include <QDialog>

#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

namespace Ui {
class personellogin;
}

class personellogin : public QDialog
{
    Q_OBJECT

public:
    explicit personellogin(QWidget *parent = nullptr);
    ~personellogin();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::personellogin *ui;
    QSqlDatabase mydb;
};

#endif // PERSONELLOGIN_H
