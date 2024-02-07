#ifndef ITEMLIST_H
#define ITEMLIST_H

#include "item.h"
#include <QString>
#include <QStringList>
#include <QMap>

class ItemList {
private:
    QMap<QString, Item*> list;
    bool changed;
public:
    ItemList();
    void readList(QString fname);
    void writeList(QString fname);
    bool getChanged() const;
    void addItem(const Item & i);
    bool removeItem(QString b);
    Item * findItem(QString b) const;
    QStringList toStringList() const;
    ~ItemList();
};

#endif // ITEMLIST_H
