#include <iostream>
using namespace std;

int calc_deposit(int salary = 300, int month = 12);

int main(int argc, char const *argv[]) {
  std::cout << "0개의 디폴트 매개 변수" << '\n';
  std::cout << calc_deposit(200, 6) << '\n';

  std::cout << "1개" << '\n';
  std::cout << calc_deposit(200) << '\n';

  std::cout << "2개" << '\n';
  std::cout << calc_deposit() << '\n';
  return 0;
}

int calc_deposit(int salary, int month){
  return salary * month;
}
