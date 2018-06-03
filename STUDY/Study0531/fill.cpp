#include <iostream>
#include <vector>
#include "myheader.hpp"

int main(int argc, char const *argv[]) {
  std::vector<int> v1;
  for (size_t i = 0; i < 10; i++) {
    v1.push_back(i);
  }
  std::cout << "fill 이전의 값 " << '\n';
  print(v1);
  fill(v1.begin(), v1.end(), 0);
  std::cout << "fill 이후의 값" << '\n';
  print(v1);
  return 0;
}
