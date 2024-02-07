#include "transaction.h"

Transaction::Transaction(QString c, QDate d) :  m_Description(c), m_Date(d)
{
}

QString Transaction::toString() const
{
    return "Transaction:\t" + m_Description + "\tDate: " + m_Date.toString();
}

QDate Transaction::getDate() const
{
    return m_Date;
}
