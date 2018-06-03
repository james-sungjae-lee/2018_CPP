#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> vec;
  for (size_t i = 0; i < 10; i++) {
    vec.push_back(i);
  }

  vector<int>::iterator it;
  it = vec.begin();
  std::cout << it[2] << '\n';
  std::cout << *(it + 2) << " " << '\n';
  it = it + 5;
  it -- ;
  std::cout << *it << " " << '\n';
  return 0;
}
// 0 1 2 3 .. 10
// it[2] = 3번째 요소 뽑아내기 = 2
// *(it + 2) -> it 는 0 위치이므로, 3번째 요소 = 2
// it = it + 5 -> 6번째 위치로 이동 = 5
// it-- -> 5번째 위치로 이동 = 4
