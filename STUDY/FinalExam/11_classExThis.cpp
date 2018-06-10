#include <iostream>
#include <string>
using namespace std;

class Person{
  string lastName;
  string firstName;

public:
  Person(string lastName, string firstName);
  string getLastName(){
    return lastName;
  }
  string getFirstName(){
    return firstName;
  }
  string buildName();
};

Person::Person(string lastName, string firstName){
  this -> lastName = lastName;
  this -> firstName = firstName;
}

string Person::buildName(){
  return this -> getLastName() + this->getFirstName();
}

int main(int argc, char const *argv[]) {
  Person person("이", "성재");
  std::cout << person.buildName() << '\n';
  return 0;
}
