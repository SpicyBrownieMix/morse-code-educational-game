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
    assessmentUnlocked = false;
    sendingMorse = false;
    captainTalking = false;

    // populate constant data structure with information from text files
    fillMorseAlphabetMap();
    fillCaptainDialogList();
    fillLetterLevelList();
    fillAssessmentList();
    setUpTextfile();
}

void Model::startNewGame()
{
    // start captain's dialog
    emit showCaptain();
    sendCaptainDialog(QString::fromStdString(*captainRanting));
    advance(captainRanting,1);
}

void Model::captainFinishedTalking()
{
    captainTalking = false;
    if (awaitingAnswer)
        return;

    // check if the captain has more to say or if this is the end of the current schpeal
    if (captainRanting != (*captainDialogIt).end())
    {
        // check if we should be displaying letters right now
        if (*captainRanting == "dl")
        {
            practicingLetter = true;
            advance(captainDialogIt,1);
            captainRanting = (*captainDialogIt).begin();
            displayLetter();
            return;
        }
        // check if we should be practicing letters right now
        if (*captainRanting == "pl")
        {
            advance(captainDialogIt,1);
            captainRanting = (*captainDialogIt).begin();
            practiceLetter();
            return;
        }
        // check if we should be practicing words
        if (*captainRanting == "pw")
        {
            practicingLetter = false;
            advance(captainDialogIt,1);
            captainRanting = (*captainDialogIt).begin();
            emit hideCaptain();
            pickRandomWord();
            return;
        }
        // if not, then send the cap's next dialog line.
        emit showCaptain();
        sendCaptainDialog(QString::fromStdString(*captainRanting));
        advance(captainRanting,1);
    }
    else
    {
        advance(captainDialogIt,1);
        captainRanting = (*captainDialogIt).begin();
        captainFinishedTalking();
    }
}

void Model::displayLetter()
{
    if (sendingMorse)
    {
        QTimer::singleShot(500, this, [this] {displayLetter();});
        return;
    }

    advance(letterLevelsIt, 1);
    string letter(1, *letterLevelsIt);
    emit showCaptain();
    sendCaptainDialog(QString::fromStdString(*captainRanting));
    advance(captainRanting, 1);
    emit clearMorseBox();
    sendMorse(letter);
}

void Model::practiceLetter()
{
    if (sendingMorse)
    {
        QTimer::singleShot(500, this, [this] {practiceLetter();});
        return;
    }

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
    emit showCaptain();
    sendCaptainDialog(QString::fromStdString(*captainRanting));
    advance(captainRanting, 1);

    // display the letter
    emit clearMorseBox();
    sendMorse(letter);
}


void Model::textInputEntered(QString text)
{
    // If the user is inputing things when they don't need to be, ignore it.
    if (!awaitingAnswer || sendingMorse || captainTalking)
        return;

    emit hideCaptain();
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
        emit showCaptain();
        sendCaptainDialog("Oops, that's not quite right! Give it another try.");
    }
}

void Model::wordTextInput(QString text)
{
    bool correct = true;

    //Receive text and check it against the correct letters.
    QString incorrectString = "Hmm, looks like some of these letters are wrong... try again, and give the reference sheet a peek if you feel stuck. The wrong ones are: ";
    if(text.length() != message.length())
    {
        correct = false;
        incorrectString = "Oops! This translation is the wrong length... give it another go!  ";
    }
    else
    {
        for (unsigned char i = 0; i < message.length(); i++)
        {
            if(text[i] != message[i])
            {
                incorrectString.append(text[i]);
                incorrectString.append(", ");
                correct = false;
            }
        }
    }

    if(!correct)
    {
        if(takingAssessment)
        {
            incorrectString = "Oh no! Looks like you got that wrong. Why don't you try again?  ";
        }
        resetStreak();
        incorrectString.erase(incorrectString.end()-2, incorrectString.end());
        emit showCaptain();
        sendCaptainDialog(incorrectString);
    }
    else
    {
        awaitingAnswer = false;
        emit clearText();

        if(takingAssessment)
        {
            emit showCaptain();
            captainFinishedTalking();
            level++;
            takingAssessment = false;
            assessmentUnlocked = false;
            resetStreak();
            setUpTextfile();
            return;
        }

        streak++;
        emit updateStreak(streak, assessmentUnlocked);

        if (!talkedAboutStreak && streak >= 3)
        {
            // captain teaches the user about the streak function
            emit showCaptain();
            talkedAboutStreak = true;
            captainFinishedTalking();
            return;
        }
        if (streak == 5 && !assessmentUnlocked)
        {
            emit showCaptain();
            captainFinishedTalking();
            assessmentUnlocked = true;
            emit streakHighEnough();
            return;
        }
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
    captainRanting = captainDialog.front().begin();
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
        filename = ":/assets/levelTwoWords.txt";
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
    QFile file(":/assets/assesmentSentances.txt");
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
    sendingMorse = true;
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
    {
        sendingMorse = false;
        return;
    }

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
    emit updateStreak(streak, assessmentUnlocked);
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
    // if in the middle of sending a morse message, wait until it's finished.
    if (sendingMorse)
    {
        QTimer::singleShot(500, this, [this] {assessmentStarted();});
        return;
    }

    takingAssessment = true;
    emit clearMorseBox();
    message = *assessmentsIt;
    advance(assessmentsIt, 1);
    sendMorse(message);
}

void Model::sendCaptainDialog(QString text)
{
    captainTalking = true;
    emit sendCaptainText(text);
}
