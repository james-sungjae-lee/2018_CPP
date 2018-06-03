#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int x, y, nextx, nexty;
  x = 1;
  y = 1;
  
  nextx = ++x;
  nexty = y++;

  std::cout << x << '\n';
  std::cout << nextx << '\n';

  std::cout << y << '\n';
  std::cout << nexty << '\n';
  return 0;
}
