#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int n = 10;
  do {
    std::cout << n << '\n';
    n = n - 3;
  } while(n > 0);

  n = 10;

  while (n > 0) {
    std::cout << n << '\n';
    n = n - 3;
  }
  return 0;
}
