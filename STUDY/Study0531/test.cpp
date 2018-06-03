#include <iostream>
using namespace std;



int main(int argc, char const *argv[]) {

  int matrix[10][10];

  for (size_t i = 0; i < 10; i++) {
    for (size_t j = 0; j < 10; j++) {
      matrix[i][j] = i + j + 1;
    }
  }


  for (size_t i = 0; i < 10; i++) {
    for (size_t j = 0; j < 10; j++) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}
