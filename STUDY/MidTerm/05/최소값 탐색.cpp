#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  const int STUDENTS = 5;
  int grade[STUDENTS];
  int max;

  for (size_t i = 0; i < STUDENTS; i++) {
    grade[i] = (i + 1) * 10;
  }
  max = grade[0];
  for (size_t i = 1; i < STUDENTS; i++) {
    if (grade[i] > max) {
      max = grade[i];
    }
  }
  std::cout << max << '\n';
  return 0;
}
