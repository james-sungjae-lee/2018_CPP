#include <iostream>
#include <cstring>
using namespace std;

class Employee{
  string name;
  double salary;

  static int count;
public:
  Employee(string n = "", double s = 0.0) : name(n), salary(s){
    count++;
  }
  ~Employee(){
    count --;
  }
  static int getCount(){
    return count;
  }
};

int Employee::count = 0;

int main(int argc, char const *argv[]) {
  Employee e1("김철수", 35000);
  Employee e2("이철수", 36000);
  Employee e3("박철수", 37000);

  int n = Employee::getCount();
  std::cout << n << '\n';

  return 0;
}
