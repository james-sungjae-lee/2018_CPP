#include <iostream>
#include <string>
using namespace std;

class Employee{
  string name;
  int salary;
  int age;
  int getSalary(){return salary;}
public:
  int getAge(){return age;}
  string getName(){return name;}
};

int main(int argc, char const *argv[]) {
  Employee e;
  // e.salary = 300;
  // e.age = 26;
  // int sa = e.getSalary();
  string s = e.getName();
  int a = e.getAge();
  return 0;
}
