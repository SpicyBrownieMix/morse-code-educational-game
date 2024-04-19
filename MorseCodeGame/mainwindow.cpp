#include "mainwindow.h"
#include "model.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QtMultimedia>
#include "referencesheetdialog.h"
#include "showalldialog.h"
#include "motion.h"
#include <Box2D/Box2D.h>

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

    referenceSheetDialog = new ReferenceSheetDialog(this);
    showAllDialog = new ShowAllDialog(this);

    ui->CaptainDialogueBox->setVisible(false);
    ui->CaptainDialogueText->setVisible(false);
    ui->captainPicture->setVisible(false);
    ui->textInputBox->setVisible(false);

    //button look, make transparent
    ui->referenceSheetButton->setStyleSheet("background-color: rgba(255, 255, 255, 0); border: none;");

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

    // textbox
    connect(ui->textInputBox, &QLineEdit::editingFinished, this, &MainWindow::textEditingComplete);
    connect(this, &MainWindow::submitTextInput, &model, &Model::textInputEntered);

    // on-screen connections
    connect(&model, &Model::playDotSound, this, &MainWindow::playDotSound);
    connect(&model, &Model::playDashSound, this, &MainWindow::playDashSound);
    connect(&model, &Model::sendMorseChar, this, &MainWindow::recieveMorseChar);
    connect(&model, &Model::clearMorseBox, this, &MainWindow::clearMorseBox);

    // captain connections
    connect(&model, &Model::toggleCaptain, this, &MainWindow::toggleCaptain);
    connect(&model, &Model::sendCaptainText, this, &MainWindow::showCaptainText);

    // popups
    connect(ui->referenceSheetButton, &QPushButton::clicked, this, &MainWindow::showRefrenceSheet);
    connect(ui->showAllButton, &QPushButton::clicked, this, &MainWindow::showEntireMessage);

    // streak connections
    connect(&model, &Model::updateStreak, this, &MainWindow::showCurrentStreak);
    connect(this, &MainWindow::refrenceOpened, &model, &Model::resetStreak);

    // box2D connections
    connect(&motion, &Motion::newCaptainHeight, this, &MainWindow::moveCaptain);

    // start screen connections
    connect(ui->newGameButton, &QAbstractButton::pressed, this, &MainWindow::startNewGame);
    connect(ui->newGameButton, &QAbstractButton::pressed, &model, &Model::startNewGame);

    //send entire message
    connect(&model, &Model::sendFullMessage, this, &MainWindow::receiveFullMessage);

    timeStep = 1.0f/60.0f;
    velocityIterations = 6;
    positionIterations = 2;
    initializeBox2D();

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateBox2D);
    timer->start(100);
    elapsedTime = 0.0f;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete world;
}

void MainWindow::startNewGame()
{
    ui->startScreenBackground->setVisible(false);
    ui->newGameButton->setVisible(false);
    ui->newGameButton->setEnabled(false);
    ui->CaptainDialogueBox->setVisible(true);
    ui->captainPicture->setVisible(true);
    ui->CaptainDialogueText->setVisible(true);
    ui->textInputBox->setVisible(true);
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
    ui->captainPicture->setVisible(!ui->captainPicture->isVisible());
}

void MainWindow::showCaptainText(QString text)
{
    ui->CaptainDialogueText->setText(text);
}

void MainWindow::showRefrenceSheet()
{
    emit refrenceOpened();
    referenceSheetDialog->setModal(true);
    referenceSheetDialog->show();
}

void MainWindow::showEntireMessage()
{
    showAllDialog->setModal(true);
    showAllDialog->show();
}

void MainWindow::showCurrentStreak(int streak)
{
    ui->streaksLabel->setText("Streak: " + QString::number(streak));
}

void MainWindow::moveCaptain(int yPos)
{
    if(captainMovingUp)
        ui->captainPicture->setGeometry(QRect(ui->captainPicture->x(), ui->captainPicture->y() + yPos, 141, 141));
    else
        ui->captainPicture->setGeometry(QRect(ui->captainPicture->x(), ui->captainPicture->y() - yPos, 141, 141));

    captainMovingUp = !captainMovingUp;
}

void MainWindow::initializeBox2D()
{
    b2Vec2 gravity(0.0f, -10.0f);
    world = new b2World(gravity);

    b2BodyDef backgroundBodyDef;
    backgroundBodyDef.type = b2_staticBody;
    backgroundBodyDef.position.Set(0.0f, 0.0f);
    backgroundBody = world->CreateBody(&backgroundBodyDef);

    b2PolygonShape backgroundShape;
    backgroundShape.SetAsBox(1000, 750);

    b2FixtureDef backgrounFixtureDef;
    backgrounFixtureDef.shape = &backgroundShape;
    backgroundBody->CreateFixture(&backgrounFixtureDef);
}


void MainWindow::updateBox2D()
{
    world->Step(timeStep, velocityIterations, positionIterations);

    elapsedTime += timeStep;

    b2Vec2 backgroundPos = backgroundBody->GetPosition();

    float32 amplitude = 10.0f;
    float32 frequency = 0.5f;
    float32 displacement = amplitude * sin(2 * b2_pi * frequency * elapsedTime);

    ui->background->move(backgroundPos.x + displacement, backgroundPos.y + displacement);
}

void MainWindow::receiveFullMessage(string s)
{
    showAllDialog->setText(s);
}
