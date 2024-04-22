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
    fillMorseAlphabetMap();
    fillCaptainDialogList();
    level = 1;
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
    if (captainTalking != (*captainDialogIt).end())
    {
        emit sendCaptainText(QString::fromStdString(*captainTalking));
        advance(captainTalking,1);
    }
    else
    {
        advance(captainDialogIt,1);
        captainTalking = (*captainDialogIt).begin();
    }
}

void Model::textInputEntered(QString text)
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

