#include "Creature.h"

const std::string& Creature::getName() const {
  return m_name;
}

void Creature::setName(const std::string& name) {
  m_name = name;
}

char Creature::getSymbol() const {
  return m_symbol;
}

void Creature::setSymbol(const char symbol) {
  m_symbol = symbol;
}

int Creature::getHealth() const {
  return m_health;
}

void Creature::setHealth(const int health) {
  m_health = health;
}

int Creature::getDamageCapacity() const {
  return m_damage_capacity;
}

void Creature::setDamageCapacity(const int damageCapacity) {
  m_damage_capacity = damageCapacity;
}

int Creature::getGoldBalance() const {
  return m_gold_balance;
}

void Creature::setGoldBalance(const int goldBalance) {
  m_gold_balance = goldBalance;
}

void Creature::reduceHealth(const int health) {
  m_health -= health;
}

bool Creature::isDead() const {
  return (m_health <= 0);
}

void Creature::addGold(const int goldReceived) {
  m_gold_balance += goldReceived;
}