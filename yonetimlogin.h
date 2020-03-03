#ifndef YONETIMLOGIN_H
#define YONETIMLOGIN_H
#include <QDialog>

#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

namespace Ui {
class yonetimlogin;
}

class yonetimlogin : public QDialog
{
    Q_OBJECT

public:
    explicit yonetimlogin(QWidget *parent = nullptr);
    ~yonetimlogin();

private slots:
    void on_buttonBox_accepted();


private:
    Ui::yonetimlogin *ui;
    QSqlDatabase mydb;
};

#endif // YONETIMLOGIN_H
