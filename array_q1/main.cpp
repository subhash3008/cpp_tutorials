#include <array>
#include <numeric>
#include <iostream>

enum ItemTypes {
  item_health_potion,
  item_torch,
  item_arrow,
  max_items
};

using inventory_type = std::array<int, ItemTypes::max_items>;

int countTotalItems(const inventory_type& items) {
  return std::accumulate(items.begin(), items.end(), 0);
}

int main() {

  inventory_type items {2, 5, 10};

  std::cout << "The player has " << countTotalItems(items) << " item(s) in total." << std::endl;
  std::cout << "The player has " << items[ItemTypes::item_torch] << " torches.";

  return 0;
}