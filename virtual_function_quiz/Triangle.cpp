#include <iostream>
#include "Triangle.h"

std::ostream& Triangle::print(std::ostream& out) const {
  out << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ")\n";
  return out;
}
