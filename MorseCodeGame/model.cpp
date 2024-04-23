#include "model.h"
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include <list>

using namespace std;

Model::Model(QObject *parent) : QObject{parent}
{
    onScreenLetterCounter = 0;
    morseString = "";
    message = "";
    streak = 0;
    level = 1;
    awaitingAnswer = false;
    practicingLetter = false;

    // populate constant data structure with information from text files
    fillMorseAlphabetMap();
    fillCaptainDialogList();
    fillLetterLevelList();
    setUpTextfile();
}

void Model::startNewGame()
{
    // start captain's dialog
    emit sendCaptainText(QString::fromStdString(*captainTalking));
    advance(captainTalking,1);
}

void Model::captainFinishedTalking()
{
    // check if the captain has more to say or if this is the end of the current schpeal
    if (captainTalking != (*captainDialogIt).end())
    {
        // check if we should be displaying letters right now
        if (*captainTalking == "dl")
        {
            practicingLetter = true;
            advance(captainDialogIt,1);
            captainTalking = (*captainDialogIt).begin();
            displayLetter();
            return;
        }
        // check if we should be practicing letters right now
        if (*captainTalking == "pl")
        {
            if (awaitingAnswer)
                return;
            advance(captainDialogIt,1);
            captainTalking = (*captainDialogIt).begin();
            practiceLetter();
            return;
        }
        // if not, then send the cap's next dialog line.
        emit sendCaptainText(QString::fromStdString(*captainTalking));
        advance(captainTalking,1);
    }
    else
    {
        advance(captainDialogIt,1);
        captainTalking = (*captainDialogIt).begin();
    }
}

void Model::displayLetter()
{
    emit clearMorseBox();
    advance(letterLevelsIt, 1);
    string letter(1, *letterLevelsIt);
    emit sendCaptainText(QString::fromStdString(*captainTalking));
    advance(captainTalking, 1);
    emit sendMorse(letter);
}

void Model::practiceLetter()
{
    // enable text box etc.
    emit clearMorseBox();
    awaitingAnswer = true;
    string letter;

    // choose one of the two letters shown.
    int random = arc4random() % 2;
    if (random == 0 || *(message.c_str()) == *letterLevelsIt)
        letter = string(1,  *(prev(letterLevelsIt)));
    else if (random == 1 || *(message.c_str()) == *(prev(letterLevelsIt)))
        letter = string(1, *letterLevelsIt);
    message = letter;

    // send cap's dialog
    emit sendCaptainText(QString::fromStdString(*captainTalking));
    advance(captainTalking, 1);

    // display the letter
    emit sendMorse(letter);
}


void Model::textInputEntered(QString text)
{
    if (!awaitingAnswer)
        return;
    if (practicingLetter)
        letterTextInput(text);
    else
        wordTextInput(text);
}

void Model::letterTextInput(QString text)
{
    char lower = *(message.c_str());
    char upper = lower - 26;
    if (text == lower || text == upper)
    {
        awaitingAnswer = false;
        captainFinishedTalking();
    }
    else
    {
         emit sendCaptainText("Oops, that's not quite right! Give it another try.");
    }
}

void Model::wordTextInput(QString text)
{
    bool correct = true;

    //Receive text and check it against the correct letters.
    QString incorrectString = "You got these wrong: ";
    if(text.length() != message.length())
    {
        correct = false;
        emit toggleCaptain();
        emit sendCaptainText("The message length is incorrect. Please try again.");
        resetStreak();
        //pickRandomWord();
        return;
    }

    for (unsigned char i = 0; i < message.length(); i++)
    {
        if(text[i] != message[i])
        {
            incorrectString.append(text[i]);
            incorrectString.append(", ");
            correct = false;
        }
    }

    if(!correct)
    {
        resetStreak();
        incorrectString.erase(incorrectString.end()-2, incorrectString.end());
        emit toggleCaptain();
        emit sendCaptainText(incorrectString);
    }
    else
    {
        emit clearText();
        streak++;
        emit updateStreak(streak);
        if(streak >= 5)
        {
            emit streakHighEnough();
        }
        emit toggleCaptain();
        emit sendCaptainText("Hooray, you got it right!");
        pickRandomWord();
    }
}

void Model::fillMorseAlphabetMap()
{
    // open the file that translates letters into morse
    QFile file(":/assets/morseAlphabet.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    // add the letter from the current line as the key and the morse code as the value
    QTextStream in(&file);
    while (!in.atEnd())
    {
        string line = in.readLine().toStdString();
        MORSE_ALPHABET.insert(pair<char,string>(line[0], line.substr(2)));
    }
    file.close();
}

void Model::fillCaptainDialogList()
{
    // open the file that translates letters into morse
    QFile file(":/assets/captainStoryDialog.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    // add all the dialog lines in this block to a list.
    // if we get to a clear space, add the list to captain dialog and clear list.
    QTextStream in(&file);
    list<string> list;
    while (!in.atEnd())
    {
        string line = in.readLine().toStdString();
        if (line.empty())
        {
            captainDialog.push_back(list);
            list.clear();
            continue;
        }
        list.push_back(line);
    }

    captainDialogIt = captainDialog.begin();
    captainTalking = captainDialog.front().begin();
    file.close();
}

void Model::fillLetterLevelList()
{
    // open the file that translates letters into morse
    QFile file(":/assets/letterLevels.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    // add the letter from the current line
    QTextStream in(&file);
    while (!in.atEnd())
    {
        char c = *in.readLine().toStdString().c_str();
        letterLevels.push_back(c);
    }

    letterLevelsIt = letterLevels.begin();
    file.close();
}

void Model::setUpTextfile()
{
    QString filename;
    currentWords.clear();

    if (level == 1)
        filename = ":/assets/levelOneWords";
    else if (level == 2)
        filename = ":/assets/levelTwoWords";
    else if (level == 3)
        filename = ":/assets/levelThreeWords";
    else if (level == 4)
        filename = ":/assets/levelFourWords";
    else if (level == 5)
        filename = ":/assets/levelFiveWords";
    else if (level == 6)
        filename = ":/assets/levelSixWords";
    else
        return;

    QFile file(filename);
    QTextStream stream(&file);

    if(file.open(QIODevice::ReadOnly))
    {
        while(!stream.atEnd())
        {
            QString word = stream.readLine();
            currentWords.push_back(word);
        }
    }
    file.close();
}

void Model::sendMorse(string word)
{
    for (char c : word)
    {
        morseString += MORSE_ALPHABET.at(c) + "  ";
    }

    QTimer::singleShot(100, this, &Model::sendMorseHelper);
    emit sendFullMessage(morseString);

}

void Model::sendMorseHelper()
{
    // if there are already 3 letters on screen, clear them before writing new ones
    if (onScreenLetterCounter == 6)
    {
        emit clearMorseBox();
        onScreenLetterCounter = 0;
    }

    // if this is the end of the string, stop writing to the screen.
    if (morseString.size() == 0)
        return;

    // send the first letter of the string to the view, and then remove that letter from the string.
    // tell the view to play the appropriate sound with the dot or dash
    char c = morseString[0];
    morseString = morseString.substr(1);
    if (c == '-')
    {
        emit playDashSound();
        QTimer::singleShot(600, this, &Model::sendMorseHelper);
        emit sendMorseChar("-");
    }
    else if (c == ' ')
    {
        QTimer::singleShot(100, this, &Model::sendMorseHelper);
        emit sendMorseChar(" ");
        onScreenLetterCounter++;
    }
    else if (c == '.')
    {
        emit playDotSound();
        QTimer::singleShot(600, this, &Model::sendMorseHelper);
        emit sendMorseChar("•");
    }
    else
        return;
}

void Model::resetStreak()
{
    streak = 0;
    emit updateStreak(streak);
}

void Model::pickRandomWord()
{
    //Pick a random word and display it.
    int random = arc4random() % (currentWords.size() - 1);
    QString word = currentWords.at(random).toLower();
    message = word.toStdString();
    QTimer::singleShot(1000, this, [word, this]() {sendMorse(message);});
}

void Model::assessmentStarted()
{
    //TODO: SEND THE ASSESMENT FOR THIS LEVEL
}
