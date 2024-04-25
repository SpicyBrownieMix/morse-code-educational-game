/********************************************************************************
** Form generated from reading UI file 'showalldialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWALLDIALOG_H
#define UI_SHOWALLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_ShowAllDialog
{
public:

    void setupUi(QDialog *ShowAllDialog)
    {
        if (ShowAllDialog->objectName().isEmpty())
            ShowAllDialog->setObjectName("ShowAllDialog");
        ShowAllDialog->resize(320, 240);

        retranslateUi(ShowAllDialog);

        QMetaObject::connectSlotsByName(ShowAllDialog);
    } // setupUi

    void retranslateUi(QDialog *ShowAllDialog)
    {
        ShowAllDialog->setWindowTitle(QCoreApplication::translate("ShowAllDialog", "Message", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowAllDialog: public Ui_ShowAllDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWALLDIALOG_H
