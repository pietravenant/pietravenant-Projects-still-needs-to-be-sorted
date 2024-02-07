#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>
#include <QDate>
#include <QList>
#include "productlist.h"

class Product : public QObject
{
    Q_OBJECT
public:
    explicit Product(QObject *parent = nullptr);
    Product(QString d, int sc, int n, double p);
    void sell(int n);
    int getSupplierCode();
    void setProductCode(int pc);
    int getProductCode();
    virtual QString toString();
    void removeAll();
    bool isExpired();



private:
    QString m_Description;
    int m_SupplierCode;
    int m_NoOfitems;
    QDate m_DateSupplied;
    double m_PricePerItem;
    int m_ProductCode;
//    QList<Transaction> m_Transactions;

};

#endif // PRODUCT_H
