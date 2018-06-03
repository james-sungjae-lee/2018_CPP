#include <iostream>
using namespace std;

const int SIZE = 20;

void copy_array(char dest[], const char src[], int count);

int main(int argc, char const *argv[]) {
  char s[SIZE] = {'H', 'E', 'L', 'L', 'O', '\0'};
  char d[SIZE];

  copy_array(d, s, SIZE);
  std::cout << d << '\n';
  return 0;
}

void copy_array(char dest[], const char src[], int size){
  for (size_t i = 0; i < size; i++) {
    dest[i] = src[i];
  }
}
