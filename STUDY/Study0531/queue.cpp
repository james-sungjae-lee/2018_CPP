#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[]) {
  queue<int> qu;
  for (size_t i = 0; i < 3; i++) {
    qu.push((i+1) * 100);
  }
  while (!qu.empty()) {
    std::cout << qu.front() << '\n';
    qu.pop();
  }
  return 0;
}
