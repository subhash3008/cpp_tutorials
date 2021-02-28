#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include "game_helper.h"

int main() {
  // Creature orc { "orc", 'o', 4, 2, 10 };
  // orc.addGold(5);
  // orc.reduceHealth(1);
  // std::cout << "The " << orc.getName() << " has " << orc.getHealth() << " health and is carrying " << orc.getGoldBalance() << " gold coins.\n";

  // std::cout << "Enter your name : ";
  // std::string name;
  // std::cin >> name;
  // Player player { name };

  // std::cout << "Welcome " << player.getName() << "!\n";
  // std::cout << "You have " << player.getHealth() << " health and are carrying " << player.getGoldBalance() << " gold coins.\n";

  // Monster m { Monster::Type::orc };
  // std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";

  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  std::rand();

  // for (int i { 0 }; i < 10; i++) {
  //   Monster m { Monster::getRandomMonster() };
  //   std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
  // }

  std::cout << "Enter your name : ";
  std::string playerName;
  std::cin >> playerName;
  Player player { playerName };
  std::cout << "Welcome, " << player.getName() << '\n';

  while(!player.isDead() && !player.hasWon()) {
    fightMonster(player);
  }

  if (player.isDead()) {
    std::cout << "You died at level " << player.getLevel() << " and with " << player.getGoldBalance() << " gold coins.\n";
    std::cout << "Too bad you cannot take it with you!\n";
  } else {
    std::cout << "You won the game with " << player.getGoldBalance() << " gold coins.\n";
  }

  return 0;
}