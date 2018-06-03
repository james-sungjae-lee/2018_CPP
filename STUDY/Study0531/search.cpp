#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[]) {
  std::vector<int> vec;
  for (size_t i = 0; i < 10; i++) {
    vec.push_back(i);
  }
  list<int> ilist;
  for (size_t i = 3; i < 6; ++i) {
    ilist.push_back(i);
  }

  std::vector<int>::iterator it;
  it = search(vec.begin(), vec.end(), ilist.begin(), ilist.end());
  if (it != vec.end()) {
    std::cout << "부분 구간이 " << distance(vec.begin(), it) << " 에 있습니다."<< '\n';
  }
  return 0;
}
