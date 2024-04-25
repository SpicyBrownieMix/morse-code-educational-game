#include "showalldialog.h"
#include "ui_showalldialog.h"
#include <QDebug>
#include <QLabel>
#include <QVBoxLayout>
#include <QString>
#include <QFont>
#include <QDebug>

/** This class was made for the Assignment 9, Educational App, in CS3505 at the University of Utah.
 *
 * @brief The ShowAllDialog class
 * This class implemnts the methods outlined in the ShowAllDialog.h class
 *
 * @version April 2024
 * @author Eva Giddings and Spencer Hoth
 */

ShowAllDialog::ShowAllDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShowAllDialog)
{
    ui->setupUi(this);
    label = new QLabel(this);
    QFont font;
    font.setPointSize(40);
    label->setFont(font);
    label->setWordWrap(true);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label, 0, Qt::AlignTop);
    setLayout(layout);
}

ShowAllDialog::~ShowAllDialog()
{
    delete ui;
}

void ShowAllDialog::setText(std::string s)
{
    QString message = "";
    for(char c : s)
    {
        if (c == '.')
            message += "•";
        else
            message += c;
    }
    label->setText(message);
}
