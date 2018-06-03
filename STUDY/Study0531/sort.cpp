#include <iostream>
#include <algorithm>
#include <vector>
#include "myheader.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
  int value[10] = {82, 25, 26, 7, 67, 55, 31, 19, 99};

  std::vector<int> v1(&value[0], &value[10]);
  print(v1, "초기 리스트");
  std::cout << '\n';
  sort(v1.begin(), v1.end());
  print(v1, "sort() 적용 후 ");
  std::cout << '\n';

  std::vector<int> v2(&value[0], &value[10]);
  stable_sort(v2.begin(), v2.end());
  print(v2, "stable_sort 적용 후");
  return 0;

}
