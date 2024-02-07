#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QString>
#include <QDateTime>
#include "item.h"
#include <QDialog>

class Transaction
{
public:
    Transaction(const QString& customerName,const QDateTime& dateTime, const QString& itemName,Item::ItemType itemType, int quantity);

    QString getCustomerName() const;
    QString getItemName() const;
    int getQuantity() const;
    QDateTime getDateTime() const;
    Item::ItemType getItemType() const;
    QString getTypeString() const;

private:
    QDateTime dateTime;
    QString customerName;
    QString itemName;
    int quantity;
    Item::ItemType itemType;

};


#endif // TRANSACTION_H
