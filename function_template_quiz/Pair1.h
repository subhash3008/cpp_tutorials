#ifndef PAIR1_H
#define PAIR1_H

template <class T>
class Pair1 {
  private:
    T m_x;
    T m_y;
  public:
    Pair1(const T& x, const T& y):
      m_x { x }, m_y { y }
    {}

    const T& first() const {
      return m_x;
    }

    const T& second() const {
      return m_y;
    }
};

#endif