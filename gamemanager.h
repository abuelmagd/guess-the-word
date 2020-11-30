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

enum enuState
{
    PLAYING,
    WON,
    LOST
};

#define TOO_MANY_WRONG_LETTERS 10

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
    enuState gameState;
    void setupWrongGuesses();
    void updateGameState();
    void updateUI();
};

#endif // GAMEMANAGER_H
