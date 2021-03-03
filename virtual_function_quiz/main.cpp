#include <iostream>
#include <vector>
#include "Circle.h"
#include "Triangle.h"
#include "Point.h"

int getLargestRadius(const std::vector<Shape*> &v) {
  int largestRadius { 0 };
  for (const auto* el : v) {
    if (auto* c { dynamic_cast<const Circle*>(el) }) {
      if (c->getRadius() > largestRadius) {
        largestRadius = c->getRadius();
      }
    }
  }
  return largestRadius;
}


int main() {
  // Circle c { Point { 1, 2, 3 }, 7 };
  // std::cout << c <<'\n';

  // Triangle t { Point { 1, 2, 3 }, Point { 4, 5, 6 }, Point { 7, 8, 9 } };
  // std::cout << t << '\n';

  std::vector<Shape*> v {
    new Circle { Point { 1, 2, 3 }, 7 },
    new Triangle { Point { 1, 2, 3 }, Point { 4, 5, 6 }, Point { 7, 8, 9 } },
    new Circle { Point { 4, 5, 6 }, 3 }
  };

  for (const auto* el : v) {
    std::cout << *el << '\n';
  }

  std::cout << "The largest radius is " << getLargestRadius(v) << '\n';

  for (const auto* el : v) {
    delete el;
  }
  return 0;
}