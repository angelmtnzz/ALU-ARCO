/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *ALU;
    QLabel *REAL;
    QLabel *IEEE;
    QLabel *HEXA;
    QLabel *OP1;
    QLabel *OP2;
    QLabel *op1R;
    QLabel *op1I;
    QLabel *op1H;
    QLabel *op2R;
    QLabel *op2I;
    QLabel *op2H;
    QPushButton *PB1;
    QPushButton *PB2;
    QPushButton *PB3;
    QLabel *R;
    QLabel *R_Result;
    QLabel *IE_Result;
    QLabel *H_Result;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(773, 265);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ALU = new QLabel(centralwidget);
        ALU->setObjectName(QString::fromUtf8("ALU"));
        ALU->setGeometry(QRect(20, 20, 731, 21));
        ALU->setFrameShape(QFrame::StyledPanel);
        ALU->setAlignment(Qt::AlignCenter);
        REAL = new QLabel(centralwidget);
        REAL->setObjectName(QString::fromUtf8("REAL"));
        REAL->setGeometry(QRect(70, 60, 221, 20));
        REAL->setFrameShape(QFrame::StyledPanel);
        REAL->setAlignment(Qt::AlignCenter);
        IEEE = new QLabel(centralwidget);
        IEEE->setObjectName(QString::fromUtf8("IEEE"));
        IEEE->setGeometry(QRect(300, 60, 221, 20));
        IEEE->setFrameShape(QFrame::StyledPanel);
        IEEE->setAlignment(Qt::AlignCenter);
        HEXA = new QLabel(centralwidget);
        HEXA->setObjectName(QString::fromUtf8("HEXA"));
        HEXA->setGeometry(QRect(530, 60, 221, 20));
        HEXA->setFrameShape(QFrame::StyledPanel);
        HEXA->setAlignment(Qt::AlignCenter);
        OP1 = new QLabel(centralwidget);
        OP1->setObjectName(QString::fromUtf8("OP1"));
        OP1->setGeometry(QRect(20, 90, 41, 20));
        OP1->setFrameShape(QFrame::StyledPanel);
        OP1->setAlignment(Qt::AlignCenter);
        OP2 = new QLabel(centralwidget);
        OP2->setObjectName(QString::fromUtf8("OP2"));
        OP2->setGeometry(QRect(20, 120, 41, 20));
        OP2->setFrameShape(QFrame::StyledPanel);
        OP2->setAlignment(Qt::AlignCenter);
        op1R = new QLabel(centralwidget);
        op1R->setObjectName(QString::fromUtf8("op1R"));
        op1R->setGeometry(QRect(70, 90, 221, 20));
        op1R->setFrameShape(QFrame::StyledPanel);
        op1R->setAlignment(Qt::AlignCenter);
        op1I = new QLabel(centralwidget);
        op1I->setObjectName(QString::fromUtf8("op1I"));
        op1I->setGeometry(QRect(300, 90, 221, 20));
        op1I->setFrameShape(QFrame::StyledPanel);
        op1I->setAlignment(Qt::AlignCenter);
        op1H = new QLabel(centralwidget);
        op1H->setObjectName(QString::fromUtf8("op1H"));
        op1H->setGeometry(QRect(530, 90, 221, 20));
        op1H->setFrameShape(QFrame::StyledPanel);
        op1H->setAlignment(Qt::AlignCenter);
        op2R = new QLabel(centralwidget);
        op2R->setObjectName(QString::fromUtf8("op2R"));
        op2R->setGeometry(QRect(70, 120, 221, 20));
        op2R->setFrameShape(QFrame::StyledPanel);
        op2R->setAlignment(Qt::AlignCenter);
        op2I = new QLabel(centralwidget);
        op2I->setObjectName(QString::fromUtf8("op2I"));
        op2I->setGeometry(QRect(300, 120, 221, 20));
        op2I->setFrameShape(QFrame::StyledPanel);
        op2I->setAlignment(Qt::AlignCenter);
        op2H = new QLabel(centralwidget);
        op2H->setObjectName(QString::fromUtf8("op2H"));
        op2H->setGeometry(QRect(530, 120, 221, 20));
        op2H->setFrameShape(QFrame::StyledPanel);
        op2H->setAlignment(Qt::AlignCenter);
        PB1 = new QPushButton(centralwidget);
        PB1->setObjectName(QString::fromUtf8("PB1"));
        PB1->setGeometry(QRect(20, 160, 241, 24));
        PB2 = new QPushButton(centralwidget);
        PB2->setObjectName(QString::fromUtf8("PB2"));
        PB2->setGeometry(QRect(270, 160, 231, 24));
        PB3 = new QPushButton(centralwidget);
        PB3->setObjectName(QString::fromUtf8("PB3"));
        PB3->setGeometry(QRect(510, 160, 241, 24));
        R = new QLabel(centralwidget);
        R->setObjectName(QString::fromUtf8("R"));
        R->setGeometry(QRect(20, 200, 41, 20));
        R->setFrameShape(QFrame::StyledPanel);
        R->setAlignment(Qt::AlignCenter);
        R_Result = new QLabel(centralwidget);
        R_Result->setObjectName(QString::fromUtf8("R_Result"));
        R_Result->setGeometry(QRect(70, 200, 221, 20));
        R_Result->setFrameShape(QFrame::StyledPanel);
        R_Result->setAlignment(Qt::AlignCenter);
        IE_Result = new QLabel(centralwidget);
        IE_Result->setObjectName(QString::fromUtf8("IE_Result"));
        IE_Result->setGeometry(QRect(300, 200, 221, 20));
        IE_Result->setFrameShape(QFrame::StyledPanel);
        IE_Result->setAlignment(Qt::AlignCenter);
        H_Result = new QLabel(centralwidget);
        H_Result->setObjectName(QString::fromUtf8("H_Result"));
        H_Result->setGeometry(QRect(530, 200, 221, 20));
        H_Result->setFrameShape(QFrame::StyledPanel);
        H_Result->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ALU->setText(QCoreApplication::translate("MainWindow", "ARITMETIC-LOGICAL UNIT", nullptr));
        REAL->setText(QCoreApplication::translate("MainWindow", "REAL", nullptr));
        IEEE->setText(QCoreApplication::translate("MainWindow", "IEEE754", nullptr));
        HEXA->setText(QCoreApplication::translate("MainWindow", "HEXADECIMAL", nullptr));
        OP1->setText(QCoreApplication::translate("MainWindow", "OP1", nullptr));
        OP2->setText(QCoreApplication::translate("MainWindow", "OP2", nullptr));
        op1R->setText(QString());
        op1I->setText(QString());
        op1H->setText(QString());
        op2R->setText(QString());
        op2I->setText(QString());
        op2H->setText(QString());
        PB1->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        PB2->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        PB3->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        R->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        R_Result->setText(QString());
        IE_Result->setText(QString());
        H_Result->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
