#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[]) {
  stack<string> st;
  string saying[3] = {
    "The grass is greener on the other side of the fence",
    "Even the greeates make mistakes",
    "To see is to believe"
  };

  for (size_t i = 0; i < 3; ++i) {
    st.push(saying[i]);
  }
  while (!st.empty()) {
    std::cout << st.top() << '\n';
    st.pop();
  }
  return 0;
}
