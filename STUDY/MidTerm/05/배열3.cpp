#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  const int SIZE = 10;
  int grade[SIZE] = {31, 53, 123, 1223, 91, 20, 19, 30, 50, 0};

  for (size_t i = 0; i < SIZE; i++) {
    std::cout << i << " : " << grade[i] << '\n';
  }
  return 0;
}
