#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "model.h"
#include <QMainWindow>
#include <string>
#include <QtMultimedia>
#include "motion.h"
#include "referencesheetdialog.h"
#include "showalldialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Model& model, QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void submitTextInput(QString text);
    void refrenceOpened();
    void timerTimeout();

public slots:
    void textEditingComplete();
    void playDotSound();
    void playDashSound();
    void recieveMorseChar(std::string s);
    void clearMorseBox();
    void toggleCaptain();
    void showCaptainText(QString text);
    void showRefrenceSheet();
    void showEntireMessage();
    void showCurrentStreak(int streak);
    void moveCaptain(int yPos);

private:
    Motion motion;
    Ui::MainWindow *ui;
    Model* model;
    QMediaPlayer *dotPlayer;
    QAudioOutput *dotAudioOutput;
    QMediaPlayer *dashPlayer;
    QAudioOutput *dashAudioOutput;
    ReferenceSheetDialog* referenceSheetDialog;
    ShowAllDialog* showAllDialog;
    bool captainMovingUp;

    // Box2D
    b2World* world;
    b2Body* backgroundBody;
    float32 timeStep;
    int32 velocityIterations;
    int32 positionIterations;

    void initializeBox2D();
    void updateBox2D();

    float elapsedTime;
};
#endif // MAINWINDOW_H
