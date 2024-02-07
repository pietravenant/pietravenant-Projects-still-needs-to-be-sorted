#include "item.h"

Item::Item(const QString &name, ItemType type)
    : name(name) , type(type)
{
    qInfo() << "Item has been added ---- Name: " << name << " Type: " << type;
}

QString Item::getName() const {
    return name;
}

void Item::setName(const QString &newName)
{
    name = newName;
}

Item::ItemType Item::getType() const
{
    return type;
}

QString Item::getTypeString() const
{
    switch (type) {
        case Books:
            return "Books";
        case Magazines:
            return "Magazines";
        default:
            return "Books";
    }
}

