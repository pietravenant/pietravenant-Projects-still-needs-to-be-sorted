#include "cheque.h"


Cheque::Cheque(QString a, Customer c, double o) : Account(a,c) , m_Overdraft(o)
{
}

bool Cheque::withdraw(double d)
{
    if((getBalance() + m_Overdraft) >=d)
    {
        double newBalance = getBalance() -d;
        m_Balance = newBalance;
       Transaction t("Account withdrawal with the amount of " + QString::number(d,'f',2),QDate::currentDate());
       m_Transactions.append(t);
       return true;
    }
    else{
        return false;
    }

}

QString Cheque::toString() const
{
    return Account::toString() + "\nOverdraft:\t" + QString::number(m_Overdraft,'f',2);
};
