#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int s[3][3][3][3];
  int i = 1;
  for (size_t z = 0; z < 3; z++) {
    for (size_t y = 0; y < 3; y++) {
      for (size_t x = 0; x < 3; x++) {
        for (size_t ss = 0; ss < 3; ss++) {
          s[z][y][x][ss] = i++;
          std::cout << s[z][y][x][ss] << " ";
        }
        std::cout << '\n';
      }
      std::cout << '\n';
    }
    std::cout << '\n';
  }
  return 0;
}
