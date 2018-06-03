#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[]) {
  std::vector<string> vec;

  vec.push_back("MILK");
  vec.push_back("BREAD");
  vec.push_back("BUTTER");

  std::vector<string>::iterator it;
  for (size_t i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << ' ';
  }
  std::cout << '\n';

  vec.insert(vec.begin() + 1, "APPLE");
  vec.pop_back();
  for(it = vec.begin(); it != vec.end(); ++it){
    std::cout << *it << ' ';
  }
  std::cout << '\n';
  return 0;
}
