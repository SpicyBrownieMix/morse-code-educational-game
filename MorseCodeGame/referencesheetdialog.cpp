#include "referencesheetdialog.h"
#include "ui_referencesheetdialog.h"

ReferenceSheetDialog::ReferenceSheetDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ReferenceSheetDialog)
{
    ui->setupUi(this);
}

ReferenceSheetDialog::~ReferenceSheetDialog()
{
    delete ui;
}

