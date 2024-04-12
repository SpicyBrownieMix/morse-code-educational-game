/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *textInputBox;
    QLabel *background;
    QLabel *morsePrinter;
    QLabel *CaptainDialogueBox;
    QLabel *CaptainDialogueText;
    QPushButton *referenceSheetButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 801);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        textInputBox = new QLineEdit(centralwidget);
        textInputBox->setObjectName("textInputBox");
        textInputBox->setGeometry(QRect(280, 465, 441, 56));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 0));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(191, 191, 191, 0));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
        QBrush brush2(QColor(34, 6, 6, 217));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush3(QColor(23, 23, 23, 0));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush3);
        QBrush brush4(QColor(0, 0, 0, 0));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush4);
        QBrush brush5(QColor(51, 122, 85, 0));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush5);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush);
        QBrush brush6(QColor(152, 152, 152, 0));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush4);
        QBrush brush7(QColor(43, 10, 10, 152));
        brush7.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        QBrush brush8(QColor(83, 176, 54, 0));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Accent, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Accent, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::Accent, brush8);
        textInputBox->setPalette(palette);
        QFont font;
        font.setPointSize(30);
        textInputBox->setFont(font);
        textInputBox->setStyleSheet(QString::fromUtf8(""));
        background = new QLabel(centralwidget);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 1000, 750));
        background->setPixmap(QPixmap(QString::fromUtf8(":/assets/MorseCodeBackground.jpg")));
        morsePrinter = new QLabel(centralwidget);
        morsePrinter->setObjectName("morsePrinter");
        morsePrinter->setGeometry(QRect(290, 270, 421, 61));
        QPalette palette1;
        QBrush brush9(QColor(43, 10, 10, 216));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        QBrush brush10(QColor(43, 10, 10, 217));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush10);
        morsePrinter->setPalette(palette1);
        QFont font1;
        font1.setPointSize(70);
        morsePrinter->setFont(font1);
        CaptainDialogueBox = new QLabel(centralwidget);
        CaptainDialogueBox->setObjectName("CaptainDialogueBox");
        CaptainDialogueBox->setEnabled(true);
        CaptainDialogueBox->setGeometry(QRect(730, 670, 191, 31));
        CaptainDialogueText = new QLabel(centralwidget);
        CaptainDialogueText->setObjectName("CaptainDialogueText");
        CaptainDialogueText->setEnabled(true);
        CaptainDialogueText->setGeometry(QRect(740, 700, 171, 20));
        referenceSheetButton = new QPushButton(centralwidget);
        referenceSheetButton->setObjectName("referenceSheetButton");
        referenceSheetButton->setGeometry(QRect(90, 610, 181, 141));
        MainWindow->setCentralWidget(centralwidget);
        background->raise();
        textInputBox->raise();
        morsePrinter->raise();
        CaptainDialogueBox->raise();
        CaptainDialogueText->raise();
        referenceSheetButton->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        textInputBox->setText(QString());
        textInputBox->setPlaceholderText(QCoreApplication::translate("MainWindow", "Type Here...", nullptr));
        background->setText(QString());
        morsePrinter->setText(QString());
        CaptainDialogueBox->setText(QCoreApplication::translate("MainWindow", "Put Captain Dialogue Here", nullptr));
        CaptainDialogueText->setText(QCoreApplication::translate("MainWindow", "Captain Dialogue Text", nullptr));
        referenceSheetButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
