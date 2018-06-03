#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> v;
  for (size_t i = 0; i < 10; i++) {
    v.push_back(rand()%100);
  }
  std::vector<int>::iterator it;

  for(it = v.begin(); ; it++){
    it = find_if(it, v.end(), bind2nd(greater<int>(), 50));
    if (it == v.end()) {
      break;
    }
    std::cout << *it << " 발견" << '\n';
  }
  return 0;
}
