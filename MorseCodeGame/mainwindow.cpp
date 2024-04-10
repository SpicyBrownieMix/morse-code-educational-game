#include "mainwindow.h"
#include "model.h"
#include "ui_mainwindow.h"
#include <iostream>

using std::string;

/**
 * @brief MainWindow::MainWindow
 * @author Eva Giddings and others
 */

MainWindow::MainWindow(Model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->model = &model;

    connect(ui->textInputBox, &QLineEdit::editingFinished, this, &MainWindow::textEditingComplete);
    connect(this, &MainWindow::submitTextInput, &model, &Model::textInputEntered);

    connect(&model, &Model::playDotSound, this, &MainWindow::playDotSound);
    connect(&model, &Model::playDashSound, this, &MainWindow::playDashSound);
    connect(&model, &Model::sendMorseChar, this, &MainWindow::recieveMorseChar);
    connect(&model, &Model::clearMorseBox, this, &MainWindow::clearMorseBox);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::textEditingComplete()
{
    emit submitTextInput(ui->textInputBox->displayText());
}

void MainWindow::playDashSound()
{

}

void MainWindow::playDotSound()
{

}

void MainWindow::recieveMorseChar(string s)
{
    QString current = ui->morsePrinter->text();
    current += s;
    ui->morsePrinter->setText(current);
}

void MainWindow::clearMorseBox()
{
    ui->morsePrinter->setText("");
}
