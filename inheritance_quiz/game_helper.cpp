#include <iostream>
#include "Monster.h"
#include "Player.h"
#include "utils.h"

// Monster is attacking player
void attackPlayer(Monster& monster, Player& player) {
  if (monster.isDead()) {
    return;
  }
  player.reduceHealth(monster.getDamageCapacity());
  std::cout << "The " << monster.getName() << " hit you for " << monster.getDamageCapacity() << " damage.\n";
}

// If monster is killed
void onMonsterKilled(Monster& monster, Player& player) {
  std::cout << "You killed the " << monster.getName() << ".\n";
  std::cout << "You found " << monster.getGoldBalance() << " gold.\n";
  player.levelUp();
  player.addGold(monster.getGoldBalance());

  constexpr int potionChance { 33 };
  if (getRandomNumber(1, 100) <= potionChance) {
    auto potion { Potion::getRandomPotion() };
    std::cout << "You found a mythical potion! Do you want to drink it? [y/n] : ";
    char choice {};
    std::cin >> choice;
    if (choice == 'Y' || choice == 'y') {
      player.drinkPotion(potion);
      std::cout << "You drank a " << potion.getName() << '\n';
    }
  }
}

// Player is attacking monster
void attackMonster(Monster& monster, Player& player) {
  if (player.isDead()) {
    return;
  }
  std::cout << "You hit the " << monster.getName() << " for " << player.getDamageCapacity() << " damage.\n";
  monster.reduceHealth(player.getDamageCapacity());

  if (monster.isDead()) {
    onMonsterKilled(monster, player);
  }
}

void fightMonster(Player& player) {
  Monster monster { Monster::getRandomMonster() };
  std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ").\n";

  while(!monster.isDead() && !player.isDead()) {
    std::cout << "(R)un or (F)ight : ";
    char playerInput;
    std::cin >> playerInput;
    if (playerInput == 'R' || playerInput == 'r') {
      if (getRandomNumber(1, 2) == 1) {
        std::cout << "You successfully escaped.\n";
        return;
      } else {
        std::cout << "You failed to escape.\n";
        attackPlayer(monster, player);
        continue;
      }
    }
    if (playerInput == 'F' || playerInput == 'f') {
      attackMonster(monster, player);
      attackPlayer(monster, player);
    }
  }

}