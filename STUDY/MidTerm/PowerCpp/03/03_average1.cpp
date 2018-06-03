#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {
  float grade, sum = 0.0, average;
  int count = 0;

  while (1) {
    std::cout << "학생 성적을 입력하시오 : " ;
    std::cin >> grade;

    if (grade < 0.0) {
      break;
    }
    count ++;
    sum += grade;
  }

  average = sum / count;
  std::cout << average << '\n';
  return 0;
}
