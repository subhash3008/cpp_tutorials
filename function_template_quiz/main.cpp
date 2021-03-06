#include <iostream>
#include "Pair1.h"
#include "Pair.h"

int main() {
  // Pair1<int> p1(5, 8);
  // std::cout << "Pair1 : " << p1.first() << " " << p1.second() << '\n';

  // const Pair1<double> p2(2.3, 4.5);
  // std::cout << "Pair1 : " << p2.first() << " " << p2.second() << '\n';

  // Pair<int, double> p1 { 1, 2.5 };
  // std::cout << "Pair : " <<  p1.first() << ' ' << p1.second() << '\n';

  // Pair<double, int> p2 { 3.7, 7 };
  // std::cout << "Pair : " << p2.first() << ' ' << p2.second() << '\n';

  StringValuePair<int> svp { "Hello", 5 };
  std::cout << "Pair : ( key : " << svp.first() << ", value : " << svp.second() << ")\n";

  return 0;
}