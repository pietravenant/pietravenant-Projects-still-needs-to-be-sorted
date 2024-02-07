#ifndef SAVINGS_H
#define SAVINGS_H

#include "account.h"

class Savings : public Account
{
public:
    Savings(QString a, Customer c);
    bool withdraw(double d);
    QString toString() const;
    static const double INTEREST;
};

#endif // SAVINGS_H
