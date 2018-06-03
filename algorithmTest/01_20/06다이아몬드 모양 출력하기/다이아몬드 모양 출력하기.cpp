#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int diamond(int k);

int main(int argc, char const *argv[]) {
  ifstream inStream;
  int numTestCases;

  inStream.open("input.txt");

   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }

   inStream >> numTestCases;

   for (size_t i = 0; i < numTestCases; i++) {
     int a;
     inStream >> a;
     diamond(a);
   }

  inStream.close();
  return 0;
}


int diamond(int k){
  int star = 1;
  int space = (k-1)/2;
  int line = (k-1)/2 + 1;

  for (; line > 0; line--) {
    for (size_t i = space; i > 0 ; i--) {
      std::cout << "*" ;
    }
    for (size_t i = star; i > 0; i--) {
      std::cout << "+";
    }
    for (size_t i = space; i > 0 ; i--) {
      std::cout << "*" ;
    }
    space--;
    star = star + 2;
    std::cout << '\n';
  }

  space = space + 2;
  line = (k-1) / 2;
  star = star - 4;

  for (; line > 0; line--) {
    for (size_t i = space; i > 0; i--) {
      std::cout << "*";
    }
    for (size_t i = star ; i > 0; i--) {
      std::cout << "+";
    }
    for (size_t i = space; i > 0; i--) {
      std::cout << "*";
    }
    space++;
    star = star - 2;
    std::cout << '\n';
  }
  return 0;
}
