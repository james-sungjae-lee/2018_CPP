#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int age;
  std::cin >> age;
  int count = 0;
  if (age >= 20 && age <= 65) {
    count ++;
  }
  return 0;
}
