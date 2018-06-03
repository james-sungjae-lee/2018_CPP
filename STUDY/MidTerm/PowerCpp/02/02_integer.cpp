#include <iostream>
#include <climits>

using namespace std;

int main(int argc, char const *argv[]) {
  short year = SHRT_MAX;
  int sale = INT_MAX;
  long total_sale = LONG_MAX;

  std::cout << "short 형의 크기 = " << sizeof(short) << '\n';
  std::cout << "int 형의 크기 = " << sizeof(int) << '\n';
  std::cout << "long 형의 크기 = " << sizeof(long) << '\n';

  std::cout << "short 형의 크기 = " << year << '\n';
  std::cout << "int 형의 최대값 = " << sale << '\n';
  std::cout << "long 형의 최대값 = " << total_sale << '\n';

  std::cout << "short 형의 최소값 = " << SHRT_MIN << '\n';
  std::cout << "int 형의 최소값 = " << INT_MIN << '\n';
  std::cout << "long 형의 최소값 = " << LONG_MIN << '\n';
  return 0;
}
