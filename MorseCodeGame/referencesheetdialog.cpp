#include "referencesheetdialog.h"
#include "ui_referencesheetdialog.h"
#include <QFont>
#include <QLabel>
#include <QHBoxLayout>
#include <QString>

/** This class was made for the Assignment 9, Educational App, in CS3505 at the University of Utah.
 *
 * @brief The ReferenceSheetDialog class
 * This class implemnts the methods outlined in the ReferenceSheetDialog.h class
 *
 * @version April 2024
 * @author Spencer Hoth
 */

ReferenceSheetDialog::ReferenceSheetDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ReferenceSheetDialog)
{
    ui->setupUi(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    setLayout(mainLayout);

    batchOneLayout = new QVBoxLayout();
    mainLayout->addLayout(batchOneLayout);

    batchTwoLayout = new QVBoxLayout();
    mainLayout->addLayout(batchTwoLayout);

    batchThreeLayout = new QVBoxLayout();
    mainLayout->addLayout(batchThreeLayout);

    batchFourLayout = new QVBoxLayout();
    mainLayout->addLayout(batchFourLayout);

    batchFiveLayout = new QVBoxLayout();
    mainLayout->addLayout(batchFiveLayout);

    batchSixLayout = new QVBoxLayout();
    mainLayout->addLayout(batchSixLayout);

    setBatch(1);
}

ReferenceSheetDialog::~ReferenceSheetDialog()
{
    delete ui;
}

void ReferenceSheetDialog::setBatch(int batch)
{
    switch(batch)
    {
    case 1:
        addMorseCode(batchOneLayout, "a", "•-");
        addMorseCode(batchOneLayout, "e", "•");
        addMorseCode(batchOneLayout, "i", "••");
        addMorseCode(batchOneLayout, "t", "-");
        addMorseCode(batchOneLayout, "n", "-•");
        addMorseCode(batchOneLayout, "r", "•-•");
        addMorseCode(batchOneLayout, ".", "•-•-•-");
        break;
    case 2:
        addMorseCode(batchTwoLayout, "o", "---");
        addMorseCode(batchTwoLayout, "u", "••-");
        addMorseCode(batchTwoLayout, "l", "•-••");
        addMorseCode(batchTwoLayout, "s", "•••");
        addMorseCode(batchTwoLayout, "", "");
        addMorseCode(batchTwoLayout, "", "");
        addMorseCode(batchTwoLayout, "", "");
        break;
    case 3:
        addMorseCode(batchThreeLayout, "d", "-••");
        addMorseCode(batchThreeLayout, "y", "-•--");
        addMorseCode(batchThreeLayout, "c", "-•-•");
        addMorseCode(batchThreeLayout, "h", "••••");
        addMorseCode(batchThreeLayout, "", "");
        addMorseCode(batchThreeLayout, "", "");
        addMorseCode(batchThreeLayout, "", "");
        break;
    case 4:
        addMorseCode(batchFourLayout, "g", "--•");
        addMorseCode(batchFourLayout, "m", "--");
        addMorseCode(batchFourLayout, "p", "•--•");
        addMorseCode(batchFourLayout, "k", "-•-");
        addMorseCode(batchFourLayout, "", "");
        addMorseCode(batchFourLayout, "", "");
        addMorseCode(batchFourLayout, "", "");
        break;
    case 5:
        addMorseCode(batchFiveLayout, "b", "-•••");
        addMorseCode(batchFiveLayout, "f", "••-•");
        addMorseCode(batchFiveLayout, "w", "•--");
        addMorseCode(batchFiveLayout, "v", "•••-");
        addMorseCode(batchFiveLayout, "", "");
        addMorseCode(batchFiveLayout, "", "");
        addMorseCode(batchFiveLayout, "", "");
        break;
    case 6:
        addMorseCode(batchSixLayout, "z", "--••");
        addMorseCode(batchSixLayout, "x", "-••-");
        addMorseCode(batchSixLayout, "q", "--•-");
        addMorseCode(batchSixLayout, "j", "•---");
        addMorseCode(batchSixLayout, "", "");
        addMorseCode(batchSixLayout, "", "");
        addMorseCode(batchSixLayout, "", "");
        break;
    default:
        break;
    }
}



void ReferenceSheetDialog::addMorseCode(QVBoxLayout *layout, const QString &character, const QString &code)
{
    QLabel *label = new QLabel(this);
    QFont font;
    font.setPointSize(25);
    label->setFont(font);
    label->setText(QString("%1  %2").arg(character).arg(code));
    layout->addWidget(label);
}
