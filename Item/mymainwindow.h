#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QTextEdit>
#include "itemlist.h"

class MyMainWindow : public QMainWindow {
    Q_OBJECT
public:
    MyMainWindow();
private slots:
    void handleAction(QAction * a);
private:
    QTextEdit * textEdit;
    ItemList iList;
};

#endif // MYMAINWINDOW_H
