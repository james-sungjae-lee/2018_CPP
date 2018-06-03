#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  for (size_t i = 0; i < 20; i++) {
    for (size_t j = 0; j < 50; j++) {
      std::cout << "*";
    }
    std::cout << '\n';
  }
  return 0;
}
