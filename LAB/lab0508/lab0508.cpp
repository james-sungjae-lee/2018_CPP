// 20132651 경영학부 경영학전공 이성재
// MyString 5

#include <iostream>
using namespace std;

class MyString{
private:
  char *memory; // 저장할 string의 길이만큼만 할당받는다.
public:
  MyString(); // memory에 저장장소를 할당받고, "" NULL String을 저장
  MyString(const char *str); // memory에 저장장소를 할당받고 str을 복사한다.
  MyString(const MyString &s);
  void cpy(const char *str); // 할당받은 memory의 크기를 변경하고, str의 내용을 memory에 복사한다.
  void strcpy(char *a, char *b);
  void strcat(char *a, char *b);
  void cat(const char *str); // str의 내용을 memory의 현재 문자열의 끝에 append 하기 위해, memory의 크기 변경하고 내용을 변경한다.
  int cmp(const char *str); // str 과 memory의 알파벳을 비교하여 -1, 0, 1 을 return
  int size()const;
  ~MyString(){delete[] memory;}

  MyString& operator=(const MyString& s){ // s 를 const 로 작성했다면, s가 사용되는 함수도 const 함수여야 한다. 그렇지 않으면 오류 발생.
    memory = new char[s.size() + 1];
    for (size_t i = 0; i < s.memory[i] != '\0'; i++) {
      memory[i] = s.memory[i];
    }
    memory[s.size()] = '\0';
    return *this;
  }
  MyString operator+(const MyString& s){ // 더해서 return 하는 것은 레퍼런스가 아니다! 값 자체를 반환한다.
    char *temp = new char[this->size() + s.size() + 1];
    cout << this -> size() << endl;
    cout << s.size() << endl;
    strcpy(temp, memory);
    strcat(temp, s.memory);
    MyString r = MyString(temp);
    return r;
  }
  char& operator[](int i){
    return memory[i];
  }
  friend ostream& operator<<(ostream& os, const MyString& v);
};

int main(int argc, char const *argv[]) {
  MyString s1("C++");
  MyString s2("Programming");
  MyString s3;
  s3 = s1+s2;
  cout << s3;
  for (size_t i = 0; i < 3; i++) {
    cout << s3[i];
  }
  s3[0] = '1';
  cout << endl << s3 << endl;

  // MyString a = MyString("ABC");
  // MyString b = MyString("DEFEFA");
  // std::cout << a.size() << '\n';
  // a = b;
  // std::cout << a.size() << '\n';
  //
  // a.cpy("renameA");
  // b.cpy("renameB");
  // cout << a;
  // cout << b;

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

void MyString::strcpy(char *a, char *b){
  delete[] a;
  int idx = 0;
  while (b[idx] != '\0') {
    idx ++;
  }
  a = new char[idx + 1];

  int i;
  for (i = 0; b[i] != 0 ; i++) {
    a[i] = b[i];
  }
  a[i] = '\0';
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

void MyString::strcat(char *a, char *b){
  int size1 = 0;
  int size2 = 0;
  while (a[size1] != '\0') {
    size1++;
  }
  while (b[size2] != '\0') {
    size2++;
  }

  char *temp = new char[size1 + size2 + 1];
  for (size_t i = 0; i < size1; i++) {
    temp[i] = a[i];
  }
  for (size_t i = 0; i < size2; i++) {
    temp[size1 + i] = b[i];
  }
  temp[size1 + size2] = '\0';

  cout << temp << '\n';

  delete[] a;
  a = temp;
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

int MyString::size()const{
  int i = 0;
  while (memory[i] != '\0') {
    i ++;
  }
  return i;
}

ostream& operator<<(ostream& os, const MyString& v){
  os << v.memory << endl;
  return os;
}
