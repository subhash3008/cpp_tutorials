#ifndef GAME_HELPER_H
#define GAME_HELPER_H

#include "Player.h"
#include "Monster.h"

void fightMonster(Player& player); 
void attackPlayer(Monster& monster, Player& player);
void attackMonster(Monster& monster, Player& player);

#endif