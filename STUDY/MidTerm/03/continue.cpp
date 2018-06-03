#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int n = 12;

  while (n > 0) {
    n = n - 2;
    if (n == 6) {
      continue;
    }
    std::cout << n << '\n';
  }
  return 0;
}
