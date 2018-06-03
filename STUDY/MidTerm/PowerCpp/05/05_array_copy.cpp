#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  const int SIZE = 5;
  int a[SIZE] = {1, 2, 3, 4, 5};
  int b[SIZE];

  for (size_t i = 0; i < SIZE; i++) {
    b[i] = a[i];
  }

  for (size_t i = 0; i < SIZE; i++) {
    std::cout << b[i] << '\n';
  }
  return 0;
}
