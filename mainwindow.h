#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void numberEmitted(int number);

private slots:
    void buttonPushed();
    void operationPushed();
    void equals();
    void setGeo();

private:
    QLabel *label;
    QPushButton *operationButton[6];
    QPushButton *buttons[10];
};
#endif // MAINWINDOW_H
