/*****************************************************************************/
/* Project: Guess The Word                                                   */
/* Module: Game Manager                                                      */
/* Description: Manages all the logic behind the game                        */
/* Author: Ali Abu-El-Magd                                                   */
/*****************************************************************************/
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QObject>
#include "randomword.h"

class GameManager : public QObject
{
    Q_OBJECT
public:
    GameManager();

public slots:
    void newGame();

private:
    RandomWord dictionairy;
    QString theWord;
};

#endif // GAMEMANAGER_H
