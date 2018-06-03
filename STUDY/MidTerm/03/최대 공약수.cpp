#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int x, y, r;
  x = 1012;
  y = 1232;

  while (y != 0) {
    r = x % y;
    x = y;
    y = r;
  }
  std::cout << x << '\n';
  return 0;
}
