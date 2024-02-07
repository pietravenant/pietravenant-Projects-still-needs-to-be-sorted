#include "addtransactiondialog.h"

AddTransactionDialog::AddTransactionDialog(DataStore* dataStore,QWidget *parent)
    : QDialog{parent}, dataStore(dataStore)
{
    setWindowTitle("Add Transaction");
    resize(300, 200);

    //itemTypes map with item names and types
    QList<Item> itemsT = dataStore->getItems();
    for (const Item& item : itemsT) {
        itemTypes[item.getName()] = item.getType();
    }

    //Layouts
    layoutMain = new QVBoxLayout(this);
    layoutCustomer = new QHBoxLayout();
    layoutItem = new QHBoxLayout();
    layoutType = new QHBoxLayout();
    layoutQuantity = new QHBoxLayout();
    layoutButtons = new QHBoxLayout();

    //Widgets
    labelHeader = new QLabel("Complete the required data", this);
    labelSelectCustomer = new QLabel("Select the customer", this);
    labelSelectItem = new QLabel("Select the item", this);
    labelItemType = new QLabel("Item type", this);
    labelItemUpdateType = new QLabel(" ", this);
    labelQuantity = new QLabel("Item quantity", this);
    comboBoxSelectCustomer = new QComboBox(this);
    comboBoxSelectItem = new QComboBox(this);
    btnAddTransaction = new QPushButton("Add Transaction", this);
    btnClearItem = new QPushButton("Clear", this);
    btnCancel = new QPushButton("Cancel", this);
    spinBoxQuantity = new QSpinBox(this);

    QList<Customer> customers = dataStore->getCustomers();
    for (const Customer& customer : customers) {
        comboBoxSelectCustomer->addItem(customer.getName());
    }

    QList<Item> items = dataStore->getItems();
    for (const Item& item : items) {
        comboBoxSelectItem->addItem(item.getName(), QVariant(static_cast<int>(item.getType())));
    }

    // Add widgets to the main layout
    layoutMain->addWidget(labelHeader);
    layoutCustomer->addWidget(labelSelectCustomer);
    layoutCustomer->addWidget(comboBoxSelectCustomer);
    layoutMain->addLayout(layoutCustomer);
    layoutItem->addWidget(labelSelectItem);
    layoutItem->addWidget(comboBoxSelectItem);
    layoutMain->addLayout(layoutItem);
    layoutType->addWidget(labelItemType);
    layoutType->addWidget(labelItemUpdateType);
    layoutMain->addLayout(layoutType);
    layoutQuantity->addWidget(labelQuantity);
    layoutQuantity->addWidget(spinBoxQuantity);
    layoutMain->addLayout(layoutQuantity);
    layoutButtons->addWidget(btnAddTransaction);
    layoutButtons->addWidget(btnClearItem);
    layoutButtons->addWidget(btnCancel);
    layoutMain->addLayout(layoutButtons);
    setLayout(layoutMain);

    comboBoxSelectCustomer->setFocus();

    // Set the tab order
    setTabOrder(comboBoxSelectCustomer, comboBoxSelectItem);
    setTabOrder(comboBoxSelectItem, spinBoxQuantity);
    setTabOrder(spinBoxQuantity, btnAddTransaction);
    setTabOrder(btnAddTransaction, btnClearItem);
    setTabOrder(btnCancel, btnCancel);

    updateItemTypeLabel(0);

    //Signals
    connect(btnAddTransaction, &QPushButton::clicked, this, &AddTransactionDialog::accept);
    connect(btnClearItem, &QPushButton::clicked, this, &AddTransactionDialog::clearAll);
    connect(btnCancel, &QPushButton::clicked, this, &AddTransactionDialog::reject);
    connect(comboBoxSelectItem, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &AddTransactionDialog::updateItemTypeLabel);
}

void AddTransactionDialog::accept()
{
    QString selectedCustomer = comboBoxSelectCustomer->currentText();
    QString selectedItem = comboBoxSelectItem->currentText();
    Item::ItemType itemType = static_cast<Item::ItemType>(comboBoxSelectItem->currentData().toInt());
    int quantity = spinBoxQuantity->value();

    // Create a new Item instance
    Transaction newTransaction(selectedCustomer,QDateTime::currentDateTime(),selectedItem,itemType,quantity);
    dataStore->addTransaction(newTransaction);
    QMessageBox::information(this, "Transaction", "Transaction has been Added");
    QDialog::accept();
}

void AddTransactionDialog::updateItemTypeLabel(int index)
{

    QString selectedItem = comboBoxSelectItem->currentText();

    // Look up the item type in the itemTypes map
    Item::ItemType itemType = itemTypes.value(selectedItem, Item::Books);
    Item selectedItemInstance(selectedItem, itemType);
    labelItemUpdateType->setText(selectedItemInstance.getTypeString());
}

void AddTransactionDialog::clearAll()
{
    comboBoxSelectCustomer->setCurrentIndex(0);
    comboBoxSelectItem->setCurrentIndex(0);
    labelItemUpdateType->setText("");
    spinBoxQuantity->setValue(0);
}
