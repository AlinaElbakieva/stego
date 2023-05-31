/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *encodeButton;
    QPushButton *saveButton;
    QWidget *tab_2;
    QLabel *label_3;
    QPushButton *pushButton_4;
    QPushButton *decodeButton;
    QLineEdit *lineEdit_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(871, 658);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 871, 631));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(320, 320));
        tabWidget->setStyleSheet(QString::fromUtf8("\n"
"background-image: url(:/resurses/images/fon.png);"));
        tab = new QWidget();
        tab->setObjectName("tab");
        tab->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(60, 10, 261, 31));
        pushButton->setMaximumSize(QSize(300, 16777215));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(450, 70, 380, 400));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(380, 400));
        label_2->setBaseSize(QSize(380, 380));
        label_2->setStyleSheet(QString::fromUtf8("background-image: url(:/resurses/images/fon2.png);"));
        label = new QLabel(tab);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 70, 380, 400));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(380, 400));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/resurses/images/fon2.png);"));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(31, 501, 621, 28));
        encodeButton = new QPushButton(tab);
        encodeButton->setObjectName("encodeButton");
        encodeButton->setGeometry(QRect(657, 501, 101, 29));
        encodeButton->setStyleSheet(QString::fromUtf8(""));
        saveButton = new QPushButton(tab);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(759, 501, 81, 29));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        label_3 = new QLabel(tab_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 50, 450, 450));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(450, 450));
        label_3->setStyleSheet(QString::fromUtf8("background-image: url(:/resurses/images/fon2.png);"));
        pushButton_4 = new QPushButton(tab_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(511, 249, 311, 31));
        pushButton_4->setStyleSheet(QString::fromUtf8(""));
        decodeButton = new QPushButton(tab_2);
        decodeButton->setObjectName("decodeButton");
        decodeButton->setGeometry(QRect(511, 322, 311, 31));
        lineEdit_2 = new QLineEdit(tab_2);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(511, 287, 311, 28));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 871, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\262\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\204\320\260\320\271\320\273 ", nullptr));
        label_2->setText(QString());
        label->setText(QString());
        encodeButton->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\264\320\270\321\200\320\276\320\262\320\260\321\202\321\214 ", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\272\320\260\321\207\320\260\321\202\321\214 ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\320\272\320\276\320\264\320\270\321\200\320\276\320\262\320\260\321\202\321\214 ", nullptr));
        label_3->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\320\262\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\204\320\260\320\271\320\273", nullptr));
        decodeButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\265\320\272\320\276\320\264\320\270\321\200\320\276\320\262\320\260\321\202\321\214 ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\320\264\320\265\320\272\320\276\320\264\320\270\321\200\320\276\320\262\320\260\321\202\321\214 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
