#include "model.h"
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include<QApplication>

using namespace std;

Model::Model(QObject *parent) : QObject{parent}
{
    fillMorseAlphabetMap();
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
        MORSE_ALPHABET.insert(pair<char,string>(line[0], line.substr(2, 6)));
    }
}

void Model::textInputEntered(QString text)
{
    //Receive text and check it against the correct letters.
}
