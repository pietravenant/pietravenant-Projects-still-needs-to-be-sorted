#ifndef PRODUCTLIST_H
#define PRODUCTLIST_H

#include <QObject>


class ProductList : public QObject
{
    Q_OBJECT
public:
    explicit ProductList(QObject *parent = nullptr);
//    int add(Product *p);
    void sell(int pc, int n);
    void remove(int pc);
    void deleteAll();
    bool codeUsed(int pc);


signals:

};

#endif // PRODUCTLIST_H
