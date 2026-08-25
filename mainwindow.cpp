#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDir>
#include<QFile>
#include<QFileDialog>
#include<QFileInfo>
#include<QTextStream>
#include<QDataStream>
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

void MainWindow::on_pushButton_clicked()
{
    QFileDialog fileInfo;
    QString filename=fileInfo.getSaveFileName(this,"select Dir & Give a file","D:/Qt_Project","Text files (*.txt);;All files (*.*)");
    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out<<ui->Data_edit->toPlainText();

    out.flush();
     file.close();
}


void MainWindow::on_pushButton_2_clicked()
{
    QFileDialog fileInfo;
    QString filename=fileInfo.getOpenFileName(this,"select a file","D:/Qt_Project","Text files (*.txt);;All files (*.*)");
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QString str;
    str=in.readAll();
    in.flush();
    file.close();
    ui->Data_edit->setPlainText(str);
}


void MainWindow::on_pushButton_4_clicked()
{
    QFileDialog fileInfo;
    QString filename=fileInfo.getSaveFileName(this,"select a file","D:/Qt_Project","Text files (*.dat);;All files (*.*)");
    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    QByteArray data=ui->Data_edit->toPlainText().toUtf8();
    /*QDataStream out(&file);
    QByteArray data=ui->Data_edit->toPlainText().toUtf8();
    out.writeBytes(data,data.size());*/
    file.write(data);
    file.flush();
    file.close();
}


void MainWindow::on_pushButton_3_clicked()
{
    QFileDialog fileInfo;
    QString filename=fileInfo.getOpenFileName(this,"select a file","D:/Qt_Project","Text files (*.dat);;All files (*.*)");
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    QByteArray arr =file.readAll();
    ui->Data_edit->setPlainText(arr);
    file.close();
}

