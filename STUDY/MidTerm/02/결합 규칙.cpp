#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int x = 0, y = 0, z = 0;
  std::cout << (2 > 3 || 6 > 7) << '\n';
  std::cout << (2 || 3 && 3 > 2) << '\n';
  std::cout << (x = y = z = 1) << '\n';
  std::cout << (- (++x) + (y--)) << '\n';
  std::cout << y << '\n';
  return 0;
}
