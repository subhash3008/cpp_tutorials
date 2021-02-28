#include <iostream>
#include <cstdint>
#include <cmath>

class FixedPoint2 {
  private:
    std::int_least16_t m_base {};
    std::int_least8_t m_fraction {};
  public:
    FixedPoint2 (std::int_least16_t base = 0, std::int_least8_t fraction = 0)
    : m_base { base }, m_fraction { fraction } {
      if (m_base < 0 || m_fraction < 0 ) {
        if (m_base > 0) {
          m_base = -m_base;
        }
        if (m_fraction > 0) {
          m_fraction = -m_fraction;
        }
      }
    }

    FixedPoint2 (double d): 
      m_base { static_cast<std::int_least16_t>(d) },
      m_fraction { static_cast<std::int_least8_t>(std::round((d - static_cast<std::int_least16_t>(d)) * 100)) }
    {}

    operator double() const {
      return m_base + (static_cast<double>(m_fraction)) / 100.0;
    }

    friend std::ostream& operator<< (std::ostream& out, const FixedPoint2& fp) {
      out << static_cast<double>(fp);
      return out;
    }
};

int main() {
  // FixedPoint2 a { 34, 56 };
  // std::cout << a << '\n';

  // FixedPoint2 b { -2, 8 };
  // std::cout << b << '\n';

  // FixedPoint2 c { 2, -8 };
  // std::cout << c << '\n';

  // FixedPoint2 d { -2, -8 };
  // std::cout << d << '\n';

  // FixedPoint2 e { 0 , -5 };
  // std::cout << e << '\n';

  FixedPoint2 a { 0.01 };
  std::cout << a << '\n';

  FixedPoint2 b { -0.01 };
  std::cout << b << '\n';

  FixedPoint2 c { 5.01 };
  std::cout << c << '\n';

  FixedPoint2 d { -5.01 };
  std::cout << d << '\n';

  return 0;
}