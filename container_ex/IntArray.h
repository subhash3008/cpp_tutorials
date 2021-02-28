#ifndef INTARRAY_H
#define INTARRAY_H

#include <cassert>
#include <initializer_list>

class IntArray {
  private:
    int m_length {};
    int *m_data {};
  public:
    IntArray() = default;

    IntArray(int length): m_length { length } {
      assert (length >= 0);
      if (length > 0) {
        m_data = new int[length] {};
      }
    }

    IntArray(std::initializer_list<int> list): IntArray(static_cast<int>(list.size())) {
      int count { 0 };
      for (auto el: list) {
        m_data[count] = el;
        ++count;
      }
    }

    ~IntArray() {
      delete[] m_data;
    }

    IntArray(const IntArray&) = delete;
    IntArray& operator=(const IntArray& list) = delete;

    IntArray& operator=(std::initializer_list<int> list) {
      int length { static_cast<int>(list.size()) };
      if (length != m_length) {
        delete[] m_data;
        m_length = length;
        m_data = new int[length] {};
      }
      int count { 0 };
      for (auto el: list) {
        m_data[count] = el;
        ++count;
      }
      return *this;
    }

    void erase() {
      delete[] m_data;
      m_data = nullptr;
      m_length = 0;
    }

    int& operator[] (int index) {
      assert(index >= 0 && index < m_length);
      return m_data[index];
    }

    int getLength() const {
      return m_length;
    }

    void reallocate(int newLength) {
      erase();
      if (newLength <= 0) {
        return;
      }
      m_data = new int[newLength];
      m_length = newLength;
    }

    void resize(int newLength) {
      if (newLength == m_length) {
        return;
      }
      if (newLength <= 0) {
        erase();
        return;
      }
      int* data { new int[newLength] };
      if (m_length > 0) {
        int elementsToCopy { (newLength > m_length) ? newLength : m_length };
        for (int index { 0 }; index < elementsToCopy; index++) {
          data[index] = m_data[index];
        }
        delete[] m_data;
        m_data = data;
        m_length = newLength;
      }
    }

    void insertBefore(int value, int index) {
      assert(index >= 0 && index <= m_length);
      int* data { new int[m_length + 1] };
      for (int x { 0 }; x < index; x++) {
        data[x] = m_data[x];
      }
      data[index] = value;
      for (int y { index }; y < m_length; y++) {
        data[y+1] = m_data[y];
      }
      delete[] m_data;
      m_data = data;
      ++m_length;
    }

    void remove(int index) {
      assert(index >= 0 && index < m_length);
      if (m_length == 1) {
        erase();
        return;
      }
      int* data { new int[m_length - 1] };
      for (int x { 0 }; x < index; x++) {
        data[x] = m_data[x];
      }
      for (int y { index + 1 }; y < m_length; y++) {
        data[y - 1] = m_data[y];
      }
      delete[] m_data;
      m_data = data;
      --m_length;
    }

    void insertAtBeginning(int value) {
      insertBefore(value, 0);
    }

    void insertAtEnd(int value) {
      insertBefore(value, m_length);
    }

};

#endif