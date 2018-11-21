/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *textEdit;
    QPushButton *forward;
    QPushButton *right;
    QPushButton *back;
    QPushButton *left;
    QComboBox *comboBox;
    QLabel *inventory;
    QPushButton *pickUp;
    QLabel *label;
    QProgressBar *progressBar;
    QTextEdit *pickItem;
    QProgressBar *oxygenProgressBar;
    QMenuBar *menuBar;
    QMenu *menuEscape_Room;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(530, 343);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textEdit = new QLabel(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 50, 401, 131));
        forward = new QPushButton(centralWidget);
        forward->setObjectName(QStringLiteral("forward"));
        forward->setGeometry(QRect(40, 200, 71, 31));
        right = new QPushButton(centralWidget);
        right->setObjectName(QStringLiteral("right"));
        right->setGeometry(QRect(70, 230, 71, 31));
        back = new QPushButton(centralWidget);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(40, 260, 71, 31));
        left = new QPushButton(centralWidget);
        left->setObjectName(QStringLiteral("left"));
        left->setGeometry(QRect(0, 230, 71, 31));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(420, 20, 101, 21));
        inventory = new QLabel(centralWidget);
        inventory->setObjectName(QStringLiteral("inventory"));
        inventory->setGeometry(QRect(430, 0, 101, 20));
        pickUp = new QPushButton(centralWidget);
        pickUp->setObjectName(QStringLiteral("pickUp"));
        pickUp->setGeometry(QRect(300, 230, 51, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(370, 100, 151, 21));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(410, 260, 118, 23));
        progressBar->setValue(0);
        pickItem = new QTextEdit(centralWidget);
        pickItem->setObjectName(QStringLiteral("pickItem"));
        pickItem->setGeometry(QRect(170, 230, 121, 31));
        oxygenProgressBar = new QProgressBar(centralWidget);
        oxygenProgressBar->setObjectName(QStringLiteral("oxygenProgressBar"));
        oxygenProgressBar->setGeometry(QRect(7, 10, 401, 20));
        oxygenProgressBar->setAutoFillBackground(false);
        oxygenProgressBar->setValue(100);
        oxygenProgressBar->setTextVisible(false);
        oxygenProgressBar->setOrientation(Qt::Horizontal);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 530, 21));
        menuEscape_Room = new QMenu(menuBar);
        menuEscape_Room->setObjectName(QStringLiteral("menuEscape_Room"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuEscape_Room->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        textEdit->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        forward->setText(QApplication::translate("MainWindow", "Forward", nullptr));
        right->setText(QApplication::translate("MainWindow", "Right", nullptr));
        back->setText(QApplication::translate("MainWindow", "Backwards", nullptr));
        left->setText(QApplication::translate("MainWindow", "Left", nullptr));
        comboBox->setCurrentText(QString());
        inventory->setText(QApplication::translate("MainWindow", "Inventory", nullptr));
        pickUp->setText(QApplication::translate("MainWindow", "Pick Up", nullptr));
        label->setText(QString());
#ifndef QT_NO_TOOLTIP
        oxygenProgressBar->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>The oxygen meter for the escape room. Once this drops to zero its bye bye Leroy! :'(</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        menuEscape_Room->setTitle(QApplication::translate("MainWindow", "Escape Room", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
