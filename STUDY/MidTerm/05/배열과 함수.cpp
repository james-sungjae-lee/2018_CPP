#include <iostream>
using namespace std;

int getAverage(int score[], int n);

int main(int argc, char const *argv[]) {
  const int STUDENTS = 5;
  int grade[STUDENTS] = {1, 2, 3, 4, 5};
  int avg;
  avg = getAverage(grade, STUDENTS);
  std::cout << avg << '\n';
  return 0;
}

int getAverage(int score[], int n){
  int sum = 0;
  for (size_t i = 0; i < n; i++) {
    sum += score[i];
  }
  return sum / n;
}
