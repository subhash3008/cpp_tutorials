#include <iostream>
#include <string>
#include <ctime>
#include <array>
#include <cstdlib>

class Monster {
  public:
    enum class Type {
      dragon,
      goblin,
      ogre,
      orc,
      skeleton,
      troll,
      vampire,
      zombie,
      max_monster_type
    };

  private:
    Type m_type {};
    std::string m_name {};
    std::string m_roar {};
    int m_hitPoints {};
  public:
    Monster(Type type, const std::string& name, const std::string& roar, int hitPoints):
      m_type {type}, m_name {name}, m_roar {roar}, m_hitPoints {hitPoints}
    {}

    std::string getString() const {
      switch(m_type) {
        case Type::dragon: return "dragon";
        case Type::goblin: return "goblin";
        case Type::ogre: return "ogre";
        case Type::orc: return "orc";
        case Type::skeleton: return "skeleton";
        case Type::troll: return "troll";
        case Type::vampire: return "vampire";
        case Type::zombie: return "zombie";
        default: "??";
      }
    }

    void print() const {
      std::cout << m_name << " the " << getString() << " has " << m_hitPoints << " hit points and says " << m_roar << ".\n";
    }
};

class MonsterGenerator {
  public:
    static int getRandomNumber(int min, int max) {
      static constexpr double fraction { 1.0 / (static_cast<double>(RAND_MAX) + 1)};
      return (static_cast<int>(std::rand() * fraction * (max - min + 1))) + min;
    }
    static Monster generateMonster() {
      auto type {static_cast<Monster::Type>(getRandomNumber(0, (static_cast<int>(Monster::Type::max_monster_type) - 1)))};
      int hitPoints { getRandomNumber(0, 100) };

      static constexpr std::array<const char*, 6> s_names { "Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans" };
      static constexpr std::array<const char*, 6> s_roars { "*ROAR*", "*PEEP*", "*SQUEAL*", "*WHINE*", "*HUM*", "*BURP*" };

      auto name { s_names[static_cast<std::size_t>(getRandomNumber(0, s_names.size() - 1))] };
      auto roar { s_roars[static_cast<std::size_t>(getRandomNumber(0, s_roars.size() - 1))] };

      return Monster { type, name, roar, hitPoints };
    }
};

int main() {
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  std::rand();
  Monster skeleton { MonsterGenerator::generateMonster() };
  skeleton.print();
  return 0;
}