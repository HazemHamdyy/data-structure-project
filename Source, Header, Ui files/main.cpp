#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setStyleSheet("QMainWindow { background-color: #f5f5f5; color: #000000; }"
                    "QPushButton { background-color: #2196F3; color: #ffffff; border-radius: 5px; padding: 10px; }"
                    "QLabel { font-size: 14px; font-weight: bold; color: #4CAF50; }"
                    "QLineEdit { background-color: #ffffff; color: #000000; border-radius: 5px; padding: 10px; border: 1px solid #2196F3; }");

    w.show();
    return a.exec();
}
