#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "Helpers.h"
#include "Formatting.h"
#include "tree.h"
#include "Json.h"
#include "Consistency.h"
#include "removeSpaceAndUnique.h"
#include "Compression.h"
#include "Decompression.h"
#include "dialoggraphinfo.h"
#include "Graph.h"
#include "User.h"
#include "inputdialog.h"
#include "string.h"
#include <iostream>
#include <sstream>
#include <iterator>

#include <QFileDialog>
#include <QMessageBox>
#include <QPalette>
#include <QStyleFactory>
#include <QTextBlockUserData>
#include <QPlainTextEdit>
#include <QTextBlock>
#include <QTextLayout>
#include <QPainter>
#include <QTextEdit>
#include <QMainWindow>
#include <QInputDialog>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_actionOpen_triggered();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionFormat_triggered();

    void on_actionMinify_triggered();

    void on_actionConvert_to_JSON_triggered();


    void on_pushButton_2_clicked();


    void on_pushButton_10_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_actionCompress_triggered();

    void on_actionSearch_the_Graph_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
