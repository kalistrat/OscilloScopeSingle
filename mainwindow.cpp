
#include "mainwindow.h"
#include <QLineEdit>
#include <QtWidgets/QDialogButtonBox>
#include <iostream>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QtWidgets/QFileDialog>
#include <QDebug>


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

    stopGenerationButton = new QPushButton(trUtf8("Остановить генерацию"), this);
    stopGenerationButton->setIcon(QIcon("stop3.ico"));
    connect(stopGenerationButton, SIGNAL (released()), this, SLOT (stopGenerationButtonClicked()));

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
    } else {
        // Создаём поток для извлечения данных из файла
        QTextStream in(&file);
        // Считываем данные до конца файла

        while (!in.atEnd())
        {
            // ... построчно
            QString line = in.readLine();
            errorTextEdit->append(line);

        }
        file.close();
    }
}


void MainWindow::connectButtonClicked()
{
    errorTextEdit->append("Производится опрашивание доступных портов");

            foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
            errorTextEdit->append("Проверяется порт : " + info.portName() + " : устройство не найдено");
            QSerialPort serial;
            serial.setPort(info);
            if (serial.open(QIODevice::ReadWrite))
                serial.close();
        }

    errorTextEdit->append("Проверка портов завершена");


    qDebug() << connectButton->text();

}

void MainWindow::startGenerationButtonClicked()
{
    errorTextEdit->append("Генерация запущена");
}

void MainWindow::stopGenerationButtonClicked()
{
    errorTextEdit->append("Генерация остановлена");
}

MainWindow::~MainWindow()
{
}



