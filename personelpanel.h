#ifndef PERSONELPANEL_H
#define PERSONELPANEL_H

#include <QDialog>

namespace Ui {
class personelpanel;
}

class personelpanel : public QDialog
{
    Q_OBJECT

public:
    explicit personelpanel(QWidget *parent = nullptr);
    ~personelpanel();

private:
    Ui::personelpanel *ui;
};

#endif // PERSONELPANEL_H
