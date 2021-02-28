#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Student {
  std::string name {};
  int grade {};
};

int getNumberOfStudents() {
  int numberOfStudents {};
  do {
    std::cout << "How many students do you want to enter?";
    std::cin >> numberOfStudents;
  } while (numberOfStudents <= 0);
}

std::vector<Student> getStudents() {
  using vector_type = std::vector<Student>;

  int numberOfStudents { getNumberOfStudents() };
  vector_type students(static_cast<vector_type::size_type>(numberOfStudents));

  int studentNumber { 1 };
  for (auto& student : students) {
    std::cout << "Enter Name #" << studentNumber << " : ";
    std::cin >> student.name;
    std::cout << "Enter Marks #" << studentNumber << " : ";
    std::cin >> student.grade;
    ++studentNumber;
  }
  return students;
}

bool compareStudents(const Student& a, const Student& b) {
  return a.grade > b.grade;
}

int main() {
  auto students { getStudents() };
  std::sort(students.begin(), students.end(), compareStudents);

  for (auto& student : students) {
    std::cout << student.name << " got a grade of " << student.grade << std::endl;
  }
  return 0;
}