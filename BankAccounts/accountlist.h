#ifndef ACCOUNTLIST_H
#define ACCOUNTLIST_H

#include <QList>

#include "account.h"

class AccountList : public QList<Account*>
{
public:
    void addAccount(Account* a);
    void displayList() const;
    void displayAccounts(QDate q) const;
    int countAccounts(double d);
    void deleteAll();
};

#endif // ACCOUNTLIST_H
