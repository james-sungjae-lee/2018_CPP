#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[]) {
  const int SIZE = 10;
  int grade[SIZE];
  for (size_t i = 0; i < SIZE; i++) {
    grade[i] = rand() % 100;
  }
  for (size_t i = 0; i < SIZE; i++) {
    std::cout << i << " " << grade[i] << '\n';
  }
  return 0;
}
