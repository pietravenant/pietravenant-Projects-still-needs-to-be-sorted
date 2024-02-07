#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork\QUdpSocket>
#include <QTextEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void processPendingDatagrams();

private:
    QUdpSocket *udpSocket;
    QTextEdit *textEdit;

};
#endif // MAINWINDOW_H
