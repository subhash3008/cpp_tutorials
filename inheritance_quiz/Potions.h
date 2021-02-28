#ifndef POTIONS_H
#define POTIONS_H

#include <string>

enum class PotionType {
  health,
  strength,
  poison,
  max_type
};

enum class PotionSize {
  small,
  medium,
  large,
  max_size
};

std::string getPotionTypeName(PotionType type);
std::string getPotionSizeName(PotionSize size);

class Potion {
  private:
    PotionType m_type {};
    PotionSize m_size {};
  public:
    Potion(PotionType type, PotionSize size):
      m_type { type }, m_size { size }
    {}

    PotionType getType() const;
    PotionSize getSize() const;

    const std::string getName() const;
    static Potion getRandomPotion();
};

#endif