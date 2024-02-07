// DataStore.h
#ifndef DATASTORE_H
#define DATASTORE_H

#include <QList>
#include <QDebug>

#include "customer.h"
#include "transaction.h"
#include "item.h"

class DataStore {
public:
    DataStore();

    // Accessor methods to get the QLists
    QList<Customer>& getCustomers();
    QList<Transaction>& getTransactions();
    QList<Item>& getItems();

    // Methods
    void addCustomer(const Customer& customer);
    void addItem(const Item& item);
    void addTransaction(const Transaction& transaction);
    void clear();

private:
    QList<Customer> customers;
    QList<Transaction> transactions;
    QList<Item> items;
};

#endif // DATASTORE_H
