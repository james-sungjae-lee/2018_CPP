#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[]) {
  string fruits[5] = {"사과", "토마토", "배", "수박", "키위"};
  std::vector<string> vec(&fruits[0], &fruits[5]);

  std::vector<string>::iterator it;
  it = find(vec.begin(), vec.end(), "수박");
  if(it != vec.end()){
    cout << "수박이 " << distance(vec.begin(), it )+1 << "번째 에 있습니다.";
  }
  return 0;
}
