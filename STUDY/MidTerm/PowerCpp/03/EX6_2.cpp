#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int k = 0, l = 0;
  for (size_t i = 0; i < 31; i++) {
    for (size_t j = 0; j < 5; j++) {
      k += i * j;
    }
    l += k;
  }
  std::cout << l << '\n';
  return 0;
}
