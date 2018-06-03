#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  const int RATE = 5000;
  int pay ;
  int hours;

  std::cout << "시간을 입력하세요 : " ;
  std::cin >> hours;

  if (hours > 8) {
    pay = RATE * 8 + (1.5 * RATE * (hours - 8));
  }else{
    pay = RATE * hours;
  }
  std::cout << "임금은" << pay << "원 입니다" << '\n';
  return 0;
}
