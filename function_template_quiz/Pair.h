#ifndef PAIR_H
#define PAIR_H

#include <string>

template <class T, class S>
class Pair {
  private:
    T m_x;
    S m_y;
  public:
    Pair(const T& x, const S& y):
      m_x { x }, m_y { y }
    {}

    const T& first() const {
      return m_x;
    }

    const S& second() const {
      return m_y;
    }
};

template <class S>
class StringValuePair : public Pair<std::string, S> {
  public:
    StringValuePair(const std::string& key, const S& value):
      Pair<std::string, S>(key, value)
    {}
};

#endif