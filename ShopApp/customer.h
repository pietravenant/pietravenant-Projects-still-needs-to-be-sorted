#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>
#include <QList>
#include <QDebug>


class Customer
{
public:
    Customer(const QString& name);

    QString getName() const;
    void setName(const QString &newName);

private:
    QString name;
};

#endif // CUSTOMER_H
