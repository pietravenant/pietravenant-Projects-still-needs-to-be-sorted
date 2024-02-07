#ifndef BROADCAST_H
#define BROADCAST_H

#include "datastore.h"
#include <QThread>
#include <QtNetwork\QUdpSocket>
#include <QDomDocument>

class Broadcast : public QThread
{
    Q_OBJECT
public:
    explicit Broadcast(DataStore* dataStore,QObject *parent = nullptr);
    void sendData(const QString &xmlData);
    QString createXmlData();

protected:
    void run();
private:
    QUdpSocket *udpSocket;
    DataStore* dataStore;

};

#endif // BROADCAST_H
