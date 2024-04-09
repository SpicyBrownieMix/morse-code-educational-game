#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <iostream>

class Model : public QObject
{
public:
    explicit Model(QObject *parent = nullptr);

public slots:
    void textInputEntered(QString text);

private:
    std::map<char,std::string> MORSE_ALPHABET; // maps the letters of the alphabet to morse code
    /**
     * @brief fillMorseAlphabetMap
     * reads from the morseAlphabet.txt file to fill in the MORSE_ALPHABET map
     */
    void fillMorseAlphabetMap();

};

#endif // MODEL_H
