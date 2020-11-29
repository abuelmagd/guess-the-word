/*****************************************************************************/
/* Project: Guess The Word                                                   */
/* Module: Random Word                                                       */
/* Description: Generates a random word from a given dictionary file         */
/* Author: Ali Abu-El-Magd                                                   */
/*****************************************************************************/
#include "randomword.h"
#include <QFile>
#include <QTextStream>
#include <QRandomGenerator>

RandomWord::RandomWord()
{

}
RandomWord::RandomWord(QString path)
{
    dictionarySize = 0;
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        gameDictionary.append(line);
        dictionarySize++;
    }
    file.close();
}

QString RandomWord::getRandomWord()
{
    QRandomGenerator *randomness = QRandomGenerator::system();
    if(dictionarySize>0)
    {
        return gameDictionary.at(randomness->bounded(dictionarySize-1));
    }
    else return "bomba";
}
