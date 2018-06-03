#include "myheader.hpp"
#include <vector>
#include <algorithm>

int increment(int element){
  return ++element;
}

int main(int argc, char const *argv[]) {
  std::vector<int> vec;
  std::vector<int> result(10);

  for (size_t i = 0; i < 10; i++) {
    vec.push_back(i);
  }
  print(vec);
  transform(vec.begin(), vec.end(), result.begin(), increment);
  print(result);
  return 0;
}
