#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
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
  int a, b, c, d, e;
  inStream >> a;
  inStream >> b;
  if (a < b) {
    c = b - a;
    d = b;
    e = 0;
  }else if(a == b){
    c = 0;
    d = a;
    e = 1;
  }else{
    c = a - b;
    d = a;
    e = 0;
  }
  std::cout << a+b << " "<< a-b << " " << c << " "<< a*b <<" " <<a/b << " "<< a%b << " "<< d << " " << e <<'\n';
}
  inStream.close();
  return 0;
}
