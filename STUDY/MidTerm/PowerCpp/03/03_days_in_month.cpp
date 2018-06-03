#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int month;
  int year = 2009;
  int days = 0;

  std::cout << "month? : ";
  std::cin >> month;

  switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      days = 31;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      days = 30;
      break;
    case 2:
      if (((year % 4 == 0) && !(year % 100 == 0)) || (year % 400 == 0)) {
        days = 29;
      }else{
        days = 28;
      }
      break;
    default:
      std::cout << "Error" << '\n';
      break;
  }
  std::cout << "월의 날 수는 : " << days << '\n';
  return 0;
}
