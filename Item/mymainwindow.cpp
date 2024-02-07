#include "mymainwindow.h"
#include "item.h"
#include "itemdialog.h"
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QActionGroup>
#include <QFont>
#include <QIcon>
#include <QToolBar>
#include <QTextEdit>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>

MyMainWindow::MyMainWindow() : textEdit(new QTextEdit(this)) {
    setWindowTitle("Stock Editor");
    setMinimumSize(600, 100);
    setFont(QFont("Courier", 8));

    QActionGroup * fileGroup = new QActionGroup(this);
    fileGroup->addAction(new QAction(QIcon("icons/o.png"), "&Open", this));
    fileGroup->addAction(new QAction(QIcon("icons/s.png"), "&Save", this));
    fileGroup->addAction(new QAction(QIcon("icons/x.png"), "E&xit", this));

    QActionGroup * editGroup = new QActionGroup(this);
    editGroup->addAction(new QAction(QIcon("icons/a.png"), "&Add", this));
    editGroup->addAction(new QAction(QIcon("icons/c.png"), "&Change", this));
    editGroup->addAction(new QAction(QIcon("icons/r.png"), "&Remove", this));

    QMenu * fileMenu = menuBar()->addMenu("&File");
    fileMenu->addActions(fileGroup->actions());
    QMenu * editMenu = menuBar()->addMenu("&Edit");
    editMenu->addActions(editGroup->actions());

    QToolBar * toolBar = new QToolBar("Main");
    toolBar->addActions(fileGroup->actions());
    toolBar->addSeparator();
    toolBar->addActions(editGroup->actions());
    addToolBar(Qt::TopToolBarArea, toolBar);

    connect(fileGroup, SIGNAL(triggered(QAction *)), this, SLOT(handleAction(QAction *)));
    connect(editGroup, SIGNAL(triggered(QAction *)), this, SLOT(handleAction(QAction *)));

    textEdit->setEnabled(false);
    setCentralWidget(textEdit);
}

void MyMainWindow::handleAction(QAction * a) {
    if (a->text() == "&Open") {
        QString fname = QFileDialog::getOpenFileName(0, "Open item file", ".", "Text files (*.txt)");
        iList.readList(fname);
    }
    else if (a->text() == "&Save") {
        QString fname = QFileDialog::getSaveFileName(0, "Save item file", ".", "Text files (*.txt)");
        iList.writeList(fname);
    }
    else if (a->text() == "E&xit") {
        if (!iList.getChanged())
            exit(0);
        else if (QMessageBox::question(0, "Exit", "Are you sure you want to exit without saving?") == QMessageBox::Yes)
            exit(0);
    }
    else if (a->text() == "&Add") {
        Item * i = ItemDialog::addItem(this);
        if (i == NULL)
            QMessageBox::warning(this, "Add item", "Item not added");
        else if (iList.findItem(i->getBarcode()) == NULL)
            iList.addItem(*i);
        else if (QMessageBox::question(0, "Add item", "This barcode already exists in the database. Add stock?") == QMessageBox::Yes)
            iList.addItem(*i);
    }
    else if (a->text() == "&Change") {
        QString barcode = QInputDialog::getText(0, "Change item", "Barcode:");
        Item * i = iList.findItem(barcode);
        if (i == NULL)
            QMessageBox::warning(this, "Change item", QString("Item %1 not found").arg(barcode));
        else {
            Item * j = ItemDialog::changeItem(this, i);
            if (j == NULL)
                QMessageBox::warning(this, "Change item", QString("Item %1 not changed").arg(barcode));
            else
                *i = *j;
        }
    }
    else if (a->text() == "&Remove") {
        QString barcode = QInputDialog::getText(0, "Remove item", "Barcode:");
        if (iList.findItem(barcode) == NULL)
            QMessageBox::warning(this, "Remove item", QString("Item %1 not found").arg(barcode));
        else if (QMessageBox::question(this, "Remove item", QString("Are you sure you want to remove item %1?").arg(barcode)) == QMessageBox::Yes)
            iList.removeItem(barcode);
    }
    textEdit->clear();
    textEdit->textCursor().insertText(QString("%1\t%2\t%3\t%4\n").arg("Barcode", 13).arg("Description", 20).arg("Stock",5).arg("Price",8));
    foreach (QString iStr, iList.toStringList())
        textEdit->textCursor().insertText(QString("%1\n").arg(iStr));
}
