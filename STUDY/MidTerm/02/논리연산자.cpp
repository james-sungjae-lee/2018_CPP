#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int x = 10, y = 20;
  bool r1, r2, r3, r4;

  r1 = (x == 10 && y == 20);
  r2 = (x == 10 && y == 30);
  r3 = (x >= 10 || y >= 30);
  r4 = !(x == 5);
  std::cout << r1 << " "<< r2 << " " << r3 << " "<< r4 << '\n';
  return 0;
}
