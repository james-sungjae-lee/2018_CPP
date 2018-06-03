#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include "myheader.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
  int values1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int values2[9] = {9, 9, 3, 4, 5, 9, 9, 9, 9};

  std::vector<int> vec1(&values1[0], &values1[9]);
  std::vector<int> vec2(&values2[0], &values2[9]);

  print(vec1);
  print(vec2);
  bool isEqual = equal(vec1.begin() + 2, vec1.begin() + 5, vec2.begin() + 2);
  if(isEqual == true){
    std::cout << "두 구간이 동일!" << '\n';
  }
  return 0;
}
