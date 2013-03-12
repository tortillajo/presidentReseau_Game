#include <QApplication>
#include "mainwindow.hpp"

int main(int argc, char *argv[])
{
    qDebug() << "Début du programme, " << QTime::currentTime().toString("HH:mm::ss");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
