#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "model.h"
#include <QMainWindow>
#include <string>
#include <QtMultimedia>
#include <QString>
#include "referencesheetdialog.h"
#include "showalldialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow
     * The constructor, initializes variables, does set up actions, and connects signals and slots.
     * @param model, the model created in main.cpp
     * @param parent, the parent widget.
     */
    MainWindow(Model& model, QWidget *parent = nullptr);
    ~MainWindow();

signals:
    /**
     * @brief submitTextInput
     * When the user presses return sends the text in the textbox to the model to check for correctness.
     * @param text, the text to check.
     */
    void submitTextInput(QString text);

    /**
     * @brief refrenceOpened
     * Sends out a signal when the refrence sheet was opened, used for updating the streak counter.
     */
    void refrenceOpened();
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
     * @brief showCaptainText
     * when the model sends the captain something to say, call typeCaptainText to type it on screen
     * (this method is needed because typeCaptainText is recursive and cannot take a parameter).
     * @param text -- The text to be typed.
     */
    void showCaptainText(QString text);
    void showRefrenceSheet();
    void showEntireMessage();
    void showCurrentStreak(int streak, bool assessmentUnlocked);


    void startNewGame();
    void receiveFullMessage(std::string s);

    /**
     * @brief clearInputBox
     * Clears all text from the user input box.
     */
    void clearInputBox();

    /**
     * @brief showAssessment
     * Shows and enables the assesment button.
     */
    void showAssessment();

private:
    Ui::MainWindow *ui; // ui
    Model* model; // the ui's copy of the model.
    QMediaPlayer *dotPlayer; // media player for the dot sound.
    QAudioOutput *dotAudioOutput; // audio output for the dot sound.
    QMediaPlayer *dashPlayer; // media player for the dash sound.
    QAudioOutput *dashAudioOutput; // audio output for the dash sound.
    ReferenceSheetDialog* referenceSheetDialog;
    ShowAllDialog* showAllDialog;
    QString typingText; // the captain's dialog text that has already been typed
    QString toBeTyped; // the captain's dialog text that has yet to be typed.
    float elapsedTime; //The elapsed time for the ship movement
    float captainElapsedTime; //The elapsed time for the captain movement
    b2World* world; // Box2D world object for physics simulation.
    b2Body* backgroundBody; // Body representing the background in the Box2D world.
    b2Body* captainBody; // Body representing the captain character in the Box2D world.
    float32 timeStep; // Time step for the Box2D simulation.
    int32 velocityIterations; // Number of velocity iterations for the Box2D solver.
    int32 positionIterations; // Number of position iterations for the Box2D solver.
    int timerCounter; //Counts how many times the ship movement has changed.
    QTimer* timer; //The timer for the box2d movement.

    /**
    * @brief Initializes the Box2D world with necessary bodies and fixtures.
    *
    * This function sets up the Box2D world with gravity and creates bodies and fixtures
    * for the background and the captain's character. It sets their positions, shapes,
    * and physical properties such as density, friction, and restitution.
    *
    */
    void initializeBox2D();

    /**
    * @brief Updates the Box2D simulation and moves UI elements based on simulation results.
    *
    * This function is responsible for updating the Box2D simulation and adjusting the positions
    * of UI elements according to the simulated physics. It increments a timer counter and stops
    * the timer if it reaches a certain threshold to limit simulation updates. It then advances
    * the Box2D world simulation, calculates displacement based on a sine wave formula to simulate
    * a floating motion effect, and moves various UI elements accordingly relative to the background
    * position.This function is called periodically to update the Box2D simulation and UI positions.
    */
    void updateBox2D();
    /**
    *  @brief Move the captain's picture on the main window.
    *
    * This function is responsible for updating the position of the captain's picture
    * based on the physics simulation of the captain's body in the Box2D world.
    * This function is called periodically to update the captain's motion.
    */
    void moveCaptain();

    /**
    * @brief Starts the motion simulation and resets necessary variables.
    *
    * This function is responsible for starting the motion simulation by resetting
    * the timer counter and starting a QTimer with a specified interval. It also
    * resets the elapsed time variable to zero, preparing the simulation for a fresh start.
    * This function is called to initiate the motion simulation.
    */
    void startMoving();

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

    /**
     * @brief captainVisibility
     * Turn's the captain's dialog box, picture, and background on or off (depends on the previous state).
     */
    void captainVisibility(bool show);
};
#endif // MAINWINDOW_H
