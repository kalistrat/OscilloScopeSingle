
#include "mainwindow.h"
#include <QLineEdit>
#include <QtWidgets/QDialogButtonBox>
#include <iostream>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
{
    QWidget * wgt = new QWidget(this);
    setCentralWidget(wgt);
    setWindowTitle(trUtf8("Генератор сигнала"));
    setWindowIcon(QIcon("icon1.ico"));

    QHBoxLayout *TopWidgetLine = new QHBoxLayout();

    connectButton = new QPushButton (trUtf8("Подключиться"), this);
    connectButton->setIcon(QIcon("logout.ico"));
    connectButton->setFixedSize(100,30);
    TopWidgetLine->addWidget(connectButton);

    connectLabel = new QLabel(trUtf8("Устройство не подключено"));
    connectLabel->setStyleSheet("border: 1px solid black; border-radius: 3px; background-color: red;");
    TopWidgetLine->addWidget(connectLabel);


    QVBoxLayout *mainLay = new QVBoxLayout();
    mainLay->addLayout(TopWidgetLine);
    wgt->setLayout(mainLay);

    //tabViewPoint = new TabViewPoint(this);
}

MainWindow::~MainWindow()
{
}



