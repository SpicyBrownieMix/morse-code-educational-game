#include "showalldialog.h"
#include "ui_showalldialog.h"
#include <QDebug>
#include <QLabel>
#include <QVBoxLayout>
#include <QString>
#include <QFont>
#include <QDebug>

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
