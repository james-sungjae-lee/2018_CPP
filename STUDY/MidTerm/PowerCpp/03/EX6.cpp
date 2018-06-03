#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int k = 0;
  for (size_t i = 0; i < 31; i++) {
    k += (i*i) + 1;
    std::cout << k << '\n';
  }
  return 0;
}
