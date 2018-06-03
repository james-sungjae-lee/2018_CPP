#include <iostream>
#include <deque>
using namespace std;

int main(int argc, char const *argv[]) {
  deque<int> dq;
  dq.push_back(99);
  dq.push_back(1);
  dq.push_front(35);
  dq.push_front(67);

  for (size_t i = 0; i < dq.size(); i++) {
    std::cout << dq[i] << ' ';
  }
  std::cout << '\n';

  dq.pop_back();
  dq.pop_front();

  for (size_t i = 0; i < dq.size(); i++) {
    std::cout << dq[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}
