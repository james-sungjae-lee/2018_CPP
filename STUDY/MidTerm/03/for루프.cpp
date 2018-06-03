#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int sum = 0;
  for (size_t i = 0; i <= 10; i++) {
    sum += i;
  }
  long fact = 1;
  int n;
  n = 10;
  for (size_t i = 1; i <= n; i++) {
    fact = fact * i;
  }
  std::cout << sum << '\n';

  std::cout << fact << '\n';
  return 0;
}
