#ifndef CREATURE_H
#define CREATURE_H

#include <string>

class Creature {
  protected:
    std::string m_name;
    char m_symbol;
    int m_health;
    int m_damage_capacity;
    int m_gold_balance;
  public:
    Creature(const std::string& name, char symbol, int health, int damageCapacity, int goldBalance):
      m_name { name },
      m_symbol { symbol },
      m_health { health },
      m_damage_capacity { damageCapacity },
      m_gold_balance { goldBalance }
    {}

    const std::string& getName() const;
    void setName(const std::string& name);
    char getSymbol() const;
    void setSymbol(const char symbol);
    int getHealth() const;
    void setHealth(const int health);
    int getDamageCapacity() const;
    void setDamageCapacity(const int damageCapacity);
    int getGoldBalance() const;
    void setGoldBalance(const int goldBalance);

    void reduceHealth(const int health);
    bool isDead() const;
    void addGold(const int goldReceived);

};

#endif