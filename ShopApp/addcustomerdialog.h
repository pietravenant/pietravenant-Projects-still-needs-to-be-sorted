#ifndef ADDCUSTOMERDIALOG_H
#define ADDCUSTOMERDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QMessageBox>

#include "customer.h"
#include "datastore.h"

class AddCustomerDialog : public QDialog
{
    Q_OBJECT
public:
    AddCustomerDialog(DataStore* dataStore,QWidget *parent = nullptr);
    void accept();
signals:


private:
    QVBoxLayout *mainLayout;
    QHBoxLayout *customerLayout;
    QHBoxLayout *buttonLayout;

    QLabel *labelHeader;
    QLabel *labelAdd;
    QPushButton *btnCancel;

    QLineEdit *lineEditCustomer;
    QPushButton *btnAddCustomer;

    DataStore* dataStore;
};

#endif // ADDCUSTOMERDIALOG_H
