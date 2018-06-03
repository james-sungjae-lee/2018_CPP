#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int s[3][5];
  int value = 0;
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 5; j++) {
      s[i][j] = value ++;
    }
  }
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 5; j++) {
      std::cout << s[i][j] << " ";
    }
    std::cout  << '\n';
  }
  return 0;
}
