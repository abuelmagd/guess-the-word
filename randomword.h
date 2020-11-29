/*****************************************************************************/
/* Project: Guess The Word                                                   */
/* Module: Random Word                                                       */
/* Description: Generates a random word from a given dictionary file         */
/* Author: Ali Abu-El-Magd                                                   */
/*****************************************************************************/
#ifndef RANDOMWORD_H
#define RANDOMWORD_H
#include <QString>
#include <QStringList>


class RandomWord
{
public:
    RandomWord();
    RandomWord(QString);
    QString getRandomWord();

private:
    QStringList gameDictionary;
    int dictionarySize;
};

#endif // RANDOMWORD_H
