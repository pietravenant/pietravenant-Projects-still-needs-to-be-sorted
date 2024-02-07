#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "custommodel.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addItem();

private:
    Ui::MainWindow *ui;
    CustomModel *model;
};
#endif // MAINWINDOW_H
