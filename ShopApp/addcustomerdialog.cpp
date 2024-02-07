#include "addcustomerdialog.h"

AddCustomerDialog::AddCustomerDialog(DataStore* dataStore, QWidget *parent)
    : QDialog{parent}, dataStore(dataStore)
{
    setWindowTitle("Add Customer");
    resize(300, 150);

    //Layouts
    mainLayout = new QVBoxLayout(this);
    customerLayout = new QHBoxLayout();
    buttonLayout = new QHBoxLayout();

    //Widgets
    labelHeader = new QLabel("Complete the required data", this);
    labelAdd = new QLabel("Insert Name:", this);
    lineEditCustomer = new QLineEdit(this);
    btnAddCustomer = new QPushButton("Add Customer", this);
    btnCancel = new QPushButton("Cancel", this);

    // Add widgets to the main layout
    mainLayout->addWidget(labelHeader);
    customerLayout->addWidget(labelAdd);
    customerLayout->addWidget(lineEditCustomer);
    mainLayout->addLayout(customerLayout);
    buttonLayout->addWidget(btnAddCustomer);
    buttonLayout->addWidget(btnCancel);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    lineEditCustomer->setFocus();
    setTabOrder(lineEditCustomer, btnAddCustomer);
    setTabOrder(btnCancel, lineEditCustomer);

    //Signals
    connect(btnAddCustomer, &QPushButton::clicked, this, &AddCustomerDialog::accept);
    connect(btnCancel, &QPushButton::clicked, this, &AddCustomerDialog::reject);
}
void AddCustomerDialog::accept()
{
    QString customerName = lineEditCustomer->text();

    if (customerName.isEmpty()) {
        QMessageBox::critical(this, "Error", "Please enter a valid customer name.");
        return;
    }

    // Create a new Item instance
    Customer newCustomer(customerName);
    dataStore->addCustomer(newCustomer);
    QMessageBox::information(this, "Customer Added", "The Customer has been Added");
    QDialog::accept();
}
