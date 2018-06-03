#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  std::vector<int> vec;
  for (size_t i = 0; i < 10; i++) {
    vec.push_back(i);
  }
  vector<int>::reverse_iterator rit;
  for(rit = vec.rbegin(); rit != vec.rend(); rit++){
    std::cout << *rit << ' ';
  }
  std::cout << '\n';
  return 0;
}

// 먼저 rever iterator 로 rit 를 정의내림
// rit 에 vector 의 rbegin 을 넣음 = rbegin : end 와 동일하지 않다. end 는 NULL을 가르키지만, rbegin 은 end 직전의 실제값을 가리킨다.
