#include <iostream>
#include <cmath>
using namespace std;
#define RAD_TO_DEG (45.0 / atan(1))

int main(int argc, char const *argv[]) {
  double w, h, r, theta;

  w = 10.0;
  h = 10.0;
  r = sqrt(w * w + h * h);
  theta = RAD_TO_DEG * atan2(h, w);
  std::cout << r << " " << theta << '\n';
  return 0;
}
