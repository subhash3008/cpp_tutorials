#include "Player.h"
#include "Potions.h"

int Player::getLevel() const {
  return m_level;
}

void Player::setLevel(const int level) {
  m_level = level;
}

void Player::levelUp() {
  ++m_level;
  ++m_damage_capacity;
}

bool Player::hasWon() const {
  return (m_level >= 20);
}

void Player::drinkPotion(const Potion& potion) {
  switch(potion.getType()) {
    case PotionType::health:
      m_health += ((potion.getSize() == PotionSize::large ? 5 : 2));
      break;
    case PotionType::strength:
      ++m_damage_capacity;
      break;
    case PotionType::poison:
      --m_health;
      break;
    case PotionType::max_type:
      break;
  }
}