#include "additemdialog.h"

AddItemDialog::AddItemDialog(DataStore* dataStore, QWidget *parent)
    : QDialog{parent}, dataStore(dataStore)
{
    setWindowTitle("Add Item");
    resize(300, 150);

    //Layouts
    mainLayout = new QVBoxLayout(this);
    typeLayout = new QHBoxLayout();
    itemLayout = new QHBoxLayout();
    buttonLayout = new QHBoxLayout();

    //Widgets
    labelHeader = new QLabel("Complete the required data", this);
    labelType = new QLabel("Item Type:", this);
    labelItem = new QLabel("Name of item:", this);
    comboboxType = new QComboBox();
    comboboxType->addItem("Books", Item::Books);
    comboboxType->addItem("Magazines", Item::Magazines);
    lineEditName = new QLineEdit(this);
    btnAddItem = new QPushButton("Add item", this);
    btnCancel = new QPushButton("Cancel", this);

    // Add widgets to the main layout
    mainLayout->addWidget(labelHeader);
    typeLayout->addWidget(labelType);
    typeLayout->addWidget(comboboxType);
    itemLayout->addWidget(labelItem);
    itemLayout->addWidget(lineEditName);
    mainLayout->addLayout(typeLayout);
    mainLayout->addLayout(itemLayout);
    buttonLayout->addWidget(btnAddItem);
    buttonLayout->addWidget(btnCancel);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    comboboxType->setFocus();
    setTabOrder(comboboxType, lineEditName);
    setTabOrder(btnAddItem, btnCancel);

    //Signals
    connect(btnAddItem, &QPushButton::clicked, this, &AddItemDialog::accept);
    connect(comboboxType, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &AddItemDialog::handleComboboxSelection);
    connect(btnCancel, &QPushButton::clicked, this, &AddItemDialog::reject);
}


void AddItemDialog::accept()
{
    QString itemName = lineEditName->text();
    Item::ItemType itemType = static_cast<Item::ItemType>(comboboxType->currentData().toInt());

    if (itemName.isEmpty()) {
        QMessageBox::critical(this, "Error", "Please enter a valid item name.");
        return;
    }
    // Create a new Item instance
    Item newItem(itemName, itemType);
    dataStore->addItem(newItem);
    QMessageBox::information(this, "Item Added", "The Item has been Added");
    QDialog::accept();
}

void AddItemDialog::handleComboboxSelection(int index)
{
    Item::ItemType itemType = static_cast<Item::ItemType>(comboboxType->currentData().toInt());
}

