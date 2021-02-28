#include <iostream>
#include <limits>

class Fraction {
  private:
    int m_num {};
    int m_den {};
  public:
    Fraction(int num = 0, int den = 1):
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

    friend std::ostream& operator<< (std::ostream& out, const Fraction& f1);
    friend std::istream& operator>> (std::istream& in, Fraction& f1);
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

std::ostream& operator<< (std::ostream& out, const Fraction& f1) {
  out << f1.m_num << '/' << f1.m_den;
  return out;
}

std::istream& operator>> (std::istream& in, Fraction& f1) {
  in >> f1.m_num;
  in.ignore(std::numeric_limits<std::streamsize>::max(), '/');
  in >> f1.m_den;
  f1.reduce();
  return in;
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

  Fraction f7 {};
  std::cout << "Enter fraction 7 : ";
  std::cin >> f7;

  Fraction f8 {};
  std::cout << "Enter fraction 8 : ";
  std::cin >> f8;

  std::cout << f7 << " * " << f8 << " is " << f7 * f8 << '\n';

  return 0;
}