#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int a[3][5];
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 5; j++) {
      a[i][j] = j;
    }
  }
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 5; j++) {
      std::cout << a[i][j] << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}
