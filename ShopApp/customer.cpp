#include "customer.h"

Customer::Customer(const QString &name)
    : name(name)
{
    qInfo() << "CustomerAdded---Name: " << name ;
}

QString Customer::getName() const
{
    return name;
}

void Customer::setName(const QString &newName)
{
    name = newName;
}

