#include <iostream>
// #define DEBUG

using namespace std;

int main(int argc, char const *argv[]) {
  int x;
  int y;
  std::cout << "Enter value for x : " << '\n';
  std::cin >> x;
  std::cout << "Enter value for y : " << '\n';
  std::cin >> y;

  x *= y;

#ifndef DEBUG
  std::cout << "Variable x : " << x << '\n' << "Variable y : " << y << '\n';
#endif
  return 0;
}
