#include "showalldialog.h"
#include "ui_showalldialog.h"

ShowAllDialog::ShowAllDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShowAllDialog)
{
    ui->setupUi(this);
}

ShowAllDialog::~ShowAllDialog()
{
    delete ui;
}
