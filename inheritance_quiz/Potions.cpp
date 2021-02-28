#include <string>
#include <array>
#include "Potions.h"
#include "utils.h"

std::string getPotionTypeName(PotionType type) {
  static std::array<std::string, 3> names {
    "Health",
    "Strength",
    "Poison"
  };
  return names.at(static_cast<std::size_t>(type));
}

std::string getPotionSizeName(PotionSize size) {
  static std::array<std::string, 3> sizes {
    "Small",
    "Medium",
    "Large"
  };
  return sizes.at(static_cast<std::size_t>(size));
}

PotionType Potion::getType() const {
  return m_type;
}

PotionSize Potion::getSize() const {
  return m_size;
}

const std::string Potion::getName() const {
  std::string size { getPotionSizeName(getSize()) };
  std::string type { getPotionTypeName(getType()) };
  return (size + " potion of " + type);
}

Potion Potion::getRandomPotion() {
  return {
    static_cast<PotionType>(getRandomNumber(0, (static_cast<int>(PotionType::max_type) - 1))),
    static_cast<PotionSize>(getRandomNumber(0, (static_cast<int>(PotionSize::max_size) - 1)))
  };
}

