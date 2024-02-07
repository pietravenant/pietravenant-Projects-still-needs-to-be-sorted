#include "accountlist.h"
#include <QTextStream>
#include <QStringList>


void AccountList::addAccount(Account *a)
{
    this->append(a);
}

void AccountList::displayList() const
{
    foreach (Account *a, *this){
        qDebug().noquote() << a->toString() << Qt::endl <<Qt::endl;
    }
}

void AccountList::displayAccounts(QDate q) const
{
    int i =0;
    foreach (Account *a,*this)
    {
        QList<Transaction> listOfTransactions = a->getTransactions();
        foreach (Transaction t,listOfTransactions)
        {
            if(t.getDate() == q)
            {
                qInfo() << a->getAccountNo();
                i++;
            }
        }

    }
    if(i==0){
        qInfo() << "There was no Transaction on the date";
    }

}

int AccountList::countAccounts(double d)
{
    int count = 0;
    foreach (Account *a,*this){
        if (a->getBalance() > d){
            count += 1;
        }
    }
    return count;
}

void AccountList::deleteAll()
{
        qDeleteAll(*this);
}


