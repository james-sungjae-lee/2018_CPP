#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> vec;
  for (size_t i = 0; i < 10; i++) {
    vec.push_back(i);
  }
  std::vector<int>::iterator it;
  for(it = vec.begin(); it != vec.end(); it++){
    std::cout << *it << " ";
  }
  std::cout << '\n';

  for(it = vec.begin(); it != vec.end(); it++){
    *it = 0;
  }

  for(it = vec.begin(); it != vec.end(); it++){
    std::cout << *it << ' ';
  }
  std::cout << '\n';

  return 0;
}
