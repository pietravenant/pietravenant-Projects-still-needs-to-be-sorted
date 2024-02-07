#include "MyAction.h"
#include "item.h"
#include "itemdialog.h"
#include <QFileDialog>
#include <QInputDialog>

MyAction::MyAction(const QIcon & icon, const QString & text, QObject * parent)
 : QAction(icon, text, parent) { }

OpenAction::OpenAction(const QIcon & icon, const QString & text, QObject * parent)
 : MyAction(icon, text, parent) { }

void OpenAction::doIt() {
    QString fname = QFileDialog::getOpenFileName(0, "Open item file", ".", "Text files (*.txt)");
}

SaveAction::SaveAction(const QIcon & icon, const QString & text, QObject * parent)
 : MyAction(icon, text, parent) { }

void SaveAction::doIt() {
    QString fname = QFileDialog::getSaveFileName(0, "Save item file", ".", "Text files (*.txt)");
}

ExitAction::ExitAction(const QIcon & icon, const QString & text, QObject * parent)
 : MyAction(icon, text, parent) { }

void ExitAction::doIt() {
    exit(0);
}

AddAction::AddAction(const QIcon & icon, const QString & text, QObject * parent)
 : MyAction(icon, text, parent) { }

void AddAction::doIt() {
    ItemDialog * id = new ItemDialog(parentWidget(), "Add item", NULL);
    id->show();
}

ChangeAction::ChangeAction(const QIcon & icon, const QString & text, QObject * parent)
 : MyAction(icon, text, parent) { }

void ChangeAction::doIt() {
    QString barcode = QInputDialog::getText(0, "Change item", "Barcode:");
    Item * i;// = itemList->findItem(barcode);
    ItemDialog * id = new ItemDialog(parentWidget(), "Change item", i);
    id->show();
}

RemoveAction::RemoveAction(const QIcon & icon, const QString & text, QObject * parent)
 : MyAction(icon, text, parent) { }

void RemoveAction::doIt() {
    QString barcode = QInputDialog::getText(0, "Remove item", "Barcode:");

}
