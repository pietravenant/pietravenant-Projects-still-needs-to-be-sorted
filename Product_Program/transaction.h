#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "product.h"

class Transaction : public Product
{
public:
    explicit Transaction(QObject *parent = nullptr);
    QString toString();

private:
    int m_NoOfItems;
    double m_PricePerItem;
    QDate m_TransactionDate;

};

#endif // TRANSACTION_H
