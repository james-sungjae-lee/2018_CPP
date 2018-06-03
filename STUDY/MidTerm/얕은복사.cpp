#include <iostream>
#include <cstring>
using namespace std;

class Student{
  char *name;
  int number;
public:
  Student(char *pn, int n){
    name = new char[strlen(pn) + 1];
    strcpy(name, pn);
    number = n;
  }
  Student(Student& s){
    name = new char[strlen(s.name) + 1];
    strcpy(name, s.name);
    number = s.number;
  }
  ~Student(){
    delete[] name;
  }
  void setName(char *pn){
    delete[] name;
    name = new char[strlen(pn) + 1];
    strcpy(name, pn);
  }
  void printInfo(){
    std::cout << name << " " << number << '\n';
  }
};

int main(int argc, char const *argv[]) {
  Student s1("Park", 20100001);
  Student s2(s1);

  s1.printInfo();
  s2.printInfo();
  s1.setName("A");

  s1.printInfo();
  s2.printInfo();
  return 0;
}
