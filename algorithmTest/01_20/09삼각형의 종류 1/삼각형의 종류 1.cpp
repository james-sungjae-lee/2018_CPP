#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int triangleCheck(int a, int b, int c);

int main(int argc, char const *argv[]) {
  ifstream inStream;
  int numTestCases;
  int a, b, c;

  inStream.open("input.txt");

   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }

   inStream >> numTestCases;

   for (size_t i = 0; i < numTestCases; i++) {
     inStream >> a;
     inStream >> b;
     inStream >> c;
     triangleCheck(a, b, c);
   }

  inStream.close();
  return 0;
}

int triangleCheck(int a, int b, int c){
  int k = 0;
  if ((a + b) > c ) {
    if (a == b && a == c) {
      k = 1;
    }else if(a == b || b == c || c == a){
      k = 3;
    }else if((a*a + b*b == c*c)){
      k = 2;
    }else{
      k = 4;
    }
  }else{
    k = 0;
  }
  std::cout << k << '\n';
  return 0;
}
