#include <iostream>
using namespace std;

int sum = 1;

int main(int argc, char const *argv[]) {
  int sum = 0;
  for (size_t i = 1; i <= 10; i++) {
    sum += i;
  }
  std::cout << sum << '\n';
  return 0;
}
