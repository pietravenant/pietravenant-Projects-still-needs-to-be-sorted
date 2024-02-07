#ifndef ITEMDIALOG_H
#define ITEMDIALOG_H

#include "item.h"
#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>

class ItemDialog : public QDialog {
    Q_OBJECT
private:
    ItemDialog(QWidget * p, QString t, Item * i);
    Item * getItem() const;
public:
    static Item * changeItem(QWidget * p, Item * i);
    static Item * addItem(QWidget * p);
private:
    Item * item;
    QLineEdit * barcodeLineEdit;
    QLineEdit * descriptionLineEdit;
    QSpinBox * stockSpinBox;
    QDoubleSpinBox * priceSpinBox;
private slots:
    void fixItem();
};

#endif // ITEMDIALOG_H
