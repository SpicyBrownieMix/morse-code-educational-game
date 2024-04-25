#include "mainwindow.h"
#include <QApplication>

/** This class was made for the Assignment 9, Educational App, in CS3505 at the University of Utah.
 *
 * @brief The Main class
 * Main is the class that starts and creates the program.
 *
 * This application is and Educational App that Teaches the user to read and listen to morse code. It teaahes
 * the letters of the alphabet and the period, but does not teach numbers. This program follows model-view
 * principles, with MainWindow being the view, which owns the Model (m/model).
 *
 * As a 1000 foot overview for perspective on the code:
 * This game operates in a progressive manner. In the game, the "Captain" is the tutorial and instructive guide,
 * who will tell the user how to play the game, teach them the letters, and generally guide progress. The captain's
 * dialog guides the progression of the game, both outwardly and in the code. Progress happens in levels. There are 6 levels,
 * in each of which the user learns 4-6 new letters. The game starts by teaching the user AIERNT, and then progresses four letters
 * each level (see letterLevels for the letters in the order they are learned). There are four things the
 * user can be doing at any given time: listening to the captain talk/explain; learning & practicing individual letters;
 * practicing words with the letters in the current tier; taking an assessment (which is more like a sentance) in order
 * to move to the next tier. Once they have learned all the letters, they can continue to practice as much as they want.
 *
 * All Artwork by Eva Giddings.
 *
 * @version April 2024
 * @author Eva Giddings, Kaiya McCombs, Rishab Dixit, Spencer Hoth, Ryan Beard
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model m;
    MainWindow w(m);
    w.show();
    return a.exec();
}
