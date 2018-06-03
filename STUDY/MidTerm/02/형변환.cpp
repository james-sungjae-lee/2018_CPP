#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  int i;
  double f;

  f = 5 / 4;
  std::cout << f << '\n';
  f = (double)5 / 4;
  std::cout << f << '\n';
  f = 5 / (double)4;
  std::cout << f << '\n';
  f = (double)5 / (double)4;
  std::cout << f << '\n';

  std::cout << '\n';

  i = 1.3 + 1.8;
  std::cout << i << '\n';
  i = (int)1.3 + (int)1.8;
  std::cout << i << '\n';
  return 0;
}
