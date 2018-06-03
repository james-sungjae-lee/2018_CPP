#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int i = 10;
  char c = 69;
  double f = 12.3;

  std::cout << &i << '\n';
  std::cout << (void *)&c << '\n';
  std::cout << &f << '\n';
  return 0;
}
