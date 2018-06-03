#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  for (size_t i = 0; i < 5; i++) {
    for (size_t i = 0; i < 10; i++) {
      std::cout << "*"<< " ";
    }
    std::cout << '\n';
  }
  return 0;
}
