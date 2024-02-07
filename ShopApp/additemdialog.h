#ifndef ADDITEMDIALOG_H
#define ADDITEMDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QMessageBox>

#include "item.h"
#include "datastore.h"

class AddItemDialog : public QDialog
{
    Q_OBJECT
public:
    AddItemDialog(DataStore* dataStore, QWidget *parent = nullptr);


private slots:
    void accept();
    void handleComboboxSelection(int index);

private:

    QVBoxLayout *mainLayout;
    QHBoxLayout *typeLayout;
    QHBoxLayout *itemLayout;
    QHBoxLayout *buttonLayout;

    QLabel *labelHeader;
    QLabel *labelType;
    QLabel *labelItem;

    QComboBox *comboboxType;
    QLineEdit *lineEditName;
    QPushButton *btnAddItem;
    QPushButton *btnCancel;

    DataStore* dataStore;

};

#endif // ADDITEMDIALOG_H
