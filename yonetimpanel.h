#ifndef YONETIMPANEL_H
#define YONETIMPANEL_H

#include <QDialog>

namespace Ui {
class yonetimpanel;
}

class yonetimpanel : public QDialog
{
    Q_OBJECT

public:
    explicit yonetimpanel(QWidget *parent = nullptr);
    ~yonetimpanel();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::yonetimpanel *ui;
};

#endif // YONETIMPANEL_H
