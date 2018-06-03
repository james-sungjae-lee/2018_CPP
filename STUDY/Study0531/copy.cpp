#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  string names[5] = {"사과", "배", "키위" , "레몬", "포도"};
  std::vector<string> fruits(5);
  std::vector<string>::iterator it;

  copy(&names[0], &names[5], fruits.begin());
  reverse(fruits.begin(), fruits.end());

  for(it = fruits.begin(); it != fruits.end(); ++it){
    std::cout << *it << '\n';
  }
  return 0;
}
