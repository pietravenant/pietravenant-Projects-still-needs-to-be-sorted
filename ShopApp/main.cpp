#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create a splash screen
    QPixmap splashImage(":/images/shop1.png");
    QSplashScreen splash(splashImage);
    splash.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    splash.show();

    // Create a timer
    QTimer timer;
    timer.setInterval(3000);
    timer.setSingleShot(true);
    timer.start();

    MainWindow w;

    //Timer's timeout signal
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        w.show();
        splash.close();
    });

    return a.exec();
}

