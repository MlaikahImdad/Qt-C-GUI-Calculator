#include "mainwindow.h"
#include "./ui_mainwindow.h"

QString value = "", total = "";
int fNum, sNum;
bool addBool = false, subtractBool = false, multiplyBool = false, divideBool = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    label = new QLabel("0", this);
    label->setGeometry(QRect(QPoint(75, 25), QSize(50, 200)));

    for (int i=0; i<6; ++i) {
        QString operations[] = {"C", "=", "+", "-", "X", "/"};
        operationButton[i] = new QPushButton(operations[i], this);
        if (i == 1) {
            connect(operationButton[i], SIGNAL(released()), this, SLOT(equals()));
        } else {
            connect(operationButton[i], SIGNAL(released()), this, SLOT(operationPushed()));
        }
    }

    for (int i=0; i<10; ++i) {
        QString digit = QString::number(i);
        buttons[i] = new QPushButton(digit, this);
        connect(buttons[i], SIGNAL(released()), this, SLOT(buttonPushed()));
    }
    setGeo();
}
void MainWindow::buttonPushed(){
    QPushButton *button = (QPushButton *)sender();
    emit numberEmitted(button->text()[0].digitValue());
    value += QString::number(button->text()[0].digitValue());
    label->setText(value);
}
void MainWindow::operationPushed(){
    QPushButton *button = (QPushButton *)sender();
    fNum = value.toInt();
    if (button->text()== "C") {
        value = "";
        fNum = 0;
        sNum = 0;
    }
    if (button->text()== "+") {
        addBool = true;
    }
    if (button->text()== "-") {
        subtractBool = true;
    }
    if (button->text()== "X") {
        multiplyBool = true;
    }
    if (button->text()== "/") {
        divideBool = true;
    }
    value = "";
    label->setText(value);
}
void MainWindow::setGeo(){
    for (int i=0; i<1; ++i) {
        buttons[i]->setGeometry(QRect(QPoint(50, 300), QSize(50, 50)));
        operationButton[i]->setGeometry(QRect(QPoint(100, 300), QSize(50, 50)));
        operationButton[i+1]->setGeometry(QRect(QPoint(150, 300), QSize(50, 50)));
        operationButton[i+2]->setGeometry(QRect(QPoint(200, 300), QSize(50, 50)));
    }
    for (int i=1; i<4; ++i) {
        buttons[i]->setGeometry(QRect(QPoint(50*i, 250), QSize(50, 50)));
        if (i == 3) {
            operationButton[i]->setGeometry(QRect(QPoint(200, 250), QSize(50, 50)));
        }
    }
    for (int i=4; i<7; ++i) {
        buttons[i]->setGeometry(QRect(QPoint(50*(i-3), 200), QSize(50, 50)));
        if (i == 4) {
            operationButton[i]->setGeometry(QRect(QPoint(200, 200), QSize(50, 50)));
        }
    }
    for (int i=7; i<10; ++i) {
        buttons[i]->setGeometry(QRect(QPoint(50*(i-6), 150), QSize(50, 50)));
        if (i == 7) {
            operationButton[i-2]->setGeometry(QRect(QPoint(200, 150), QSize(50, 50)));
        }
    }
}

void MainWindow::equals(){
    if(addBool) {
        sNum = value.toInt();
        total = QString::number(fNum+sNum);
        label->setText(total);
        addBool = false;
    }
    if(subtractBool) {
        sNum = value.toInt();
        total = QString::number(fNum-sNum);
        label->setText(total);
        subtractBool = false;
    }
    if(multiplyBool){
        sNum = value.toInt();
        total = QString::number(fNum*sNum);
        label->setText(total);
        multiplyBool = false;
    }
    if(divideBool){
        sNum = value.toInt();
        total = QString::number(fNum/sNum);
        label->setText(total);
        divideBool = false;
    }
    fNum = 0;
    sNum = 0;
    value = "";
    total = "";
}

MainWindow::~MainWindow()
{
}
