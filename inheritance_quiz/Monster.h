#ifndef MONSTER_H
#define MONSTER_H

#include "Creature.h"

class Monster : public Creature {
  public:
    enum class Type {
      dragon,
      orc,
      slime,
      max_types
    };
  private:
    static const Creature& getDefaultCreature(Type type);
  public:
    Monster(Type type): Creature(getDefaultCreature(type))
    {}

    static Monster getRandomMonster();
};

#endif