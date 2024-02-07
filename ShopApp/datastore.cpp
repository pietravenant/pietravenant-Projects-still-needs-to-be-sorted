#include "datastore.h"

DataStore::DataStore()
{

}
QList<Customer>& DataStore::getCustomers() {
    return customers;
}

QList<Transaction>& DataStore::getTransactions() {
    return transactions;
}

QList<Item>& DataStore::getItems() {
    return items;
}

void DataStore::addCustomer(const Customer &customer)
{
    customers.append(customer);
    qInfo() << "A Customer has been added to the DataStore";
}

void DataStore::addItem(const Item &item)
{
    items.append(item);
    qInfo() << "A Item has been added to the DataStore";
}

void DataStore::addTransaction(const Transaction &transaction)
{
    transactions.append(transaction);
    qInfo() << "A Transactions has been added to the DataStore";
}

void DataStore::clear()
{
    customers.clear();
    transactions.clear();
    items.clear();
}

