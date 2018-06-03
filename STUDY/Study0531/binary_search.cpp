#include <iostream>
#include <vector>
#include <algorithm>
#include "myheader.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
  const int wanted = 7;
  int values[9] = {1, 3, 5, 5, 5, 8 ,11, 20, 30};
  std::vector<int> vec(&values[0], &values[9]);
  std::vector<int>::iterator it;

  print(vec);
  bool exist = binary_search(vec.begin(), vec.end(), wanted);
  if (exist == true) {
    std::cout << wanted << " 을 찾음!" << '\n';
  }else{
    it = lower_bound(vec.begin(), vec.end(), wanted);
    vec.insert(it, wanted);
  }
  print(vec);
  return 0;
}
