#include "itemlist.h"
#include "itemreader.h"
#include "itemwriter.h"

ItemList::ItemList() : changed(false) { }

void ItemList::readList(QString fname) {
    ItemReader iReader(fname);
    while (!iReader.endOfFile())
        addItem(iReader.readItem());
    changed = false;
}

void ItemList::writeList(QString fname) {
    ItemWriter iWriter(fname);
    foreach (Item * i, list.values())
        iWriter.writeItem(*i);
    changed = false;
}

bool ItemList::getChanged() const {
    return changed;
}

void ItemList::addItem(const Item & i) {
    if (list.contains(i.getBarcode())) {
        Item * j = list.value(i.getBarcode());
        j->setStock(j->getStock()+i.getStock());
    }
    else
        list.insert(i.getBarcode(), new Item(i));
    changed = true;
}

bool ItemList::removeItem(QString b) {
    bool result = list.remove(b) > 0;
    if (result)
        changed = true;
    return result;
}

Item * ItemList::findItem(QString b) const {
    if (list.contains(b))
        return list.value(b);
    else
        return NULL;
}

QStringList ItemList::toStringList() const {
    QStringList sList;
    foreach (Item * i, list.values())
        sList << i->toString();
    return sList;
}

ItemList::~ItemList() {
    qDeleteAll(list.values());
}
