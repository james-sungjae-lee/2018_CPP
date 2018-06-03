// MyString.cpp
#include "MyString.h"

MyString::MyString() {// memory에 저장장소를 할당받고 NULL String 저장
      memory = new char[1];
      *memory = '\0';
}

MyString::MyString(const char str[]){
      int count = 0;
      while(str[count] != '\0')
        count++;

      memory = new char[count + 1];

      int idx = 0;
      while(str[idx] != '\0'){
        memory[idx] = str[idx];
        idx++;
      }

      memory[idx] = '\0';
}

MyString::MyString(MyString& s){ // 깊은 복사로 구현
      int str_size = 0;
      while(s.memory[str_size] != '\0')
        str_size++;

      memory = new char[str_size + 1];
      for(int i = 0; i < str_size; i++)
        memory[i] = s.memory[i];

      memory[str_size] = '\0';
}

MyString::~MyString() { delete[] memory; } // 소멸자

int MyString::size() const {// 저장된 문자열 길이를 반환
      int count = 0;
      while(memory[count] != '\0')
        count++;
      return count;
}

MyString& MyString::operator= (const MyString& s){ // 깊은 복사로 구현
      if (&s == this) return *this;
      int length = s.size();

      delete[] memory;
      memory = new char[length + 1];

      for(int i = 0; i < length; i++)
        memory[i] = s.memory[i];

      memory[length] = '\0';

      return *this;
}
