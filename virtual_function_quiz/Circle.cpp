#include <iostream>
#include "Circle.h"
#include "Point.h"
#include "Shape.h"

Circle::Circle(const Point& center, int radius):
  m_center { center }, m_radius { radius }
{}

std::ostream& Circle::print(std::ostream& out) const {
  out << "Circle(" << m_center << ", radius " << m_radius << ")\n";
  return out;
}

int Circle::getRadius() const {
  return m_radius;
}