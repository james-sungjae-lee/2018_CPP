#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  const int STUDENTS = 5;
  int grade[STUDENTS];
  int sum = 0;
  int average;

  for (size_t i = 0; i < STUDENTS; i++) {
    std::cin >> grade[i];
  }
  for (size_t i = 0; i < STUDENTS; i++) {
    sum += grade[i];
  }
  average = sum / STUDENTS ;
  std::cout << "평균 : " << average << '\n';
  return 0;
}
