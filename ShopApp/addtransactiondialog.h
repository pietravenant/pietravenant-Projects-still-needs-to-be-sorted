#ifndef ADDTRANSACTIONDIALOG_H
#define ADDTRANSACTIONDIALOG_H
#include "datastore.h"
#include "transaction.h"
#include "customer.h"
#include "item.h"

#include <QDialog>
#include <QDebug>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>


class AddTransactionDialog : public QDialog
{
    Q_OBJECT
public:
    AddTransactionDialog(DataStore* dataStore, QWidget *parent = nullptr);
    void accept();

private slots:
    void updateItemTypeLabel(int index);

private:
    QLabel *labelHeader;
    QLabel *labelSelectCustomer;
    QLabel *labelSelectItem;
    QLabel *labelItemType;
    QLabel *labelItemUpdateType;
    QLabel *labelQuantity;

    QComboBox *comboBoxSelectCustomer;
    QComboBox *comboBoxSelectItem;

    QPushButton *btnClearItem;
    QPushButton *btnAddTransaction;
    QPushButton *btnCancel;

    QSpinBox *spinBoxQuantity;

    QVBoxLayout *layoutMain;
    QHBoxLayout *layoutCustomer;
    QHBoxLayout *layoutItem;
    QHBoxLayout *layoutType;
    QHBoxLayout *layoutQuantity;
    QHBoxLayout *layoutButtons;

    void clearAll();

    DataStore* dataStore;
    QMap<QString, Item::ItemType> itemTypes;

};

#endif // ADDTRANSACTIONDIALOG_H
