#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <iostream>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <iterator>
#include <list>

class Model : public QObject
{
    Q_OBJECT

public:
    explicit Model(QObject *parent = nullptr);

public slots:
    void textInputEntered(QString text);
    void resetStreak();
    void startNewGame();
    void assessmentStarted();
    /**
     * @brief captainFinishedTalking
     * When the view sends the signal that the captain has finished his previous sentance, this method
     * decides weather to send another sentance to the model or stop for now.
     */
    void captainFinishedTalking();


signals:
    void sendMorseChar(std::string s); // sends a single morse character to the view.
    void playDotSound(); // signals the view to play the "dot" sound
    void playDashSound(); // signals the view to play the "dash" sound
    void clearMorseBox(); // signals the view to clear any morse code that is currently on screen
    void toggleCaptain(); // signals the view to either show or hide the captain, depending on the previous state.
    void sendCaptainText(QString text); // send the captain text to say.
    void updateStreak(int streak);
    void sendFullMessage(std::string text);
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
    std::list<std::string>::iterator captainTalking; // indicates that the captain has another dialog line after the current one &keeps track of the current line
    std::list<char> letterLevels; // the letters of the alphabet, in the order they are taught in the game
    std::list<char>::iterator letterLevelsIt; // iterator over the previous
    QStringList currentWords; //The words that are in the current text file;
    int onScreenLetterCounter; // counts the current number of morse letters on screen
    std::string morseString; // the string of morse characters representing the current word or sentance being shown to the user.
    std::string message;
    int streak; //Counts the user's current streak.
    int level; //The level the user is currently on.
    bool practicingLetter; // indicates weather the user is practicing letters, or full words.

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

    void letterTextInput(QString text);
    void wordTextInput(QString text);
};

#endif // MODEL_H
