#include <iostream>

using namespace std;

int gcd(int x, int y){
  int r, t;
  
  if (x < y) {
    t = y;
    y = x;
    x = t;
  }

  r = x % y;
  x = y;
  y = r;

  if (y == 0) {
    return x;
  }
  return gcd(y, r);
}

int main(int argc, char const *argv[]) {
    std::cout << gcd(24, 36) << '\n';
    return 0;
}
