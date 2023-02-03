/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionFormat;
    QAction *actionMinify;
    QAction *actionConvert_to_JSON;
    QAction *actionCompress;
    QAction *actionSearch_the_Graph;
    QAction *actionSave_as;
    QAction *actionUndo;
    QAction *actionRedo;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_11;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_10;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPlainTextEdit *plainTextEdit;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuOperations;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1214, 715);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/imgs/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/rec/imgs/save.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon1);
        actionFormat = new QAction(MainWindow);
        actionFormat->setObjectName("actionFormat");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/rec/imgs/prettify.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFormat->setIcon(icon2);
        actionMinify = new QAction(MainWindow);
        actionMinify->setObjectName("actionMinify");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/rec/imgs/minify.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMinify->setIcon(icon3);
        actionConvert_to_JSON = new QAction(MainWindow);
        actionConvert_to_JSON->setObjectName("actionConvert_to_JSON");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/rec/imgs/json.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConvert_to_JSON->setIcon(icon4);
        actionCompress = new QAction(MainWindow);
        actionCompress->setObjectName("actionCompress");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/rec/imgs/compress.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCompress->setIcon(icon5);
        actionSearch_the_Graph = new QAction(MainWindow);
        actionSearch_the_Graph->setObjectName("actionSearch_the_Graph");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/rec/imgs/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSearch_the_Graph->setIcon(icon6);
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName("actionSave_as");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/rec/imgs/Save as.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_as->setIcon(icon7);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName("actionUndo");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/rec/imgs/Undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon8);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName("actionRedo");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/rec/imgs/Redo-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon9);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout->addWidget(pushButton_3);

        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");

        verticalLayout->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");

        verticalLayout->addWidget(pushButton_9);

        pushButton_11 = new QPushButton(centralwidget);
        pushButton_11->setObjectName("pushButton_11");

        verticalLayout->addWidget(pushButton_11);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");

        verticalLayout->addWidget(pushButton_4);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName("pushButton_10");

        verticalLayout->addWidget(pushButton_10);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");

        verticalLayout->addWidget(pushButton_5);

        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");

        verticalLayout->addWidget(pushButton_7);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");

        verticalLayout->addWidget(pushButton_6);

        pushButton_12 = new QPushButton(centralwidget);
        pushButton_12->setObjectName("pushButton_12");

        verticalLayout->addWidget(pushButton_12);

        pushButton_13 = new QPushButton(centralwidget);
        pushButton_13->setObjectName("pushButton_13");

        verticalLayout->addWidget(pushButton_13);


        horizontalLayout->addLayout(verticalLayout);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");

        horizontalLayout->addWidget(plainTextEdit);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1214, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuOperations = new QMenu(menubar);
        menuOperations->setObjectName("menuOperations");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuOperations->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuOperations->addAction(actionFormat);
        menuOperations->addAction(actionMinify);
        menuOperations->addAction(actionConvert_to_JSON);
        menuOperations->addAction(actionCompress);
        menuOperations->addSeparator();
        menuOperations->addAction(actionSearch_the_Graph);
        menuOperations->addAction(actionUndo);
        menuOperations->addAction(actionRedo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionFormat->setText(QCoreApplication::translate("MainWindow", "Format", nullptr));
        actionMinify->setText(QCoreApplication::translate("MainWindow", "Minify", nullptr));
        actionConvert_to_JSON->setText(QCoreApplication::translate("MainWindow", "Convert to JSON", nullptr));
        actionCompress->setText(QCoreApplication::translate("MainWindow", "Compress", nullptr));
        actionSearch_the_Graph->setText(QCoreApplication::translate("MainWindow", "Search the Graph", nullptr));
        actionSave_as->setText(QCoreApplication::translate("MainWindow", "Save as", nullptr));
        actionUndo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        actionRedo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "Open File", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Format XML", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Check Consistency", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Check for Errors", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Correct Consistency", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Minify", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Compress", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Decompress", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Convert to JSON", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Graph Info", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Search Posts", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Mutual Followers", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Suggest Followers", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuOperations->setTitle(QCoreApplication::translate("MainWindow", "Operations", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
