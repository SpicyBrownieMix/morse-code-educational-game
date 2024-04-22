#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "model.h"
#include <QMainWindow>
#include <string>
#include <QtMultimedia>
#include <QString>
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
    void captainFinishedTalking();

public slots:
    void textEditingComplete();
    void playDotSound();
    void playDashSound();
    void recieveMorseChar(std::string s);
    /**
     * @brief clearMorseBox
     * Clears the morse code that is printed on the main screen.
     */
    void clearMorseBox();
    /**
     * @brief toggleCaptain
     * Turn's the captain's dialog box, picture, and background on or off (depends on the previous state).
     */
    void toggleCaptain();
    /**
     * @brief showCaptainText
     * when the model sends the captain something to say, call typeCaptainText to type it on screen
     * (this method is needed because typeCaptainText is recursive and cannot take a parameter).
     * @param text -- The text to be typed.
     */
    void showCaptainText(QString text);
    void showRefrenceSheet();
    void showEntireMessage();
    void showCurrentStreak(int streak);
    void moveCaptain(int yPos);
    void startNewGame();
    void receiveFullMessage(std::string s);
    void clearInputBox();
    /**
     * @brief showAssessment
     * Shows and enables the assesment button.
     */
    void showAssessment();

private:
    Ui::MainWindow *ui; // ui
    Model* model; // the ui's copy of the model.
    Motion motion;
    QMediaPlayer *dotPlayer; // media player for the dot sound.
    QAudioOutput *dotAudioOutput; // audio output for the dot sound.
    QMediaPlayer *dashPlayer; // media player for the dash sound.
    QAudioOutput *dashAudioOutput; // audio output for the dash sound.
    ReferenceSheetDialog* referenceSheetDialog;
    ShowAllDialog* showAllDialog;
    bool captainMovingUp;
    QString typingText; // the captain's dialog text that has already been typed
    QString toBeTyped; // the captain's dialog text that has yet to be typed.
    float elapsedTime;

    // Box2D
    b2World* world;
    b2Body* backgroundBody;
    float32 timeStep;
    int32 velocityIterations;
    int32 positionIterations;

    void initializeBox2D();
    void updateBox2D();
    /**
     * @brief hideAssessment
     * Hides and disables the assessment button.
     */
    void hideAssessment();
    /**
     * @brief typeCaptainText
     * When the captain recieves a message to "say," this method types it on screen, as if the captain
     * is speaking the words in real time.
     */
    void typeCaptainText();
};
#endif // MAINWINDOW_H
