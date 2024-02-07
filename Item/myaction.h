#ifndef MYACTION_H
#define MYACTION_H

#include <QAction>

class MyAction : public QAction {
public:
    MyAction(const QIcon & icon, const QString & text, QObject * parent);
    virtual void doIt() = 0;
};

class OpenAction : public MyAction {
public:
    OpenAction(const QIcon & icon, const QString & text, QObject * parent);
    void doIt();
};

class SaveAction : public MyAction {
public:
    SaveAction(const QIcon & icon, const QString & text, QObject * parent);
    void doIt();
};

class ExitAction : public MyAction {
public:
    ExitAction(const QIcon & icon, const QString & text, QObject * parent);
    void doIt();
};

class AddAction : public MyAction {
public:
    AddAction(const QIcon & icon, const QString & text, QObject * parent);
    void doIt();
};

class ChangeAction : public MyAction {
public:
    ChangeAction(const QIcon & icon, const QString & text, QObject * parent);
    void doIt();
};

class RemoveAction : public MyAction {
public:
    RemoveAction(const QIcon & icon, const QString & text, QObject * parent);
    void doIt();
};

#endif // MYACTION_H
