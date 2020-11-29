/*****************************************************************************/
/* Project: Guess The Word                                                   */
/* Module: Game Manager                                                      */
/* Description: Manages all the logic behind the game                        */
/* Author: Ali Abu-El-Magd                                                   */
/*****************************************************************************/
#include "gamemanager.h"


GameManager::GameManager()
{
    dictionairy = RandomWord(":/txt/dict.txt");
}

void GameManager::newGame()
{
    theWord = dictionairy.getRandomWord();
}
