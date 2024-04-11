#include "model.h"
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QTimer>

using namespace std;

Model::Model(QObject *parent) : QObject{parent}
{
    onScreenLetterCounter = 0;
    morseString = "";
    fillMorseAlphabetMap();

    QTimer::singleShot(1000, this, [this]() {sendMorse("supercalifragilistic");});
}

void Model::textInputEntered(QString text)
{
    emit toggleCaptain();   // REMOVE LATER
    emit sendCaptainText(text); // REMOVE LATER
    //Receive text and check it against the correct letters.
}

void Model::fillMorseAlphabetMap()
{
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

void Model::sendMorse(string word)
{
    for (char c : word)
    {
        morseString += MORSE_ALPHABET.at(c) + "  ";
    }

    QTimer::singleShot(100, this, &Model::sendMorseHelper);
}

void Model::sendMorseHelper()
{
    // if there are already 3 letters on screen, clear them before writing new ones
    if (onScreenLetterCounter == 6)
    {
        emit clearMorseBox();
        onScreenLetterCounter = 0;
    }

    // if this is the end of the string, stop going.
    if (morseString.size() == 0)
        return;

    // send the first letter of the string to the view, and then remove that letter from the string.
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
