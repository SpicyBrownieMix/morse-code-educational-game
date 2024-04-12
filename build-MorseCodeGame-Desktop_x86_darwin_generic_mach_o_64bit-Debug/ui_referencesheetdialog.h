/********************************************************************************
** Form generated from reading UI file 'referencesheetdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REFERENCESHEETDIALOG_H
#define UI_REFERENCESHEETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_ReferenceSheetDialog
{
public:

    void setupUi(QDialog *ReferenceSheetDialog)
    {
        if (ReferenceSheetDialog->objectName().isEmpty())
            ReferenceSheetDialog->setObjectName("ReferenceSheetDialog");
        ReferenceSheetDialog->resize(480, 640);

        retranslateUi(ReferenceSheetDialog);

        QMetaObject::connectSlotsByName(ReferenceSheetDialog);
    } // setupUi

    void retranslateUi(QDialog *ReferenceSheetDialog)
    {
        ReferenceSheetDialog->setWindowTitle(QCoreApplication::translate("ReferenceSheetDialog", "Reference Sheet", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReferenceSheetDialog: public Ui_ReferenceSheetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REFERENCESHEETDIALOG_H
