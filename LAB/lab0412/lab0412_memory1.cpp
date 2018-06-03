// 경영학부 경영학전공 20132651 이성재
// lab0412_memory1.cpp
#include <iostream>
#include <cstring>
using namespace std;

class MyString{
public:
  char memory[80] = {0};

  int size(){
    int i = 0;
    while (memory[i] != '\0') {
      i++;
    }
    return i;
  };
  void cpy(char str[]){
    int i = 0;
    while (str[i] != '\0') {
      memory[i] = str[i];
      i++;
    }

  };
  void cat(char str[]){
    int i = size();
    int j = 0;
    while (str[j] != '\0') {
      memory[i] = str[j];
      j++; i++;
    }
    memory[i] = '\0';
  };

  int cmp(char str[]){
    for (size_t i = 0; i < size(); i++) {
      if (memory[i] == '\0') {
        break;
      }
      if (memory[i] == str[i]) {
        continue;
      }
      if (memory[i] != str[i]) {
        if (memory[i] > str[i]) {
          return 1;
        }else{
          return -1;
        }
      }
    }
    return 0;
  };
};

int main(int argc, char const *argv[]) {
  MyString a;

  a.cpy("ABC");
  std::cout << a.memory << '\n';
  std::cout << a.size() << '\n';
  a.cat("ABCDEF");
  std::cout << a.memory << '\n';
  std::cout << a.size() << '\n';
  std::cout << a.cmp("ABCABCD") << '\n';
  return 0;
}
