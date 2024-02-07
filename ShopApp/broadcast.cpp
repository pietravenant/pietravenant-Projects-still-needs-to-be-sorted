#include "broadcast.h"

Broadcast::Broadcast(DataStore *dataStore, QObject *parent)
    :dataStore(dataStore),QThread{parent}
{
    udpSocket = new QUdpSocket(this);
}

void Broadcast::sendData(const QString &xmlData)
{
    QByteArray data = xmlData.toUtf8();

        QHostAddress broadcastAddress(QHostAddress::Broadcast);
        quint16 port = 12345;
        udpSocket->writeDatagram(data, broadcastAddress, port);
}

QString Broadcast::createXmlData()
{
    QDomDocument xmlDocument;
    xmlDocument.setContent(QString("<?xml version=\"1.0\" encoding=\"UTF-8\"?>"));

    QDomElement rootElement = xmlDocument.createElement("ShopData");
    xmlDocument.appendChild(rootElement);

    // Group transactions by customer using dataStore
    QMap<QString, QList<Transaction>> transactionsByCustomer;

    const QList<Transaction> &transactions = dataStore->getTransactions(); // Get transactions from dataStore

    for (const Transaction &transaction : transactions) {
        transactionsByCustomer[transaction.getCustomerName()].append(transaction);
    }

    // Iterate through customers and their transactions
    for (const QString &customerName : transactionsByCustomer.keys()) {
        QDomElement customerElement = xmlDocument.createElement("Customer");
        customerElement.setAttribute("name", customerName);
        rootElement.appendChild(customerElement);

        const QList<Transaction> &customerTransactions = transactionsByCustomer[customerName];

        for (const Transaction &transaction : customerTransactions) {
            QDomElement transactionElement = xmlDocument.createElement("transaction");
            transactionElement.setAttribute("date", transaction.getDateTime().toString());
            customerElement.appendChild(transactionElement);

            QDomElement itemElement = xmlDocument.createElement("Item");
            itemElement.setAttribute("type", transaction.getTypeString());
            itemElement.setAttribute("Name", transaction.getItemName());
            itemElement.setAttribute("Quantity", QString::number(transaction.getQuantity()));
            transactionElement.appendChild(itemElement);
        }
    }

    QString xmlData = xmlDocument.toString(4);

    return xmlData;
}

void Broadcast::run()
{
    //continuously broadcast data
    while (!isInterruptionRequested()) {
            QString xmlData = createXmlData();
            sendData(xmlData);
            msleep(1000); // Sleep for 1 second (adjust as needed)
        }
}

