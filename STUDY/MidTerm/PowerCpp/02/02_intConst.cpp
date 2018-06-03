#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int x = 10;
  int y = 010;
  int z = 0x10;

  std::cout << "x = " << x << '\n';
  std::cout << "y = " << y << '\n';
  std::cout << "z = " << z << '\n';

  return 0;
}
