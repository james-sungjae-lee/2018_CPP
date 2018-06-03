#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[]) {
  double v;

  while (1) {
    std::cout << "실수 : " ;
    std::cin >> v;

    if (v < 0.0) {
      break;
    }
    std::cout << sqrt(v) << '\n';
  }
  return 0;
}
