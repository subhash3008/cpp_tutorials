#include <iostream>
#include <fstream>
#include <string>
// #include <algorithm> // std::all_of
// #include <cctype> // std::isalph, std::isspace

// bool isValidName(const std::string& name) {
//   return std::all_of(name.begin(), name.end(), [](char ch) {
//     return (std::isalpha(ch) || std::isspace(ch));
//   });
// }

int main() {
  // std::string name {};
  // do {
  //   std::cout << "Please enter your name : ";
  //   std::getline(std::cin, name);
  // } while(!isValidName(name));

  // std::cout << "Hello " << name << "!!\n";

  // std::ofstream outf { "Sample.txt" };
  // if (!outf) {
  //   std::cerr << "Oops! Sample could not be opened for writing.\n";
  //   return 1;
  // }

  // outf << "This is line 1\n";
  // outf << "This is line 2\n";

  std::ifstream inf { "Sample.txt" };
  if (!inf) {
    std::cout << "Oops!! Sample file could not be opened for reading.\n";
    return 1;
  }
  while (inf) {
    std::string strInp;
    // inf >> strInp;
    std::getline(inf, strInp);
    std::cout << strInp << '\n';
  }

  return 0;
}