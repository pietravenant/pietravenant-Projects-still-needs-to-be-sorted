#include "account.h"
#include <QTextStream>

Account::Account(QString a, Customer c) : m_AccountNo(a), m_AccHolder(c), m_Balance(0.0)
{
        Transaction t("Account opened",QDate::currentDate());
}

void Account::deposit(double d)
{
    m_Balance = m_Balance + d;
    Transaction t("Account received a Deposit of " + QString::number(d,'f',2),QDate::currentDate());
    m_Transactions.append(t);
}

QString Account::toString() const
{
    QString str;
    QTextStream accountStr(&str);
    accountStr << "ACCOUNT HOLDER\n" << m_AccHolder.toString()
                  << "\nAccount No:\t" << m_AccountNo
                  << "\nBalance:\t" << m_Balance
                  << "\nTRANSACTIONS \t";
    foreach (Transaction t, m_Transactions){
        accountStr << "\n" << t.toString();
    }
    return str;
}

QList<Transaction> Account::getTransactions() const
{
    return m_Transactions;
}

double Account::getBalance() const
{
    return m_Balance;
}

QString Account::getAccountNo() const
{
    return m_AccountNo;
}

Account::~Account()
{
    qInfo()<< "Deleted";
}


