#include "mainwindow.h"
#include <QApplication>
/*
#include <QtCore/QCoreApplication>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>
*/


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}


/*
void Write(QString Filename){
    QFile mFile(Filename);
    if(!mFile.open(QFile::WriteOnly | QFile::Text)){
        qDebug() << "Could not open file for writting!";
        return;
    }
    QTextStream out(&mFile);
    out << "Hello World";
    mFile.flush();
    mFile.close();
}

void Read(QString Filename){
    QFile mFile(Filename);
    if(!mFile.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Could not open file for reading!";
        return;
    }
    QTextStream in(&mFile);
    QString mText = in.readAll();

    qDebug() << mText;

    mFile.flush();
    mFile.close();
}

int qmain(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString mFilename = "C:/Users/dataKeyVault.txt";
    Write(mFilename);
    Read(":/MyFiles/KeyVault.pro");

    return a.exec();
}
*/
