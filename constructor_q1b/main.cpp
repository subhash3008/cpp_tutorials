#include <iostream>
#include <string>

class Ball {
  private:
    std::string m_color;
    double m_radius;
  public:
    Ball(double radius) {
      m_color = "black";
      m_radius = radius;
    }
    Ball(const std::string& color = "black", double radius = 10.0) {
      m_color = color;
      m_radius = radius;
    }

    void print() {
      std::cout << "Color : " << m_color << "\nRadius: " << m_radius << std::endl;
    }
};

int main() {
  Ball def{};
  def.print();

  Ball blue{"blue"};
  blue.print();

  Ball red {"red", 20.9};
  red.print();

  return 0;
}