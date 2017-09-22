//
// Created by kalistrat on 19.09.2017.
//

#ifndef OSCILLOSCOPESINGLE_MYSERIALPORT_H
#define OSCILLOSCOPESINGLE_MYSERIALPORT_H
#include<QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class MySerialPort : public QObject {
Q_OBJECT
public:
    QSerialPort *serialPort;
    QByteArray resBa;
    MySerialPort(QSerialPortInfo serialPortInfo);
    ~MySerialPort();

private slots:
    void serialReceived();
};


#endif //OSCILLOSCOPESINGLE_MYSERIALPORT_H
