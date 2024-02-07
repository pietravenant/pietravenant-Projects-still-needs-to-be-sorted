#ifndef CHEQUE_H
#define CHEQUE_H

#include "account.h"

class Cheque : public Account
{
public:
    Cheque(QString a,Customer c,double o);
    bool withdraw(double d);
    QString toString() const;

private:
    double m_Overdraft;
};

#endif // CHEQUE_H
