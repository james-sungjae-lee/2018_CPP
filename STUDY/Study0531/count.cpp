#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

template <typename T>
bool is_even(const T& num){
  return (num % 2 ) == 0;
}

int main(int argc, char const *argv[]) {
  char *s = "I go to the school";
  std::vector<int> vec;
  for (size_t i = 0; i < 10; i++) {
    vec.push_back(i);
  }
  size_t n1 = count(s, s + strlen(s), 'o');
  size_t n2 = count_if(vec.begin(), vec.end(), is_even<int>);

  std::cout << "값이 'o' 인 요소의 개수 : " << n1 << '\n';
  std::cout << "값이 짝수인 요소의 개수 : " << n2 << '\n';
  return 0;
}
