#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[]) {
  priority_queue<int> pq;
  for (size_t i = 0; i < 3; i++) {
    pq.push((i+1) * 100);
  }
  while (!pq.empty()) {
    std::cout << pq.top() << '\n';
    pq.pop();
  }
  return 0;
}
