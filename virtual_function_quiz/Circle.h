#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "Shape.h"
#include "Point.h"

class Circle : public Shape {
  private:
    Point m_center;
    int m_radius;
  public:
    Circle(const Point& center, int radius);

    virtual std::ostream& print(std::ostream& out) const override;
    int getRadius() const;
};

#endif