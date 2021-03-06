#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <algorithm> // std::min_element, std::max_element
#include <numeric> // std::iota

int main() {
  // std::vector<int> vect;
  // for (int count = 0; count < 6; ++count) {
  //   vect.push_back(count);
  // }

  // std::vector<int>::const_iterator it;
  // it = vect.begin();
  // while (it != vect.end()) {
  //   std::cout << *it << ' ';
  //   ++it;
  // }
  // std::cout << '\n';

  // std::list<int> li;
  // for (int count = 0; count < 6; ++count) {
  //   li.push_back(count);
  // }
  // std::list<int>::const_iterator it;
  // it = li.begin();
  // while (it != li.end()) {
  //   std::cout << *it << ' ';
  //   ++it;
  // }
  // std::cout << '\n';

  // std::set<int> myset;
  // myset.insert(7);
  // myset.insert(6);
  // myset.insert(5);
  // myset.insert(5);
  // myset.insert(4);
  // myset.insert(-3);
  // myset.insert(2);
  // myset.insert(1);

  // std::set<int>::const_iterator it;
  // it = myset.begin();
  // while (it != myset.cend()) {
  //   std::cout << *it << ' ';
  //   ++it;
  // }
  // std::cout << '\n';

  // std::map<int, std::string> mymap;
  // mymap.insert(std::make_pair(1, "Subhash"));
  // mymap.insert(std::make_pair(4, "Kumari"));
  // mymap.insert(std::make_pair(2, "Chandra"));
  // mymap.insert(std::make_pair(3, "Swati"));

  // std::map<int, std::string>::const_iterator it { mymap.cbegin() };
  // while (it != mymap.end()) {
  //   std::cout << it->first << '=' << it->second << ' ';
  //   ++it;
  // }
  // std::cout << '\n';

  // std::list<int> li(6);
  // std::iota(li.begin(), li.end(), 0);

  // std::cout << 
  //   *std::min_element(li.begin(), li.end()) << ' ' <<
  //   *std::max_element(li.begin(), li.end()) << '\n';

  // std::list<int>::const_iterator it { std::find(li.begin(), li.end(), 3) };
  // li.insert(it, 8);

  // for (int i : li) {
  //   std::cout << i << ' ';
  // }
  // std::cout << '\n';

  std::vector<int> vect { 7, -3, 6, 2, -5, 0, 4 };
  std::sort(vect.begin(), vect.end());
  for (int i : vect) {
    std::cout << i << ' ';
  }
  std::cout << '\n';

  std::reverse(vect.begin(), vect.end());
  for (int i : vect) {
    std::cout << i << ' ';
  }
  std::cout << '\n';

  return 0;
}