#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QDate>

class Transaction
{
public:
    Transaction(QString c, QDate d);
    QString toString() const;
    QDate getDate() const;

private:
    QString m_Description;
    QDate m_Date;
};

#endif // TRANSACTION_H
