

#ifndef OSCILLOSCOPE_MAIN_WINDOW_H
#define OSCILLOSCOPE_MAIN_WINDOW_H


#include <QtWidgets/QWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QStackedLayout>
#include <QtWidgets/QDialogButtonBox>


class MainWindow : public QMainWindow
{
Q_OBJECT;
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    //void createFormInterior();
    QPushButton *connectButton;
    QLabel *connectLabel;


};


#endif //OSCILLOSCOPE_MAIN_WINDOW_H
