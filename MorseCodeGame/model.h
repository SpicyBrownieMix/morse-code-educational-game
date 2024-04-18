#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <iostream>
#include <QTimer>
#include <Box2D/Box2D.h>

class Model : public QObject
{
    Q_OBJECT

public:
    explicit Model(QObject *parent = nullptr);

public slots:
    void textInputEntered(QString text);
    void resetStreak();
    void startNewGame();

signals:
    void sendMorseChar(std::string s);
    void playDotSound();
    void playDashSound();
    void clearMorseBox();
    void toggleCaptain();
    void sendCaptainText(QString text);
    void updateStreak(int streak);

private:

    std::map<char,std::string> MORSE_ALPHABET; // maps the letters of the alphabet to morse code
    int onScreenLetterCounter; // counts the current number of morse letters on screen
    std::string morseString; // the string of morse characters representing the current word or sentance being shown to the user.
    std::string message;
    int streak; //Counts the user's current streak.
    int level; //The level the user is currently on.
    QStringList currentWords; //The words that are in the current text file;

    /**
     * @brief fillMorseAlphabetMap
     * reads from the morseAlphabet.txt file to fill in the MORSE_ALPHABET map
     */
    void fillMorseAlphabetMap();
    /**
     * @brief chooseRandomWord
     * chooses a random word from one of the text files full of words. Which text file is used depends on the level
     * the user is at, as there are different sets of words for each level.
     */
    //void chooseRandomWord();
    /**
     * @brief sendMorse
     * Translates a word into a morse code string, and then sends the dots or dashes to the view on a regular basis so that it looks like it's "typing"
     */
    void sendMorse(std::string word);
    void sendMorseHelper();

    /**
     * @brief sendNewWord
     * Sends a new random word to be displayed on screen.
     */
    void sendNewWord();

    /**
     * @brief setUpTextfile
     * Gets all the words from the current level's text file. Call every time the level is updated.
     */
    void setUpTextfile();

};

#endif // MODEL_H
