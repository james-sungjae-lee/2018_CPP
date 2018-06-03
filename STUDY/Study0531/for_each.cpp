#include <iostream>
#include <vector>
#include <algorithm>
void display(int element) {
  std::cout << element << '\n';
}
int main(int argc, char const *argv[]) {
  std::vector<int> vec;
  for (size_t i = 0; i < 10; i++) {
    vec.push_back(i);
  }

  for_each(vec.begin(), vec.end(), display);
  return 0;
}
