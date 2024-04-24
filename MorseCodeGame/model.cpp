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
    talkedAboutStreak = false;
    takingAssessment = false;

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
    if (awaitingAnswer)
        return;

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
            advance(captainDialogIt,1);
            captainTalking = (*captainDialogIt).begin();
            practiceLetter();
            return;
        }
        // check if we should be practicing words
        if (*captainTalking == "pw")
        {
            practicingLetter = false;
            advance(captainDialogIt,1);
            captainTalking = (*captainDialogIt).begin();
            emit toggleCaptain();
            pickRandomWord();
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
        captainFinishedTalking();
    }
}

void Model::displayLetter()
{
    advance(letterLevelsIt, 1);
    string letter(1, *letterLevelsIt);
    emit sendCaptainText(QString::fromStdString(*captainTalking));
    advance(captainTalking, 1);
    emit clearMorseBox();
    emit sendMorse(letter);
}

void Model::practiceLetter()
{
    // enable text box etc.
    awaitingAnswer = true;
    string letter;

    // choose one of the two letters shown.
    int random = arc4random() % 2;
    if (random == 0)
        letter = string(1,  *(prev(letterLevelsIt)));
    if (random == 1)
        letter = string(1, *letterLevelsIt);
    if (*(message.c_str()) == *letterLevelsIt)
        letter = string(1,  *(prev(letterLevelsIt)));
    if(*(message.c_str()) == *(prev(letterLevelsIt)))
        letter = string(1, *letterLevelsIt);
    message = letter;

    // send cap's dialog
    emit sendCaptainText(QString::fromStdString(*captainTalking));
    advance(captainTalking, 1);

    // display the letter
    emit clearMorseBox();
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
    char upper = lower - 32;
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
    QString incorrectString = "Hmm, looks like some of these letters are wrong... try again, and give the refernce sheet a peek if you feel stuck. The wrong ones are: ";
    for (unsigned char i = 0; i < message.length(); i++)
    {
        if(text[i] != message[i])
        {
            incorrectString.append(text[i]);
            incorrectString.append(", ");
            correct = false;
        }
    }
    if(text.length() != message.length())
    {
        correct = false;
        emit toggleCaptain();
        incorrectString = "Oops! This translation is the wrong length... give it another go!  ";
        resetStreak();
        return;
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
        awaitingAnswer = false;
        if (!talkedAboutStreak && streak >= 2)
        {
            // captain teaches the user about the streak function
            emit toggleCaptain();
            talkedAboutStreak = true;
            captainFinishedTalking();
            return;
        }
        if (streak >= 5)
        {
            captainFinishedTalking();
            emit streakHighEnough();
        }
        //emit toggleCaptain();
        //sendCaptainText("Hooray, you got it right!");
        //emit toggleCaptain();
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

void Model::fillAssessmentList()
{
    // open the file that translates letters into morse
    QFile file(":/assets/assessmentSentances.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    // add the letter from the current line as the key and the morse code as the value
    QTextStream in(&file);
    while (!in.atEnd())
    {
        string line = in.readLine().toStdString();
        assessments.push_back(line);
    }

    assessmentsIt = assessments.begin();
    file.close();
}

void Model::sendMorse(string word)
{
    for (char c : word)
    {
        morseString += MORSE_ALPHABET.at(c) + "  ";
    }

    morseString.erase(morseString.end()-1, morseString.end());
    onScreenLetterCounter = 0;
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
    else if (c == '/')
    {
        QTimer::singleShot(800, this, &Model::sendMorseHelper);
        emit sendMorseChar("");
        onScreenLetterCounter = 0;
        emit clearMorseBox();
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
    // Pick a random word and display it.
    emit clearMorseBox();
    awaitingAnswer = true;
    int random = arc4random() % (currentWords.size() - 1);
    QString word = currentWords.at(random).toLower();
    message = word.toStdString();
    sendMorse(message);
}

void Model::assessmentStarted()
{
    takingAssessment = true;
    emit clearMorseBox();
    message = *assessmentsIt;
    advance(assessmentsIt, 1);
    sendMorse(message);
}
