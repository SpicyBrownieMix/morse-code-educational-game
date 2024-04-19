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
    QPushButton *showAllButton;
    QLabel *streaksLabel;
    QLabel *captainPicture;
    QLabel *startScreenBackground;
    QPushButton *newGameButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 783);
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
        CaptainDialogueBox->setGeometry(QRect(70, 580, 861, 161));
        CaptainDialogueBox->setPixmap(QPixmap(QString::fromUtf8(":/assets/captainDialogBox.jpg")));
        CaptainDialogueText = new QLabel(centralwidget);
        CaptainDialogueText->setObjectName("CaptainDialogueText");
        CaptainDialogueText->setEnabled(true);
        CaptainDialogueText->setGeometry(QRect(100, 600, 651, 121));
        QPalette palette2;
        QBrush brush11(QColor(72, 33, 19, 216));
        brush11.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush11);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush11);
        CaptainDialogueText->setPalette(palette2);
        QFont font2;
        font2.setPointSize(20);
        CaptainDialogueText->setFont(font2);
        CaptainDialogueText->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        referenceSheetButton = new QPushButton(centralwidget);
        referenceSheetButton->setObjectName("referenceSheetButton");
        referenceSheetButton->setGeometry(QRect(90, 610, 181, 141));
        showAllButton = new QPushButton(centralwidget);
        showAllButton->setObjectName("showAllButton");
        showAllButton->setGeometry(QRect(420, 390, 151, 32));
        QPalette palette3;
        QBrush brush12(QColor(255, 52, 80, 0));
        brush12.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush12);
        QBrush brush13(QColor(209, 90, 64, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush13);
        QBrush brush14(QColor(57, 71, 27, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush14);
        QBrush brush15(QColor(243, 102, 102, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush15);
        QBrush brush16(QColor(203, 139, 59, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush16);
        QBrush brush17(QColor(218, 58, 0, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush17);
        QBrush brush18(QColor(58, 35, 17, 217));
        brush18.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush18);
        QBrush brush19(QColor(195, 126, 49, 255));
        brush19.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush19);
        QBrush brush20(QColor(72, 33, 19, 217));
        brush20.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush20);
        QBrush brush21(QColor(195, 0, 0, 0));
        brush21.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush21);
        QBrush brush22(QColor(182, 29, 70, 255));
        brush22.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush22);
        QBrush brush23(QColor(216, 148, 60, 217));
        brush23.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::HighlightedText, brush23);
        QBrush brush24(QColor(193, 131, 67, 255));
        brush24.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush24);
        QBrush brush25(QColor(255, 0, 5, 64));
        brush25.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush25);
        QBrush brush26(QColor(227, 0, 4, 255));
        brush26.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush26);
        QBrush brush27(QColor(255, 43, 0, 64));
        brush27.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush27);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush12);
        QBrush brush28(QColor(209, 48, 36, 255));
        brush28.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush28);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush14);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush15);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush16);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush17);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush18);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush19);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush20);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush21);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush22);
        palette3.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush23);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush24);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush25);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush26);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush27);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush16);
        QBrush brush29(QColor(209, 88, 45, 255));
        brush29.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush29);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush14);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush15);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush16);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush17);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush19);
        QBrush brush30(QColor(72, 33, 19, 255));
        brush30.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush30);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush21);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush21);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush22);
        palette3.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush23);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush24);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush25);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush26);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush27);
#endif
        showAllButton->setPalette(palette3);
        streaksLabel = new QLabel(centralwidget);
        streaksLabel->setObjectName("streaksLabel");
        streaksLabel->setGeometry(QRect(280, 180, 91, 16));
        QPalette palette4;
        QBrush brush31(QColor(56, 34, 16, 216));
        brush31.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush31);
        QBrush brush32(QColor(56, 34, 16, 217));
        brush32.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush32);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush31);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush32);
        streaksLabel->setPalette(palette4);
        QFont font3;
        font3.setPointSize(14);
        streaksLabel->setFont(font3);
        captainPicture = new QLabel(centralwidget);
        captainPicture->setObjectName("captainPicture");
        captainPicture->setGeometry(QRect(770, 590, 141, 141));
        captainPicture->setPixmap(QPixmap(QString::fromUtf8(":/assets/captainPicture.jpg")));
        startScreenBackground = new QLabel(centralwidget);
        startScreenBackground->setObjectName("startScreenBackground");
        startScreenBackground->setEnabled(true);
        startScreenBackground->setGeometry(QRect(0, 0, 1000, 750));
        startScreenBackground->setPixmap(QPixmap(QString::fromUtf8(":/assets/startScreenBackground.png")));
        newGameButton = new QPushButton(centralwidget);
        newGameButton->setObjectName("newGameButton");
        newGameButton->setGeometry(QRect(280, 280, 421, 141));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Bauhaus 93")});
        font4.setPointSize(45);
        newGameButton->setFont(font4);
        MainWindow->setCentralWidget(centralwidget);
        background->raise();
        textInputBox->raise();
        morsePrinter->raise();
        referenceSheetButton->raise();
        showAllButton->raise();
        streaksLabel->raise();
        CaptainDialogueBox->raise();
        CaptainDialogueText->raise();
        captainPicture->raise();
        startScreenBackground->raise();
        newGameButton->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 22));
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
        CaptainDialogueBox->setText(QString());
        CaptainDialogueText->setText(QCoreApplication::translate("MainWindow", "Captain Dialogue Text", nullptr));
        referenceSheetButton->setText(QString());
        showAllButton->setText(QCoreApplication::translate("MainWindow", "Show Entire Message", nullptr));
        streaksLabel->setText(QCoreApplication::translate("MainWindow", "Streak: 0", nullptr));
        captainPicture->setText(QString());
        startScreenBackground->setText(QString());
        newGameButton->setText(QCoreApplication::translate("MainWindow", "Start New Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
