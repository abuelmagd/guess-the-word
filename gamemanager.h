/*****************************************************************************/
/* Project: Guess The Word                                                   */
/* Module: Game Manager                                                      */
/* Description: Manages all the logic behind the game                        */
/* Author: Ali Abu-El-Magd                                                   */
/*****************************************************************************/
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QObject>
#include <QSet>
#include <QQuickWindow>
#include "randomword.h"

class GameManager : public QObject
{
    Q_OBJECT
public:
    GameManager(QObject *rootObject);

public slots:
    void newGame();
    void newGuess(QString);
private:
    RandomWord dictionairy;
    QString theWord;
    QString theGuess;
    QList<QChar> lettersTriedAndWrong;
    QSet<QChar> lettersRemaining;
    QObject *theWordQmlObject;
    QObject *wrongGuessesQmlObject;
    void setupWrongGuesses();
};

#endif // GAMEMANAGER_H
