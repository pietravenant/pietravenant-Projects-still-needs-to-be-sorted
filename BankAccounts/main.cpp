#include <QCoreApplication>
#include <QString>
#include <QDate>

#include "customer.h"
#include "transaction.h"
#include "account.h"
#include "savings.h"
#include "cheque.h"
#include "accountlist.h"


int main()
{
    Customer cus1("P Avenant" , "0001");
    Customer cus2("D Brand" , "0002");
    Customer cus3("K du Toit" , "0003");
    Customer cus4("J Schoombie" , "0004");
    Customer cus5("H Why" , "0005");

    Account *s1 = new Savings("s001",cus1);
    Account *s2 = new Savings("s002",cus2);
    Account *s3 = new Savings("s004",cus3);
    Account *c1 = new Cheque("c001",cus3,2000);
    Account *c2 = new Cheque("c002",cus4,1500);
    Account *c3 = new Cheque("c003",cus5,25000);


    AccountList AllAccounts;
    AllAccounts.addAccount(s1);
    AllAccounts.addAccount(s2);
    AllAccounts.addAccount(s3);
    AllAccounts.addAccount(c1);
    AllAccounts.addAccount(c2);
    AllAccounts.addAccount(c3);

    qInfo() << "----------------- Accounts with no Money in it ----------------------";
    AllAccounts.displayList();

    s1->deposit(1000);
    s2->deposit(2000);
    s3->deposit(3000);
    c1->deposit(4000);
    c2->deposit(5000);
    c3->deposit(6000);

    qInfo() << "----------------- Accounts after Deposits ----------------------";
    AllAccounts.displayList();

    s1->withdraw(500);
    c1->withdraw(1000);
    s2->withdraw(1618);
    c2->withdraw(1680);

    qInfo() << "----------------- Accounts after withdrawels ----------------------";
    AllAccounts.displayList();

    qInfo() << "\n";

    qInfo() << "----------------- Display all Accounts date(2022,07,29)----------------------";
    QDate date(2022,07,29);
    AllAccounts.displayAccounts(date);

     qInfo() << "\n";

    qInfo() << "----------------- Display all Accounts date(currentDate)----------------------";
    QDate date2(QDate::currentDate());
    AllAccounts.displayAccounts(date2);

    qInfo() << "\n";
    qInfo() << "----------------- Balances greater than 1000----------------------";
    qInfo() << "There is " << AllAccounts.countAccounts(1000) << " accounts with more than 1000";

    qInfo() << "\n";

    qInfo() << "----------------- Balances greater than 3000----------------------";
    qInfo() << "There is " << AllAccounts.countAccounts(3000) << " accounts with more than 3000";


    qInfo() << "\n";

    qInfo() << "----------------- Accounts Removed ----------------------";
    AllAccounts.deleteAll();
}
