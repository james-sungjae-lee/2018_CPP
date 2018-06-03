#include "myheader.hpp"
#include <vector>
#include <cstring>
#include <algorithm>

int main(int argc, char const *argv[]) {
  string names[5] = {"사과", "배" ,"키위" , "레몬" , "포도"};
  std::vector<string> fruits(5);
  copy(&names[0], &names[5], fruits.begin());
  print(fruits, "삭제전\n");

  std::vector<string>::iterator it;
  it = remove(fruits.begin(), fruits.end(), "레몬");
  print(fruits, "remove() 후\n");

  fruits.erase(it, fruits.end());
  print(fruits, "erase() 후\n");
  return 0;
}
