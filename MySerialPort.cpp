//
// Created by kalistrat on 19.09.2017.
//

#include <QtCore/QArgument>
#include "MySerialPort.h"
#include <QDebug>

MySerialPort::MySerialPort(QSerialPortInfo SerialPortInfo)
{
    serialPort = new QSerialPort();
    serialPort->setPort(SerialPortInfo);
    //serialPort->open(QIODevice::ReadWrite);
    connect(serialPort, SIGNAL(readyRead()), this, SLOT(serialReceived()));

}

void MySerialPort::serialReceived(){
    QByteArray ba;
    //serialPort->waitForReadyRead(1000);

        ba = serialPort->readAll();
        resBa.append(ba);
        qDebug() << "Что-то пришло из " + serialPort->portName() + " это следующие данные : " + ba.toHex();

}
MySerialPort::~MySerialPort() {
    serialPort->close();
}