#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnClearAll_clicked()
{
    ui->lineEdit_H->clear();
    ui->lineEdit_W->clear();
    ui->lcdNumber->display(0);
}


void MainWindow::on_btnCalc_clicked()
{
    QString str_W = ui->lineEdit_W->text();
    QString str_H = ui->lineEdit_H->text();
    bool okw;
    bool okh;
    double w = str_W.toDouble(&okw);
    double h = str_H.toDouble(&okh);
    if (!okw || !okh){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Please enter a valid number !");
        messageBox.setFixedSize(500,200);
        ui->lineEdit_H->clear();
        ui->lineEdit_W->clear();
    }
    else{
     ui->lcdNumber->display(w/(h*h));
    }
}

