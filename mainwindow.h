

#ifndef OSCILLOSCOPE_MAIN_WINDOW_H
#define OSCILLOSCOPE_MAIN_WINDOW_H


#include <QtWidgets/QWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QStackedLayout>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QTextEdit>


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
    QPushButton *pointFileButton;
    QLineEdit *fileNameLine;
    QLabel *fileHeaderLabel;
    QPushButton *startGenerationButton;
    QPushButton *stopGenerationButton;
    QProgressBar *progressBar;
    QTextEdit *errorTextEdit;


private slots:
    void pointFileButtonClicked();
    void connectButtonClicked();
    void startGenerationButtonClicked();
    void stopGenerationButtonClicked();

};


#endif //OSCILLOSCOPE_MAIN_WINDOW_H
