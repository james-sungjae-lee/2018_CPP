#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  const int STUDENTS = 5;
  int grade[STUDENTS];
  int sum = 0;
  float average;
  for (size_t i = 0; i < STUDENTS; i++) {
    grade[i] = (i + 1)* 10;
  }
  for (size_t i = 0; i < STUDENTS; i++) {
    sum += grade[i];
  }
  average = sum / STUDENTS;
  std::cout << average << '\n';
  return 0;
}
