#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QObject>
#include <QList>
#include "transaction.h"
#include "customer.h"

class Account
{
public:
    Account(QString a, Customer c);
    void deposit(double d);
    virtual bool withdraw(double d) = 0;
    QString toString() const;
    QList<Transaction> getTransactions() const;
    double getBalance() const;
    QString getAccountNo() const;
    ~Account();

private:
    QString m_AccountNo;
    Customer m_AccHolder;

protected:
    double m_Balance;
    QList<Transaction> m_Transactions;
};

#endif // ACCOUNT_H
