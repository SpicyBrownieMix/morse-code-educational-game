#include "model.h"
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QTimer>

using namespace std;

Model::Model(QObject *parent) : QObject{parent}
{
    timerInterval = 100;
    morseString = "";
    fillMorseAlphabetMap();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Model::sendMorseHelper);
    QTimer::singleShot(1000, this, [this]() {sendMorse("cat");});
}

void Model::textInputEntered(QString text)
{
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

    char first = morseString[0];
    morseString = morseString.substr(1);
    if (first == '-')
    {
        emit sendMorseChar("-");
        emit playDashSound();
        timerInterval = 520;
    }
    else if (first == '.')
    {
        emit sendMorseChar("•");
        emit playDotSound();
        timerInterval = 392;
    }
    else
        return;

    timer->start(timerInterval);
}

void Model::sendMorseHelper()
{
    if (morseString.size() == 0)
    {
        timer->stop();
        return;
    }
    char c = morseString[0];
    morseString = morseString.substr(1);

    if (c == '-')
    {
        timerInterval = 520;
        emit sendMorseChar("-");
        emit playDashSound();
    }
    else if (c == ' ')
    {
        timerInterval = 500;
        emit sendMorseChar(" ");
    }
    else if (c == '.')
    {
        timerInterval = 392;
        emit sendMorseChar("•");
        emit playDotSound();
    }
    else
        return;
}
