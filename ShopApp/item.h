#ifndef ITEM_H
#define ITEM_H

#include <QString>
#include <QList>
#include <QDebug>

class Item
{
public:
    enum ItemType {
        Books,
        Magazines,
    };

    Item(const QString& name, ItemType type);

    QString getName() const;
    void setName(const QString& newName);
    ItemType getType() const;
    QString getTypeString() const;

private:
    QString name;
    ItemType type;

};

#endif // ITEM_H
