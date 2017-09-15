
#include "mainwindow.h"
#include <QLineEdit>
#include <QtWidgets/QDialogButtonBox>
#include <iostream>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QtWidgets/QFileDialog>
#include <QDebug>
#include <QtCore/QTextCodec>
#include <QtCore/QDate>
#include "devcmd.h"

extern std::vector<uint8_t>TxData;

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
{
    QWidget * wgt = new QWidget(this);
    setCentralWidget(wgt);
    setWindowTitle(trUtf8("Генератор сигнала"));
    setWindowIcon(QIcon("icon1.ico"));

    QHBoxLayout *TopWidgetLine = new QHBoxLayout();

    connectButton = new QPushButton (trUtf8("Подключиться"), this);
    connectButton->setIcon(QIcon("connect.ico"));

    connect(connectButton, SIGNAL (released()), this, SLOT (connectButtonClicked()));

    //connectButton->setFixedSize(100,30);
    TopWidgetLine->addWidget(connectButton);

    connectLabel = new QLabel(trUtf8("Устройство не подключено"),this);
    connectLabel->setStyleSheet("border: 1px solid black; border-radius: 3px; background-color: red;");
    TopWidgetLine->addWidget(connectLabel);

    pointFileButton = new QPushButton(trUtf8("Указать файл"), this);
    pointFileButton->setIcon(QIcon("openfile.ico"));

    connect(pointFileButton, SIGNAL (released()), this, SLOT (pointFileButtonClicked()));

    QLabel *fileNameLineLabel = new QLabel(trUtf8("Имя выбранного файла:"));
    fileNameLine = new QLineEdit(this);
    fileNameLine->setEnabled(false);
    fileHeaderLabel = new QLabel(trUtf8("Заголовок"),this);

    QVBoxLayout *MiddleRightWidgetBox = new QVBoxLayout();
    MiddleRightWidgetBox->addWidget(fileNameLineLabel);
    MiddleRightWidgetBox->addWidget(fileNameLine);
    MiddleRightWidgetBox->addWidget(fileHeaderLabel);

    QHBoxLayout *MiddleWidgetLine = new QHBoxLayout();

    MiddleWidgetLine->addWidget(pointFileButton);
    MiddleWidgetLine->addLayout(MiddleRightWidgetBox);

    QHBoxLayout *MiddleWidgetLine2 = new QHBoxLayout();
    startGenerationButton = new QPushButton(trUtf8("Начать генерацию"), this);
    startGenerationButton->setIcon(QIcon("play.ico"));
    connect(startGenerationButton, SIGNAL (released()), this, SLOT (startGenerationButtonClicked()));
    startGenerationButton->setEnabled(false);

    stopGenerationButton = new QPushButton(trUtf8("Остановить генерацию"), this);
    stopGenerationButton->setIcon(QIcon("stop3.ico"));
    connect(stopGenerationButton, SIGNAL (released()), this, SLOT (stopGenerationButtonClicked()));
    stopGenerationButton->setEnabled(false);

    MiddleWidgetLine2->addWidget(startGenerationButton);
    MiddleWidgetLine2->addWidget(stopGenerationButton);

    QFrame* separatorFrame = new QFrame();
    separatorFrame->setFrameShape(QFrame::HLine);

    QFrame* separatorFrame2 = new QFrame();
    separatorFrame2->setFrameShape(QFrame::HLine);

    QFrame* separatorFrame3 = new QFrame();
    separatorFrame3->setFrameShape(QFrame::HLine);

    QFrame* separatorFrame4 = new QFrame();
    separatorFrame4->setFrameShape(QFrame::HLine);

    progressBar = new QProgressBar();
    progressBar->setMinimum(0);
    progressBar->setMaximum(100);
    QLabel *progressBarLabel = new QLabel(trUtf8("Статус выполнения генерации: "),this);

    errorTextEdit = new QTextEdit();
    //errorTextEdit->setEnabled(false);
    QLabel *errorTextLabel = new QLabel(trUtf8("Окно сообщений: "),this);
    QLabel *connectLabel = new QLabel(trUtf8("Подключение к прибору: "),this);
    QLabel *importLabel = new QLabel(trUtf8("Импорт файла: "),this);
    QLabel *manageLabel = new QLabel(trUtf8("Управление генерацией: "),this);

    QVBoxLayout *mainLay = new QVBoxLayout();
    mainLay->addWidget(connectLabel);
    mainLay->addLayout(TopWidgetLine);
    mainLay->addWidget(separatorFrame);
    mainLay->addWidget(importLabel);
    mainLay->addLayout(MiddleWidgetLine);
    mainLay->addWidget(separatorFrame2);
    mainLay->addWidget(manageLabel);
    mainLay->addLayout(MiddleWidgetLine2);
    mainLay->addWidget(separatorFrame3);
    mainLay->addWidget(progressBarLabel);
    mainLay->addWidget(progressBar);
    mainLay->addWidget(separatorFrame4);
    mainLay->addWidget(errorTextLabel);
    mainLay->addWidget(errorTextEdit);

    wgt->setLayout(mainLay);

    //reqSerialPortInfo = NULL;
    reqSerialPort = new QSerialPort();
    genFileNamePath = "";
    connect(reqSerialPort, SIGNAL(readyRead()), this, SLOT(serialReceived()));


    //tabViewPoint = new TabViewPoint(this);
}


void MainWindow::pointFileButtonClicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    QString::fromUtf8("Указать файл"),
                                                    QDir::currentPath(),
                                                    "*.csv");
    qDebug()<<fileName;

    QFile file(fileName);

    fileNameLine->setText(fileName);


    int nRows = 0;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        nRows = QTextStream(&file).readAll().split('\n').count();
    file.close();
    qDebug() << nRows;

    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "Файл не найден";
        startGenerationButton->setEnabled(false);
        stopGenerationButton->setEnabled(false);
    } else {
        // Создаём поток для извлечения данных из файла
        QTextStream in(&file);
        // Считываем данные до конца файла

//        while (!in.atEnd())
//        {
//            // ... построчно
//            QString line = in.readLine();
//            errorTextEdit->append(line);
//
//        }
        QString headerLabelline;
        for (int i=0; i<2; i++) {
            headerLabelline = headerLabelline + "  " + in.readLine();
        }
        fileHeaderLabel->setText(trUtf8("Заголовок : ") + headerLabelline);
        file.close();
        if (connectButton->text() ==  trUtf8("Отключиться")) {
            startGenerationButton->setEnabled(true);
            stopGenerationButton->setEnabled(true);
        }
    }
}


void MainWindow::connectButtonClicked()
{
    //QString butName = connectButton->text();
    //qDebug() << butName;

    if (connectButton->text() == "Подключиться") {

        errorTextEdit->append("Производится опрашивание доступных портов");

                foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
                errorTextEdit->append("Проверяется порт : " + info.portName());
                QSerialPort serial;
                serial.setPort(info);

                if (serial.open(QIODevice::ReadWrite)) {

                    cmdGetDeviceState();
                    QByteArray *sentData = new QByteArray(reinterpret_cast<const char *>(TxData.data()), TxData.size());
                    QByteArray input;
                    serial.write(sentData->data());
                    //TxData.clear();

                    serial.waitForBytesWritten(1000);
                    serial.waitForReadyRead(1000);
                    input = serial.readAll();
                    //std::cout << input << std::endl;
                    QString DataAsString = QTextCodec::codecForMib(106)->toUnicode(input);
                    qDebug() << input;

                    if (DataAsString == "~") {
                        errorTextEdit->append(info.portName() + " : " + "устройство найдено");
                        reqSerialPortInfo = info;
                    }
                    serial.close();
                }

            }

        errorTextEdit->append("Проверка портов завершена");

        if (!reqSerialPortInfo.isNull()) {
            reqSerialPort->setPort(reqSerialPortInfo);
            reqSerialPort->open(QIODevice::ReadWrite);

            connectLabel->setText("Устройство подключено");
            connectLabel->setStyleSheet("border: 1px solid black; border-radius: 3px; background-color: green;");
            connectButton->setText("Отключиться");

            if (!(fileNameLine->text()).isEmpty()) {
                startGenerationButton->setEnabled(true);
                stopGenerationButton->setEnabled(true);
            }
        }

    } else {
        reqSerialPort->close();
        connectLabel->setText("Устройство не подключено");
        connectLabel->setStyleSheet("border: 1px solid black; border-radius: 3px; background-color: red;");
        connectButton->setText("Подключиться");
        startGenerationButton->setEnabled(false);
        stopGenerationButton->setEnabled(false);
    }



    //qDebug() << connectButton->text();

}

void MainWindow::startGenerationButtonClicked()
{
    errorTextEdit->append("Генерация запущена");
    QString prevFileName = fileHeaderLabel->text();
    prevFileName.replace("#CLOCK=","C");
    prevFileName.replace("#SIZE=","S");
    prevFileName.replace(" ","");
    prevFileName.replace(trUtf8("Заголовок"),"");
    prevFileName.replace(trUtf8(":"),"");

    QFileInfo fileNamePath(fileNameLine->text());
    QString sfileNamePath = fileNameLine->text();
    QString fileNameOnly = fileNamePath.fileName();
    fileNameOnly.replace(".csv","");

    QString sCurrentDate = QDateTime::currentDateTime().toString("yyyyMMddhhmm");
    QString genFileName = fileNameOnly + "_" + prevFileName+ "_" + sCurrentDate + ".csv";
    genFileNamePath = sfileNamePath.replace(fileNameOnly + ".csv","") + genFileName;


    QFile transFile(fileNameLine->text());
//    outFile.open(QIODevice::WriteOnly);
//    outFile.close();
//
//    errorTextEdit->append(sfileNamePath);
//    errorTextEdit->append(fileNameOnly);
//    errorTextEdit->append(genFileName);
//    errorTextEdit->append(genFileNamePath);


    if ( !transFile.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "Файл не найден";
    } else {
        // Создаём поток для извлечения данных из файла
        QTextStream inStr(&transFile);
        QByteArray transByteData;
        // Считываем данные до конца файла

        while (!inStr.atEnd())
        {
            // ... построчно
            QString line = inStr.readLine();
            for (int i = 0; i < line.size(); ++i)
            transByteData.append(line.at(i));

        }
        transFile.close();
        //reqSerialPort->waitForBytesWritten(transByteData.length());
        reqSerialPort->write(transByteData.data());


    }

}

void MainWindow::stopGenerationButtonClicked()
{
    errorTextEdit->append("Генерация остановлена");
}

void MainWindow::serialReceived()
{
        QFile outFile(genFileNamePath);
        QTextStream out(&outFile);
        outFile.open(QIODevice::ReadWrite | QIODevice::Append);
        QByteArray ba;
        //reqSerialPort->waitForReadyRead(1000);
        ba = reqSerialPort->readAll();
        out << ba;
        outFile.close();
        //qDebug() << "serialReceived inside";
}

MainWindow::~MainWindow()
{
}



