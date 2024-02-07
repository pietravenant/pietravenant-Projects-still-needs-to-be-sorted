#include "transaction.h"

Transaction::Transaction(const QString &customerName, const QDateTime &dateTime, const QString &itemName, Item::ItemType itemType, int quantity)
: customerName(customerName), dateTime(QDateTime::currentDateTime()), itemName(itemName), itemType(itemType), quantity(quantity)
{
    qInfo() << "Transaction has been added, Customer Name: " << customerName << "Date Time: " << dateTime;
    qInfo() << "Type: " << itemType << "Quantity: " << quantity << "Item Name: " << itemName;

}

QString Transaction::getCustomerName() const
{
    return customerName;
}

QString Transaction::getItemName() const
{
    return itemName;
}

int Transaction::getQuantity() const
{
    return quantity;
}

QDateTime Transaction::getDateTime() const
{
    return dateTime;
}

Item::ItemType Transaction::getItemType() const
{
    return itemType;
}

QString Transaction::getTypeString() const
{
    Item item("", itemType);
       return item.getTypeString();
}
