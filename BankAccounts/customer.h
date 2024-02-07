#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>

class Customer
{

public:
    Customer(QString n, QString i);
    QString toString() const;

private:
    QString m_Name;
    QString m_Id;

};

#endif // CUSTOMER_H
