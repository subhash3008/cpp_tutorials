#include <iostream>
#include "IntArray.h"

int main() {
  // IntArray arr(10);

  // for (int i { 0 }; i < 10; i++) {
  //   arr[i] = i + 1;
  // }
  // arr.resize(8);
  // arr.insertBefore(20, 5);
  // arr.remove(3);
  // arr.insertAtEnd(30);
  // arr.insertAtBeginning(40);

  IntArray arr { 5, 4, 3, 2, 1};

  for (int i { 0 }; i < arr.getLength(); i++) {
    std::cout << arr[i] << ' ';
  }

  std::cout << '\n';

  arr = { 1, 3, 5, 7, 9, 11 };

	for (int count{ 0 }; count < arr.getLength(); ++count)
		std::cout << arr[count] << ' ';

	std::cout << '\n';

  return 0;
}