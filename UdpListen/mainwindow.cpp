#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("UDP Listener");
    resize(500, 400);

        textEdit = new QTextEdit(this);
        setCentralWidget(textEdit);

        //Configure the UDP socket
        udpSocket = new QUdpSocket(this);
        udpSocket->bind(QHostAddress::Any, 12345);
        connect(udpSocket, &QUdpSocket::readyRead, this, &MainWindow::processPendingDatagrams);
}

MainWindow::~MainWindow()
{
}

void MainWindow::processPendingDatagrams()
{
    textEdit->clear();

    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        QHostAddress senderAddress;
        quint16 senderPort;
        udpSocket->readDatagram(datagram.data(), datagram.size(), &senderAddress, &senderPort);
        textEdit->append(QString("Received from %1:%2: %3").arg(senderAddress.toString()).arg(senderPort).arg(QString(datagram)));
    }
}

