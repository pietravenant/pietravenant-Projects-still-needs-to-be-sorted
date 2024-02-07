#include "savings.h"
const double Savings::INTEREST = 4.5;

Savings::Savings(QString a, Customer c): Account(a,c)
{
}

bool Savings::withdraw(double d)
{
        if(getBalance() >=d){
            double newBalance = getBalance() -d;
            m_Balance = newBalance;
            Transaction t("Account withdrawal with the amount of " + QString::number(d,'f',2),QDate::currentDate());
            m_Transactions.append(t);
            return true;
        }
        else
            return false;

}

QString Savings::toString() const
{
    return Account::toString() + "\nInterest rate:\t" + QString::number(INTEREST,'f',2);
}

