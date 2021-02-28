#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
#include "Potions.h"

class Player : public Creature {
  private:
    int m_level;
  public:
    Player(std::string name): Creature(name, '@', 10, 1, 0), m_level { 1 }
    {}

    int getLevel() const;
    void setLevel(const int level);

    void levelUp();
    bool hasWon() const;

    void drinkPotion(const Potion& potion);
};

#endif