#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

void get_random(int n){
  for (size_t i = 0; i < n; i++) {
    std::cout << rand()%100 << '\n';
  }
}
int main(int argc, char const *argv[]) {
  srand((unsigned)time(NULL));
  get_random(10);
  return 0;
}
''
