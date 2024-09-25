#include "mainwindow.h"
#include <QApplication>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();
    w.setFixedSize(300, 400);

    QScreen *screen = QApplication::primaryScreen();
    if (screen) {
        QRect screenRect = screen->geometry();
        QRect widgetRect = w.rect();
        QPoint center = screenRect.center() - widgetRect.center();
        w.move(center);
    }

    w.show();
    return a.exec();
}
