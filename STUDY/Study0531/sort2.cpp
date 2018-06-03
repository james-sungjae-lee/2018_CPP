#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include "myheader.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
  std::vector<int> v;
  for (size_t i = 0; i < 10; i++) {
    v.push_back(rand()%100);
  }
  sort(v.begin(), v.end(), greater<int>());
  print(v);
  return 0;
}
