#include <iostream>
#include <climits>
using namespace std;

int main(int argc, char const *argv[]) {
  short year = SHRT_MAX;
  int sale = INT_MAX;
  long total_sale = LONG_MAX;

  std::cout << "short의 크기 " << sizeof(short) << '\n';
  std::cout << "int의 크기 " << sizeof(int) << '\n';
  std::cout << "long의 크기 " << sizeof(long) << '\n';

  std::cout << "short의 최대값 " << year << '\n';
  std::cout << "int의 최대값 " << sale << '\n';
  std::cout << "long의 최대값 " << total_sale << '\n';

  std::cout << "short의 최소값 " << SHRT_MIN << '\n';
  std::cout << "int의 최소값 " << INT_MIN << '\n';
  std::cout << "long의 최소값 " << LONG_MIN << '\n';
  return 0;
}
