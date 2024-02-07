#include "customer.h"
#include <iostream>
#include <QList>


Customer::Customer(QString n, QString i) : m_Name(n), m_Id(i)
{
}

QString Customer::toString() const
{
      return "Customer Name:\t" + m_Name + "\nCustomer ID:\t" + m_Id;

}


