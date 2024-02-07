#ifndef FOODPRODUCT_H
#define FOODPRODUCT_H

#include "product.h"

class FoodProduct : public Product
{
public:
    explicit FoodProduct(QObject *parent = nullptr);
    FoodProduct(QString d, int sc, int n, double p, QDate sbd);
    void sell(int n);
    QString toString;
    bool isExpired;


private:
    QDate m_SellByDate;
    int DISCOUNT;

};

#endif // FOODPRODUCT_H
