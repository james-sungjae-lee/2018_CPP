#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int year;
  bool result;

  year = 2018;

  result = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
  std::cout << result << '\n';
  return 0;
}
