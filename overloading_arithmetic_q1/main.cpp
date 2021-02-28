#include <iostream>

class Fraction {
  private:
    int m_num {};
    int m_den {};
  public:
    Fraction(int num, int den):
      m_num {num}, m_den {den}
    {
      reduce();
    }

    static int gcd (int a, int b) {
      return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
    }

    void reduce() {
      if (m_num != 0 && m_den != 0) {
        int gcd { Fraction::gcd(m_num, m_den) };
        m_num /= gcd;
        m_den /= gcd;
      }
    }

    void print() const {
      std::cout << m_num << "/" << m_den << '\n';
    }

    friend Fraction operator* (const Fraction& f1, const Fraction& f2);
    // friend Fraction operator* (Fraction& f1, Fraction& f2, Fraction& f3);
    friend Fraction operator* (const Fraction& f1, int x);
    friend Fraction operator* (int x, const Fraction& f1);
};

Fraction operator* (const Fraction& f1, const Fraction& f2) {
  return { (f1.m_num * f2.m_num), (f1.m_den * f2.m_den) };
}

// Fraction operator* (Fraction& f1, Fraction& f2, Fraction& f3) {
//   return Fraction((f1.m_num * f2.m_num * f3.m_num), (f1.m_den * f2.m_den * f3.m_den));
// }

Fraction operator* (const Fraction& f1, int x) {
  return { (f1.m_num * x), f1.m_den };
}

Fraction operator* (int x, const Fraction& f1) {
  return { (x * f1.m_num), f1.m_den };
}


int main() {
  Fraction f1 { 2, 5 };
  f1.print();

  Fraction f2 { 3, 8 };
  f2.print();

  Fraction f3 { f1 * f2 };
  f3.print();

  Fraction f4 { f1 * 2 };
  f4.print();

  Fraction f5{ 2 * f2 };
  f5.print();

  Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
  f6.print();

  return 0;
}