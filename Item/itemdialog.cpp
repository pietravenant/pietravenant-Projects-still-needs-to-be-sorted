#include "itemdialog.h"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

ItemDialog::ItemDialog(QWidget * p, QString t, Item * i)
  : QDialog(p), item(NULL), barcodeLineEdit(new QLineEdit()), descriptionLineEdit(new QLineEdit()), stockSpinBox(new QSpinBox()), priceSpinBox(new QDoubleSpinBox())
{
    setWindowTitle(t);
    QGridLayout * layout = new QGridLayout();
    layout->addWidget(new QLabel("Barcode:"), 0, 0);
    layout->addWidget(barcodeLineEdit, 0, 1);
    layout->addWidget(new QLabel("Description:"), 1, 0);
    layout->addWidget(descriptionLineEdit, 1, 1);
    layout->addWidget(new QLabel("Stock:"), 2, 0);
    stockSpinBox->setMinimum(0);
    stockSpinBox->setMaximum(999);
    layout->addWidget(stockSpinBox, 2, 1);
    layout->addWidget(new QLabel("Price:"), 3, 0);
    priceSpinBox->setMinimum(0);
    priceSpinBox->setMaximum(9999);
    priceSpinBox->setDecimals(2);
    layout->addWidget(priceSpinBox, 3, 1);
    QPushButton * OKPushButton = new QPushButton("OK");
    layout->addWidget(OKPushButton, 4, 0);
    QPushButton * cancelPushButton = new QPushButton("Cancel");
    layout->addWidget(cancelPushButton, 4, 1);
    setLayout(layout);
    if (i != NULL) {
        barcodeLineEdit->setText(i->getBarcode());
        descriptionLineEdit->setText(i->getDescription());
        stockSpinBox->setValue(i->getStock());
        priceSpinBox->setValue(i->getPrice());
    }
    connect(cancelPushButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(OKPushButton, SIGNAL(clicked()), this, SLOT(fixItem()));
}

Item * ItemDialog::changeItem(QWidget * p, Item * i) {
    ItemDialog id(p, "Change Item", i);
    id.exec();
    return id.getItem();
}

Item * ItemDialog::addItem(QWidget * p) {
    ItemDialog id(p, "Add Item", NULL);
    id.exec();
    return id.getItem();
}

void ItemDialog::fixItem() {
    item = new Item(barcodeLineEdit->text(), descriptionLineEdit->text(), stockSpinBox->value(), priceSpinBox->value());
    close();
}

Item * ItemDialog::getItem() const {
    return item;
}
