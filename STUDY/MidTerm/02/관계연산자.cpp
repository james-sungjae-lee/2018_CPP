#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int x = 10;
  int y = 20;

  bool r1, r2, r3, r4;

  r1 = (x == y);
  r2 = (x != y);
  r3 = (x >= y);
  r4 = (x <= y);
  std::cout << r1 << " " << r2 << " "<< r3 << " "<< r4 << '\n';
  return 0;
}
