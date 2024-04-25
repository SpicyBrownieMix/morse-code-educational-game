#include "mainwindow.h"
#include "model.h"
#include "ui_mainwindow.h"
#include <QtMultimedia>
#include "referencesheetdialog.h"
#include "showalldialog.h"
#include <Box2D/Box2D.h>
#include <QDebug>

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
    ui->centralwidget->setFixedSize(990, 740);

    referenceSheetDialog = new ReferenceSheetDialog(this);
    showAllDialog = new ShowAllDialog(this);

    //Set initial visibilites
    ui->CaptainDialogueBox->setVisible(false);
    ui->CaptainDialogueText->setVisible(false);
    ui->captainPicture->setVisible(false);
    ui->textInputBox->setVisible(false);
    ui->assessmentButton->setVisible(false);
    ui->assessmentButton->setEnabled(false);

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
    connect(ui->textInputBox, &QLineEdit::returnPressed, this, &MainWindow::textEditingComplete);
    connect(this, &MainWindow::submitTextInput, &model, &Model::textInputEntered);
    connect(&model, &Model::clearText, this, &MainWindow::clearInputBox);

    // on-screen connections
    connect(&model, &Model::playDotSound, this, &MainWindow::playDotSound);
    connect(&model, &Model::playDashSound, this, &MainWindow::playDashSound);
    connect(&model, &Model::sendMorseChar, this, &MainWindow::recieveMorseChar);
    connect(&model, &Model::clearMorseBox, this, &MainWindow::clearMorseBox);

    // captain connections
    //connect(&model, &Model::toggleCaptain, this, &MainWindow::toggleCaptain);
    connect(&model, &Model::sendCaptainText, this, &MainWindow::showCaptainText);
    connect(&model, &Model::showCaptain, this, [this]{captainVisibility(true);});
    connect(&model, &Model::hideCaptain, this, [this]{captainVisibility(false);});

    // popups
    connect(ui->referenceSheetButton, &QPushButton::clicked, this, &MainWindow::showRefrenceSheet);
    connect(ui->showAllButton, &QPushButton::clicked, this, &MainWindow::showEntireMessage);

    // streak connections
    connect(&model, &Model::updateStreak, this, &MainWindow::showCurrentStreak);
    connect(this, &MainWindow::refrenceOpened, &model, &Model::resetStreak);
    connect(&model, &Model::streakHighEnough, this, &MainWindow::showAssessment);

    // start screen connections
    connect(ui->newGameButton, &QAbstractButton::pressed, this, &MainWindow::startNewGame);
    connect(ui->newGameButton, &QAbstractButton::pressed, &model, &Model::startNewGame);

    //send entire message
    connect(&model, &Model::sendFullMessage, this, &MainWindow::receiveFullMessage);

    //reference sheet
    connect(&model, &Model::sendLevel, this, &MainWindow::receiveLevelNumber);

    //assessment connection
    connect(ui->assessmentButton, &QPushButton::pressed, &model, &Model::assessmentStarted);

    connect(this, &MainWindow::captainFinishedTalking, &model, &Model::captainFinishedTalking);

    timeStep = 1.0f/60.0f;
    velocityIterations = 6;
    positionIterations = 2;
    initializeBox2D();

    //Motion start timer
    QTimer* startMotionTimer = new QTimer(this);
    connect(startMotionTimer, &QTimer::timeout, this, &MainWindow::startMoving);
    startMotionTimer->start(10000);

    //Motion active timer
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateBox2D);

    //Captain timer
    QTimer* captainTimer = new QTimer(this);
    connect(captainTimer, &QTimer::timeout, this, &MainWindow::moveCaptain);
    captainTimer->start(50);
    captainElapsedTime = 0;

    //test, delete later
    referenceSheetDialog->setModal(true);
    referenceSheetDialog->show();
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

void MainWindow::captainVisibility(bool show)
{
    ui->CaptainDialogueBox->setVisible(show);
    ui->CaptainDialogueText->setVisible(show);
    ui->captainPicture->setVisible(show);
}

void MainWindow::showCaptainText(QString text)
{
    typingText = "";
    ui->CaptainDialogueText->setText("");
    toBeTyped = text;
    typeCaptainText();
}

void MainWindow::typeCaptainText()
{
    // if this is the end of the string, stop writing to the screen and clear previous text
    if (toBeTyped.size() == 0)
    {
        QTimer::singleShot(1000, this, [this] {emit captainFinishedTalking();});
        return;
    }

    // type one letter at a time by getting the first char of the toBeTyped string and typing it, then removing that letter.
    QChar c = toBeTyped.front();
    toBeTyped = toBeTyped.mid(1);
    typingText.append(c);
    ui->CaptainDialogueText->setText(typingText);
    QTimer::singleShot(30, this, &MainWindow::typeCaptainText);
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

void MainWindow::showCurrentStreak(int streak, bool assessmentUnlocked)
{
    if(streak == 0 && !assessmentUnlocked)
        hideAssessment();
    ui->streaksLabel->setText("Streak: " + QString::number(streak));
}

void MainWindow::moveCaptain()
{
    world->Step(timeStep, velocityIterations, positionIterations);

    captainElapsedTime += timeStep;

    b2Vec2 position = captainBody->GetPosition();

    float32 amplitude = 10.0f;
    float32 frequency = 0.5f;
    float32 displacement = amplitude * sin(2 * b2_pi * frequency * captainElapsedTime);

    //Move captain position up and down.
    ui->captainPicture->move(ui->captainPicture->x(), displacement + position.y);
}

void MainWindow::initializeBox2D()
{
    b2Vec2 gravity(0.0f, -10.0f);
    world = new b2World(gravity);

    //Background
    b2BodyDef backgroundBodyDef;
    backgroundBodyDef.type = b2_staticBody;
    backgroundBodyDef.position.Set(0.0f, 0.0f);
    backgroundBody = world->CreateBody(&backgroundBodyDef);

    b2PolygonShape backgroundShape;
    backgroundShape.SetAsBox(1000, 750);

    b2FixtureDef backgrounFixtureDef;
    backgrounFixtureDef.shape = &backgroundShape;
    backgroundBody->CreateFixture(&backgrounFixtureDef);

    //Captain
    b2BodyDef captainBodyDef;
    captainBodyDef.type = b2_staticBody;
    captainBodyDef.position.Set(770.0f, 590.0f);
    captainBody = world->CreateBody(&captainBodyDef);

    b2PolygonShape captainShape;
    backgroundShape.SetAsBox(1, 1);

    b2FixtureDef captainFixtureDef;
    captainFixtureDef.shape = &captainShape;
    captainFixtureDef.density = 1.0f;

    // Override the default friction.
    captainFixtureDef.friction = 0.3f;
    captainFixtureDef.restitution = 0.9f;
    captainBody->CreateFixture(&captainFixtureDef);
}


void MainWindow::updateBox2D()
{
    timerCounter++;

    //Stop moving so that it isnt constant.
    if(timerCounter >= 50)
    {
        timer->stop();
        return;
    }

    world->Step(timeStep, velocityIterations, positionIterations);

    elapsedTime += timeStep;

    b2Vec2 backgroundPos = backgroundBody->GetPosition();

    float32 amplitude = 10.0f;
    float32 frequency = 0.5f;
    float32 displacement = amplitude * sin(2 * b2_pi * frequency * elapsedTime);

    //Moves the background and all other visible parts of the screen that should move as well.
    ui->background->move(backgroundPos.x + displacement, backgroundPos.y + displacement);
    ui->textInputBox->move(backgroundPos.x + displacement + 280, backgroundPos.y + displacement + 465);
    ui->assessmentButton->move(backgroundPos.x + displacement + 549, backgroundPos.y + displacement + 180);
    ui->referenceSheetButton->move(backgroundPos.x + displacement + 90, backgroundPos.y + displacement + 610);
    ui->showAllButton->move(backgroundPos.x + displacement + 420, backgroundPos.y + displacement + 390);
    ui->streaksLabel->move(backgroundPos.x + displacement + 280, backgroundPos.y + displacement + 180);
}

void MainWindow::startMoving()
{
    timerCounter = 0;
    timer->start(100);
    elapsedTime = 0.0f;
}

void MainWindow::receiveFullMessage(string s)
{
    showAllDialog->setText(s);
}

void  MainWindow::receiveLevelNumber(int level)
{
    referenceSheetDialog->setBatch(level);
}

void MainWindow::showAssessment()
{
    ui->assessmentButton->setVisible(true);
    ui->assessmentButton->setEnabled(true);
}

void MainWindow::hideAssessment()
{
    ui->assessmentButton->setVisible(false);
    ui->assessmentButton->setEnabled(false);
}

void MainWindow::clearInputBox()
{
    ui->textInputBox->clear();
}
