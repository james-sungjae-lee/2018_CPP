#include <iostream>

int main(int argc, char const *argv[]) {
  for (size_t i = 0; i < 10; i++) {
    const int i_squared = i * i;
    std::cout << i_squared << '\n';
  }
  return 0;
}
