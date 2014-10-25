#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QTextCodec *linuxCodec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(linuxCodec);
    QTextCodec::setCodecForCStrings(linuxCodec);
    QTextCodec::setCodecForLocale(linuxCodec);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
