#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  const int SIZE = 10;
  int grade[SIZE] = {31, 235, 123, 12, 15, 51, 921, 329, 12, 1312};

  std::cout << "====================" << '\n';
  std::cout << "인덱스 값 : " << '\n';
  std::cout << "====================" << '\n';

  for (size_t i = 0; i < SIZE; i++) {
    std::cout << i << "      " << grade[i] << '\n';
  }
  return 0;
}
