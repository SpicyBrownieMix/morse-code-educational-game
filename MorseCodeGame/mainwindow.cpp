#include "mainwindow.h"
#include "model.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QtMultimedia>

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

    ui->CaptainDialogueBox->setVisible(false);
    ui->CaptainDialogueText->setVisible(false);

    // setup player for "dot" sound
    dotPlayer = new QMediaPlayer;
    dotAudioOutput = new QAudioOutput;
    dotPlayer->setAudioOutput(dotAudioOutput);
    dotAudioOutput->setVolume(50);
    dotPlayer->setSource(QUrl("qrc:/assets/MorseDotSound.mp3"));

    // setup player for "dash" sound
    dashPlayer = new QMediaPlayer;
    dashAudioOutput = new QAudioOutput;
    dashPlayer->setAudioOutput(dashAudioOutput);
    dashAudioOutput->setVolume(50);
    dashPlayer->setSource(QUrl("qrc:/assets/MorseDashSound.mp3"));

    connect(ui->textInputBox, &QLineEdit::editingFinished, this, &MainWindow::textEditingComplete);
    connect(this, &MainWindow::submitTextInput, &model, &Model::textInputEntered);

    connect(&model, &Model::playDotSound, this, &MainWindow::playDotSound);
    connect(&model, &Model::playDashSound, this, &MainWindow::playDashSound);
    connect(&model, &Model::sendMorseChar, this, &MainWindow::recieveMorseChar);
    connect(&model, &Model::clearMorseBox, this, &MainWindow::clearMorseBox);

    connect(&model, &Model::toggleCaptain, this, &MainWindow::toggleCaptain);
    connect(&model, &Model::sendCaptainText, this, &MainWindow::showCaptainText);
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
    dashPlayer->play();
}

void MainWindow::playDotSound()
{
    dotPlayer->play();
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

void MainWindow::toggleCaptain()
{
    ui->CaptainDialogueBox->setVisible(!ui->CaptainDialogueBox->isVisible());
    ui->CaptainDialogueText->setVisible(!ui->CaptainDialogueText->isVisible());
}

void MainWindow::showCaptainText(QString text)
{
    ui->CaptainDialogueText->setText(text);
}
