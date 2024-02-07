#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QApplication>
#include <QTreeView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QFile>
#include <QDataStream>
#include <QDomDocument>
#include <QDomElement>
#include <QXmlStreamWriter>
#include <QFileDialog>
#include <QToolBar>

#include "addtransactiondialog.h"
#include "broadcast.h"
#include "additemdialog.h"
#include "addcustomerdialog.h"
#include "datastore.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateTree();
    void saveDataToFile(const QString &fileName);
    void openDataFromFile(const QString &fileName);
    void backup(const QString action);

private slots:
    void saveDataAction();
    void openDataAction();
    void addItemAction();
    void addCustomerAction();
    void clearAll();
    void exitApplication();
    void addTransactionAction();
    void restoreStoreAction();
    void backupStoreAction();
    void settingsAction();
    void showContactAction();
    void showAboutAction();
    void showUpdatesAction();

private:

    QMenu *fileMenu;
    QAction *exitAction;
    QAction *addItem;
    QAction *addCustomer;
    QAction *addTransaction;
    QAction *openAction;
    QAction *saveAction;
    QAction *clearAllAction;
    QAction *restoreAction;
    QAction *backupAction;
    QAction *settingAction;
    QAction *contactAction;
    QAction *aboutAction;
    QAction *updatesAction;

    QToolBar *toolbar;

    QTreeView *treeView;
    QStandardItemModel *model;

    Broadcast *broadcast;
    DataStore* dataStore;

};
#endif // MAINWINDOW_H
