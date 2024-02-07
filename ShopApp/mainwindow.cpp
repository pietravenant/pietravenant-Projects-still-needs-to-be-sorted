#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Create an instance of DataStore
    dataStore = new DataStore();

    //    create a new item
    Item newItem("To Kill a Mockingbird", Item::Books);
    dataStore->addItem(newItem);
    Item newItem2("1984 by George Orwell", Item::Books);
    dataStore->addItem(newItem2);
    Item newItem3("Pride and Prejudice", Item::Books);
    dataStore->addItem(newItem3);
    Item newItem4("National Geographic", Item::Magazines);
    dataStore->addItem(newItem4);
    Item newItem5("The New Yorker", Item::Magazines);
    dataStore->addItem(newItem5);
    Item newItem6("Time", Item::Magazines);
    dataStore->addItem(newItem6);

    // Create a new Customer
    Customer newCustomer("Sipho");
    dataStore->addCustomer(newCustomer);
    Customer newCustomer2("Christopher");
    dataStore->addCustomer(newCustomer2);
    Customer newCustomer3("Jessica");
    dataStore->addCustomer(newCustomer3);
    Customer newCustomer4("Daniel");
    dataStore->addCustomer(newCustomer4);
    Customer newCustomer5("Sarah");
    dataStore->addCustomer(newCustomer5);

    setWindowTitle("Shop");
    resize(500, 400);

    QIcon icon(":/images/shop1.png");
    setWindowIcon(icon);

    // Widgets
    exitAction = new QAction(tr("E&xit"), this);
    addCustomer= new QAction(QIcon(":/images/001-user-app.png"),tr("Add &Customer"), this);
    addItem = new QAction(QIcon(":/images/005-shopping-cart"),tr("Add &Item"), this);
    addTransaction = new QAction(QIcon(":/images/006-buy"),tr("Add &Transaction"), this);
    openAction = new QAction(QIcon(":/images/003-open-folder"),tr("&Open"), this);
    saveAction = new QAction(QIcon(":/images/002-data-storage"),tr("&Save"), this);
    clearAllAction = new QAction(QIcon(":/images/delete"),tr("&Clear"), this);
    restoreAction = new QAction(tr("&Restore"), this);
    backupAction = new QAction(tr("&Backup"), this);
    settingAction = new QAction(tr("&Settings"), this);
    contactAction = new QAction(tr("Contact"), this);
    aboutAction = new QAction(tr("About"), this);
    updatesAction = new QAction(tr("Check for Updates"), this);

    // Signals
    connect(openAction, &QAction::triggered, this, &MainWindow::openDataAction);
    connect(saveAction, &QAction::triggered, this, &MainWindow::saveDataAction);
    connect(exitAction, &QAction::triggered, this, &MainWindow::exitApplication);
    connect(addCustomer, &QAction::triggered, this, &MainWindow::addCustomerAction);
    connect(addItem, &QAction::triggered, this, &MainWindow::addItemAction);
    connect(addTransaction, &QAction::triggered, this, &MainWindow::addTransactionAction);
    connect(clearAllAction, &QAction::triggered, this, &MainWindow::clearAll);
    connect(restoreAction, &QAction::triggered, this, &MainWindow::restoreStoreAction);
    connect(backupAction, &QAction::triggered, this, &MainWindow::backupStoreAction);
    connect(settingAction, &QAction::triggered, this, &MainWindow::settingsAction);
    connect(contactAction, &QAction::triggered, this, &MainWindow::showContactAction);
    connect(aboutAction, &QAction::triggered, this, &MainWindow::showAboutAction);
    connect(updatesAction, &QAction::triggered, this, &MainWindow::showUpdatesAction);

    // File menu
    fileMenu = menuBar()->addMenu(tr("File"));
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addSeparator();
    fileMenu->addAction(clearAllAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);
    fileMenu = menuBar()->addMenu(tr("Add"));
    fileMenu->addAction(addCustomer);
    fileMenu->addAction(addItem);
    fileMenu->addAction(addTransaction);
    fileMenu = menuBar()->addMenu(tr("Tools"));
    fileMenu->addAction(backupAction);
    fileMenu->addAction(restoreAction);
    fileMenu->addSeparator();
    fileMenu->addAction(settingAction);
    fileMenu = menuBar()->addMenu(tr("Help"));
    fileMenu->addAction(contactAction);
    fileMenu->addAction(aboutAction);
    fileMenu->addSeparator();
    fileMenu->addAction(updatesAction);

    // Assign keyboard shortcuts
    exitAction->setShortcut(QKeySequence(tr("Ctrl+Q")));
    addCustomer->setShortcut(QKeySequence(tr("Ctrl+C")));
    addItem->setShortcut(QKeySequence(tr("Ctrl+I")));
    addTransaction->setShortcut(QKeySequence(tr("Ctrl+T")));
    openAction->setShortcut(QKeySequence(tr("Ctrl+O")));
    saveAction->setShortcut(QKeySequence(tr("Ctrl+S")));
    clearAllAction->setShortcut(QKeySequence(tr("Ctrl+L")));
    restoreAction->setShortcut(QKeySequence(tr("Ctrl+R")));
    backupAction->setShortcut(QKeySequence(tr("Ctrl+B")));
    settingAction->setShortcut(QKeySequence(tr("Alt+S")));

    // Create a toolbar
    QToolBar *toolbar = addToolBar(tr("Toolbar"));
    toolbar->addAction(openAction);
    toolbar->addAction(saveAction);
    toolbar->addAction(clearAllAction);
    toolbar->addAction(addCustomer);
    toolbar->addAction(addItem);
    toolbar->addAction(addTransaction);

    // Create the QTreeView
    treeView = new QTreeView(this);
    model = new QStandardItemModel(this);
    treeView->setModel(model);
    setCentralWidget(treeView);
    updateTree();

    //Start the Broadcast
    broadcast = new Broadcast(dataStore, this);
    broadcast->start();
}

MainWindow::~MainWindow()
{
    delete dataStore;
}

void MainWindow::updateTree()
{
    model->clear();
    model->setColumnCount(3);
    model->setHorizontalHeaderLabels(QStringList() << "Transaction" << "Type" << "Quantity");
    treeView->setColumnWidth(0, 200);

    QMap<QString, QList<Transaction>> transactionsByCustomer;
    QList<Transaction>& transactions = dataStore->getTransactions();

    // Group by customer
    for (const Transaction &transaction : transactions) {
        transactionsByCustomer[transaction.getCustomerName()].append(transaction);
    }

    QStandardItem *rootItem = model->invisibleRootItem();

    for (const QString &customerName : transactionsByCustomer.keys()) {
        const QList<Transaction> &customerTransactions = transactionsByCustomer[customerName];

        // Customer grouping
        QStandardItem *customerItem = new QStandardItem("Customer: " + customerName);

        for (const Transaction &transaction : customerTransactions) {
            QStandardItem *dateTimeItem = new QStandardItem(transaction.getDateTime().toString());
            QStandardItem *itemNameItem = new QStandardItem(transaction.getItemName());
            QStandardItem *itemTypeItem = new QStandardItem(transaction.getTypeString());
            QStandardItem *quantityItem = new QStandardItem(QString::number(transaction.getQuantity()));
            QList<QStandardItem *> itemRow;
            itemRow << itemNameItem << itemTypeItem << quantityItem;
            dateTimeItem->appendRow(itemRow);
            customerItem->appendRow(dateTimeItem);
        }
        rootItem->appendRow(customerItem);
        treeView->expandAll();
    }
}

void MainWindow::saveDataToFile(const QString &fileName) {

    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);

        xmlWriter.writeStartDocument();
        xmlWriter.writeStartElement("ShopData");

        // Save Customers
        xmlWriter.writeStartElement("Customers");
        const QList<Customer> &customers = dataStore->getCustomers();
        for (const Customer &customer : customers) {
            xmlWriter.writeStartElement("Customer");
            xmlWriter.writeAttribute("name", customer.getName());
            xmlWriter.writeEndElement();
        }
        xmlWriter.writeEndElement();

        // Save Items
        xmlWriter.writeStartElement("Items");
        const QList<Item> &items = dataStore->getItems();
        for (const Item &item : items) {
            xmlWriter.writeStartElement("Item");
            xmlWriter.writeAttribute("name", item.getName());
            xmlWriter.writeAttribute("type", QString::number(static_cast<int>(item.getType())));
            xmlWriter.writeEndElement();
        }
        xmlWriter.writeEndElement();

        // Save Transactions
        xmlWriter.writeStartElement("Transactions");
        const QList<Transaction> &transactions = dataStore->getTransactions();
        for (const Transaction &transaction : transactions) {
            xmlWriter.writeStartElement("Transaction");
            xmlWriter.writeAttribute("date", transaction.getDateTime().toString());
            xmlWriter.writeAttribute("itemName", transaction.getItemName());
            xmlWriter.writeAttribute("itemType", QString::number(static_cast<int>(transaction.getItemType())));
            xmlWriter.writeAttribute("quantity", QString::number(transaction.getQuantity()));
            xmlWriter.writeAttribute("customerName", transaction.getCustomerName());
            xmlWriter.writeEndElement();
        }
        xmlWriter.writeEndElement();
        xmlWriter.writeEndElement();
        xmlWriter.writeEndDocument();

        file.close();
        QMessageBox::information(this, "Save", "Database has been saved");
    } else {
       qDebug() << "Failed to open file for writing.";
    }
}

void MainWindow::saveDataAction()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save Data File", "", "Data Files (*.txt);;All Files (*)");
    saveDataToFile(fileName);

}

void MainWindow::openDataAction()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Data File", "", "Data Files (*.txt);;All Files (*)");
    openDataFromFile(fileName);
}

void MainWindow::openDataFromFile(const QString &fileName) {

    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QDomDocument xmlDocument;
        if (xmlDocument.setContent(&file)) {

            dataStore->clear();

            QDomElement rootElement = xmlDocument.documentElement();

            // Load Customers
            QDomElement customersElement = rootElement.firstChildElement("Customers");
            QDomNodeList customerNodes = customersElement.elementsByTagName("Customer");
            for (int i = 0; i < customerNodes.size(); ++i) {
                QDomElement customerElement = customerNodes.at(i).toElement();
                QString customerName = customerElement.attribute("name");
                dataStore->addCustomer(Customer(customerName));
            }

            // Load Items
            QDomElement itemsElement = rootElement.firstChildElement("Items");
            QDomNodeList itemNodes = itemsElement.elementsByTagName("Item");
            for (int i = 0; i < itemNodes.size(); ++i) {
                QDomElement itemElement = itemNodes.at(i).toElement();
                QString itemName = itemElement.attribute("name");
                int itemType = itemElement.attribute("type").toInt();
                dataStore->addItem(Item(itemName, static_cast<Item::ItemType>(itemType)));
            }

            // Load Transactions
            QDomElement transactionsElement = rootElement.firstChildElement("Transactions");
            QDomNodeList transactionNodes = transactionsElement.elementsByTagName("Transaction");
            for (int i = 0; i < transactionNodes.size(); ++i) {
                QDomElement transactionElement = transactionNodes.at(i).toElement();
                QDateTime dateTime = QDateTime::fromString(transactionElement.attribute("date"));
                QString itemName = transactionElement.attribute("itemName");
                int itemType = transactionElement.attribute("itemType").toInt();
                int quantity = transactionElement.attribute("quantity").toInt();
                QString customerName = transactionElement.attribute("customerName");
                dataStore->addTransaction(Transaction(customerName, dateTime, itemName, static_cast<Item::ItemType>(itemType), quantity));

            }

            file.close();
            QMessageBox::information(this, "Open", "Database has been opened");
            updateTree();

        } else {

            qDebug() << "Failed to XML content.";
        }
    } else {

        qDebug() << "Failed to open file for reading.";
    }

}

void MainWindow::backup(const QString action)
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString dateTimeString = currentDateTime.toString("yy-MM-dd-HH'H'mm-ss");
    QString folderPath = "backup";
    QString fileName = "backup/Backup-";
    QDir().mkpath(folderPath);
    fileName.append(dateTimeString);
    fileName.append("-");
    fileName.append(action);
    fileName.append(".txt");
    saveDataToFile(fileName);
    qInfo() << "Backup created: " << fileName;

}

void MainWindow::exitApplication()
{
    QApplication::quit();
}

void MainWindow::addItemAction()
{
    qInfo() << "Add Item Dialog is called";
    AddItemDialog addItemDialog(dataStore, this);
    int result = addItemDialog.exec();

    if (result == QDialog::Accepted) {
        updateTree();
        backup("Customer_Added");
    }

}

void MainWindow::addCustomerAction()
{
    qInfo() << "Add Customer Dialog is called";
    AddCustomerDialog addCustomreDialog(dataStore, this);
    int result = addCustomreDialog.exec();

    if (result == QDialog::Accepted) {
        updateTree();
        backup("Customer_Added");
    }

}

void MainWindow::clearAll()
{
    dataStore->clear();
    updateTree();
}

void MainWindow::addTransactionAction()
{
    AddTransactionDialog addtransactiondialog(dataStore, this);
    int result = addtransactiondialog.exec();

    if (result == QDialog::Accepted) {
        updateTree();
        backup("Transaction_Added");
    }
}

void MainWindow::restoreStoreAction()
{
    qInfo() << "Add Restore Dialog is called";

    QString folderPath = "backup";
    QDir backupDir(folderPath);

    QStringList filters;
    filters << "*.txt";
    backupDir.setNameFilters(filters);

    QStringList backupFiles = backupDir.entryList();

    if (backupFiles.isEmpty()) {
        QMessageBox::information(this, "Restore", "No backup files found.");
        return;
    }

    // Create a dialog to select a backup file
    QDialog dialog(this);
    dialog.setWindowTitle("Select a Backup File");

    QVBoxLayout layout(&dialog);
    QComboBox backupComboBox(&dialog);
    backupComboBox.addItems(backupFiles);

    QPushButton restoreButton("Restore", &dialog);
    QPushButton cancelButton("Cancel", &dialog);

    layout.addWidget(&backupComboBox);
    layout.addWidget(&restoreButton);
    layout.addWidget(&cancelButton);

    connect(&restoreButton, &QPushButton::clicked, &dialog, &QDialog::accept);
    connect(&cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);


    if (dialog.exec() == QDialog::Accepted) {
       QString selectedBackupFile = "backup/" + backupComboBox.currentText();

        qInfo() << "Selected backup file: " << selectedBackupFile;
        openDataFromFile(selectedBackupFile);
        updateTree();
        QMessageBox::information(this, "Restore", "Database has been Restore");
    }
}

void MainWindow::backupStoreAction()
{
    qInfo() << "Add Backup is called";
    backup("Backup");
    QMessageBox::information(this, "Backup", "Backup Has been made");
}

void MainWindow::settingsAction()
{
    qInfo() << "Settings is called";
    QMessageBox::critical(this, "Settings", "The Settings is behind a Paywall");
}

void MainWindow::showContactAction()
{
    QMessageBox::information(this, "Contact", "Email me on 48780715@mylife.unisa.ac.za");
}

void MainWindow::showAboutAction()
{
    QMessageBox::information(this, "About", "This is the Work of Pieter Avenant, Student Number: 48780715");
}

void MainWindow::showUpdatesAction()
{
    QMessageBox::information(this, "Update", "There is no Updates available");
}

