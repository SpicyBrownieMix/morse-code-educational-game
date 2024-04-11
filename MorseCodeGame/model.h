#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <iostream>
#include <QTimer>

class Model : public QObject
{
    Q_OBJECT

public:
    explicit Model(QObject *parent = nullptr);

public slots:
    void textInputEntered(QString text);

signals:
    void sendMorseChar(std::string s);
    void playDotSound();
    void playDashSound();
    void clearMorseBox();
    void toggleCaptain();
    void sendCaptainText(QString text);

private:
    std::map<char,std::string> MORSE_ALPHABET; // maps the letters of the alphabet to morse code
    int onScreenLetterCounter; // counts the current number of morse letters on screen
    std::string morseString; // the string of morse characters representing the current word or sentance being shown to the user.
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



};

#endif // MODEL_H
