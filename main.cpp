#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test =c.CreateConnection();
    MainWindow w;
    if (test){
        //qDebug()<<"connection succeed";
        w.show();
        QMessageBox::information(nullptr,QObject::tr("DataBases open"),
                                 QObject::tr("Connection successful \n"
                                              "click OK to exit"),QMessageBox::Ok);

    }
    else {
        //qDebug ()<<"connection failed";
        QMessageBox::critical(nullptr,QObject::tr("DataBases is not open"),
                                 QObject::tr("Connection failed! \n"
                                              "click Cancel to exit"),QMessageBox::Cancel);
    }
    return a.exec();
}
