#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;

  if (n < 100) {
    std::cout << "small" << '\n';
  }else if(100 <= n && n < 200){
    std::cout << "medium" << '\n';
  }else{
    std::cout << "large" << '\n';
  }

  return 0;
}
