#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include <QLabel>
#include <QGridLayout>
#include <QString>
#include <QFont>

/** This class was made for the Assignment 9, Educational App, in CS3505 at the University of Utah.
 *
 * @brief The AboutDialog class
 * This class implemnts the methods outlined in the AboutDialog.h class
 *
 * @version April 2024
 * @author Spencer Hoth
 */

AboutDialog::AboutDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    QLabel* titleLabel = new QLabel("Educational Morse Code App", this);
    QFont font;
    font.setPointSize(40);
    titleLabel->setFont(font);
    titleLabel->setWordWrap(true);

    QLabel* createdLabel = new QLabel("Created by Eva Giddings, Kaiya McCombs, Rishab Dixit, Spencer Hoth, Ryan Beard", this);
    QLabel* dateLabel = new QLabel("April 2024", this);
    QLabel* artworkLabel = new QLabel("All Artwork by Eva Giddings.", this);
    QLabel* classLabel = new QLabel("Created for The University of Utah's CS3505 - Software Practice II Spring 2024 class "
                                    "under the direction of professor Eric Heisler.", this);

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(titleLabel, 0, 0);
    layout->addWidget(dateLabel, 1, 1);
    layout->addWidget(createdLabel, 1, 0);
    layout->addWidget(artworkLabel, 2, 0);
    layout->addWidget(classLabel, 3, 0);
    layout->setRowStretch(4, 1);
    setLayout(layout);

}

AboutDialog::~AboutDialog()
{
    delete ui;
}
