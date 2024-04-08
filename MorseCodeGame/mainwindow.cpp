#include "mainwindow.h"
#include "model.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(Model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->model = &model;

    connect(ui->textInputBox, &QLineEdit::editingFinished, this, &MainWindow::textEditingComplete);
    connect(this, &MainWindow::submitTextInput, &model, &Model::textInputEntered);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::textEditingComplete()
{
    emit submitTextInput(ui->textInputBox->displayText());
}
