#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int drawingGraph(int a);

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
     int k;
     inStream >> k;
     drawingGraph(k);
   }

  inStream.close();
  return 0;
}

int drawingGraph(int a){

  for (size_t i = 0; i < a/2; i++) {
    for (size_t i = 0; i < a/2; i++) {
      std::cout << ".";
    }
    std::cout << "I" ;
    for (size_t j = a/2-1; j > i ; j--) {
      std::cout << "." ;
    }
    std::cout << "*";
    for (size_t j = 0; j < i; j++) {
      std::cout << "." ;
    }
    std::cout << '\n';
  }

  for (size_t i = 0; i < a/2; i++) {
    std::cout << "+";
  }
  std::cout << "O" ;
  for (size_t i = 0; i < a/2; i++) {
    std::cout << "+";
  }
  std::cout << '\n';

  for (size_t i = 0; i < a/2; i++) {

    for (size_t j = a/2-1; j > i ; j--) {
      std::cout << "." ;
    }
    std::cout << "*";
    for (size_t j = 0; j < i; j++) {
      std::cout << "." ;
    }
    std::cout << "I" ;

    for (size_t i = 0; i < a/2; i++) {
      std::cout << ".";
    }

    std::cout << '\n';
  }
  return 0;













}
