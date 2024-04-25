#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <list>

class Model : public QObject
{
    Q_OBJECT

public:
    explicit Model(QObject *parent = nullptr);

public slots:
    /**
     * @brief textInputEntered
     * Checks entered text for correctness and does appropriate actions based on result and game state.
     * @param text, the text to check.
     */
    void textInputEntered(QString text);

    /**
     * @brief resetStreak
     * Sets the streak back to 0.
     */
    void resetStreak();
    void startNewGame();

    /**
     * @brief assessmentStarted
     * When the assessment button is clicked, starts the assessment for the user.
     */
    void assessmentStarted();

    /**
     * @brief captainFinishedTalking
     * When the view sends the signal that the captain has finished his previous sentance, this method
     * decides weather to send another sentance to the model or stop for now.
     */
    void captainFinishedTalking();


signals:
    /**
     * @brief sendMorseChar
     * Sends a single morse character to the view.
     * @param s
     */
    void sendMorseChar(std::string s);

    /**
     * @brief playDotSound
     * Signals the view to play the "dot" sound
     */
    void playDotSound();

    /**
     * @brief playDashSound
     * Signals the view to play the "dash" sound
     */
    void playDashSound();

    /**
     * @brief clearMorseBox
     * Signals the view to clear any morse code that is currently on screen
     */
    void clearMorseBox();

    /**
     * @brief showCaptain
     * Tells the main window to show the captain on the screen.
     */
    void showCaptain();

    /**
     * @brief hideCaptain
     * Tells the main window to hide the captain.
     */
    void hideCaptain();

    /**
     * @brief sendCaptainText
     * Sends the captain text to say.
     * @param text, the text to say.
     */
    void sendCaptainText(QString text);

    /**
     * @brief updateStreak
     * Tells the main window the streak has changed.
     * @param streak, the new value of the streak.
     */
    void updateStreak(int streak);
    void updateStreak(int streak, bool assessmentUnlocked);

    void sendFullMessage(std::string text);

    /**
     * @brief clearText
     * Clears the text from the input box.
     */
    void clearText();

    /**
     * @brief streakHighEnough
     * The streak is high enough to continue to the assesment if desired.
     */
    void streakHighEnough();

private:
    std::map<char,std::string> MORSE_ALPHABET; // maps the letters of the alphabet to morse code
    std::list<std::list<std::string>> captainDialog; // store the captain's dialog. A list which contains's chunks of dialog, broken into lists of readable parts
    std::list<std::list<std::string>>::iterator captainDialogIt; // iterator over captain's dialog
    std::list<std::string>::iterator captainRanting; // indicates that the captain has another dialog line after the current one &keeps track of the current line
    std::list<char> letterLevels; // the letters of the alphabet, in the order they are taught in the game
    std::list<char>::iterator letterLevelsIt; // iterator over the previous
    std::list<std::string> assessments; // the letters of the alphabet, in the order they are taught in the game
    std::list<std::string>::iterator assessmentsIt; // iterator over the previous
    QStringList currentWords; //The words that are in the current text file;
    int onScreenLetterCounter; // counts the current number of morse letters on screen
    std::string morseString; // the string of morse characters representing the current word or sentance being shown to the user.
    std::string message;
    int streak; //Counts the user's current streak.
    int level; //The level the user is currently on.
    bool practicingLetter; // indicates wether the user is practicing letters right now or not
    bool awaitingAnswer; // indicates if the program should be waiting for the user's answer
    bool talkedAboutStreak; // indicates wether the captain has talked about the streak yet.
    bool takingAssessment;

    /**
     * @brief fillMorseAlphabetMap
     * reads from the morseAlphabet.txt file to fill in the MORSE_ALPHABET map
     */
    void fillMorseAlphabetMap();

    /**
     * @brief fillCaptainDialogList
     * fill the captain dialog List (captainDialog) with lines from the captain dialog text file (captianStoryDialog.txt)
     */
    void fillCaptainDialogList();

    /**
     * @brief fillLetterLevelList
     * fill the letterLevel list (letterLevels) with the letters from the letterLevels.txt file
     */
    void fillLetterLevelList();

    /**
     * @brief fillAssessmentList
     * Fills the assessment list with the assessments from the text file.
     */
    void fillAssessmentList();

    /**
     * @brief sendMorse
     * Translates a word into a morse code string, and then sends the dots or dashes to the view on a regular basis so that it looks like it's "typing"
     */
    void sendMorse(std::string word);

    /**
     * @brief sendMorseHelper
     */
    void sendMorseHelper();

    /**
     * @brief pickRandomWord
     * chooses a random word from one of the text files full of words. Which text file is used depends on the level
     * the user is at, as there are different sets of words for each level.
     */
    void pickRandomWord();

    /**
     * @brief setUpTextfile
     * Gets all the words from the current level's text file. Call every time the level is updated.
     */
    void setUpTextfile();

    /**
     * @brief practiceLetter
     */
    void practiceLetter();

    /**
     * @brief practiceLetter
     */
    void displayLetter();

    void letterTextInput(QString text);
    void wordTextInput(QString text);
    void sendCaptainDialog(QString text);
};

#endif // MODEL_H
