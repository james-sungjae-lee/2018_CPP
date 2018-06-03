#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  long fact = 1;
  int n = 20;

  for (size_t i = 1; i <= n; i++) {
    fact = fact * i;
    std::cout << fact << '\n';
  }
  return 0;
}
