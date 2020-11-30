/*****************************************************************************/
/* Project: Guess The Word                                                   */
/* Module: Game Manager                                                      */
/* Description: Manages all the logic behind the game                        */
/* Author: Ali Abu-El-Magd                                                   */
/*****************************************************************************/
#include "gamemanager.h"

GameManager::GameManager(QObject *rootObject)
{

    theWordQmlObject = rootObject->findChild<QObject*>("TheWord");
    wrongGuessesQmlObject = rootObject->findChild<QObject*>("WrongGuesses");
    QQuickWindow *window = qobject_cast<QQuickWindow *>(rootObject);
    QObject::connect(window, SIGNAL(newGameButtonClick()), this, SLOT(newGame()));
    QObject::connect(window, SIGNAL(newLetterGuess(QString)), this, SLOT(newGuess(QString)));
    dictionairy = RandomWord(":/txt/dict.txt");
    newGame();
}

void GameManager::newGame()
{
    for(int i=0; i<26; i++)
        lettersRemaining.insert(QChar('a'+i));
    lettersTriedAndWrong.clear();
    theWord = dictionairy.getRandomWord();
    theGuess.clear();
    for(int i=0; i<theWord.length();i++)
        theGuess.append('-');
    theWordQmlObject->setProperty("text", theGuess);

    gameState = PLAYING;
    theWordQmlObject->setProperty("state", "playing");
    wrongGuessesQmlObject->setProperty("state", "playing");
    setupWrongGuesses();
}

void GameManager::newGuess(QString K)
{
    QChar guessLetter = K[0];
    if(gameState != PLAYING) return;
    if(lettersRemaining.contains(guessLetter))
    {
        bool notFound = true;
        lettersRemaining.remove(guessLetter);
        for(int i=0; i<theWord.length();i++)
        {
            if(theWord.at(i) == guessLetter)
            {
                notFound = false;
                theGuess[i] = guessLetter;
            }
        }
        theWordQmlObject->setProperty("text", theGuess);
        if(notFound) lettersTriedAndWrong.append(guessLetter);
        setupWrongGuesses();
    }
    updateGameState();
}

void GameManager::setupWrongGuesses()
{
    QString wrongTries = " ";
    for(int i=0; i<lettersTriedAndWrong.length();i++)
    {
        wrongTries.append(lettersTriedAndWrong.at(i));
        wrongTries.append(' ');
    }
    wrongGuessesQmlObject->setProperty("text", wrongTries);
}

void GameManager::updateGameState()
{
    if(lettersTriedAndWrong.length() == TOO_MANY_WRONG_LETTERS)
    {
        gameState = LOST;
        theWordQmlObject->setProperty("state", "lost");
        wrongGuessesQmlObject->setProperty("state", "lost");
    }
    else if (theGuess == theWord)
    {
        gameState = WON;
        theWordQmlObject->setProperty("state", "won");
        wrongGuessesQmlObject->setProperty("state", "won");
    }
}
