// 20132651 경영학부 경영학전공 이성재
// MyString 3

#include <iostream>
using namespace std;

class MyString{
public:
  char *memory; // 저장할 string의 길이만큼만 할당받는다.
  MyString(); // memory에 저장장소를 할당받고, "" NULL String을 저장
  MyString(const char *str); // memory에 저장장소를 할당받고 str을 복사한다.
  MyString(const MyString &s);
  void cpy(const char *str); // 할당받은 memory의 크기를 변경하고, str의 내용을 memory에 복사한다.
  void cat(const char *str); // str의 내용을 memory의 현재 문자열의 끝에 append 하기 위해, memory의 크기 변경하고 내용을 변경한다.
  int cmp(const char *str); // str 과 memory의 알파벳을 비교하여 -1, 0, 1 을 return
  int size();
  ~MyString(){delete[] memory;}
};

int main(int argc, char const *argv[]) {
  MyString a = MyString("ABC");
  std::cout << a.memory << '\n';
  a.cpy("DEFG");
  std::cout << a.memory << '\n';
  // a.cat("HIJK");
  // std::cout << a.memory << '\n';
  // std::cout << a.cmp("DEFGHIJ") << '\n';
  //
  // MyString b = MyString(a);
  // MyString c = MyString(b);
  // std::cout << b.memory << '\n';
  // std::cout << c.memory << '\n';
  //
  //
  // a.~MyString();
  // b.~MyString();

  return 0;
}

MyString::MyString(){
  memory = new char[1];
  memory[0] = '\0';
}

MyString::MyString(const MyString& s){
  int i = 0;
  while (s.memory[i] != '\0') {
    i++;
  }
  memory = new char[i + 1];
  int last;
  for (size_t j = 0; s.memory[j] != '\0'; j++) {
    memory[j] = s.memory[j];
    last = j;
  }
  memory[last + 1] = '\0';

}

MyString::MyString(const char *str){
  int i = 0;
  while (str[i] != '\0') {
    i++;
  }
  memory = new char[i + 1];
  int last;
  for (size_t j = 0; str[j] != '\0'; j++) {
    memory[j] = str[j];
    last = j;
  }
  memory[last + 1] = '\0';
}

void MyString::cpy(const char *str){
  delete[] memory;
  int idx = 0;
  while (str[idx] != '\0') {
    idx ++;
  }
  memory = new char[idx + 1];

  int i;
  for (i = 0; str[i] != 0 ; i++) {
    memory[i] = str[i];
  }
  memory[i] = '\0';
}

void MyString::cat(const char *str){
  int size1 = size();
  int size2 = 0;
  while (str[size2] != '\0') {
    size2++;
  }

  char *temp = new char[size1 + size2];
  for (size_t i = 0; i < size(); i++) {
    temp[i] = memory[i];
  }
  for (size_t i = 0; i < size2; i++) {
    temp[size1 + i] = str[i];
  }
  temp[size1 + size2] = '\0';

  delete[] memory;
  memory = temp;
  delete[] temp;
}

int MyString::cmp(const char *str){
  int i;
  for (i = 0; i < size(); i++) {
    if (memory[i] == str[i]) {
      continue;
    }
    if (memory[i] > str[i]) {
      return 1;
    }else{
      return -1;
    }
  }
  if (str[i] == '\0') {
    return 0;
  }else{
    return -1;
  }
}

int MyString::size(){
  int i = 0;
  while (memory[i] != '\0') {
    i ++;
  }
  return i;
}
