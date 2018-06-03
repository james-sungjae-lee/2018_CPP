#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>

using namespace std;

int triangleTest(int x1, int y1, int x2, int y2, int x3, int y3);


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
     int x1, y1, x2, y2, x3, y3;
     inStream >> x1;
     inStream >> y1;
     inStream >> x2;
     inStream >> y2;
     inStream >> x3;
     inStream >> y3;

     triangleTest(x1, y1, x2, y2, x3, y3);
   }

  inStream.close();
  return 0;
}

int triangleTest(int x1, int y1, int x2, int y2, int x3, int y3){
  double a, b, c;
  a = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
  b = (x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3);
  c = (x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3);

  if (c < a) {
    double temp;
    temp = c;
    c = a;
    a = temp;
  }
  if (c < b) {
    double temp;
    temp = c;
    c = b;
    b = temp;
  }

  if ((sqrt(a) + sqrt(b)) <= sqrt(c)) {
    std::cout << "0" << '\n';
  }else{
    if (c == (a + b)) {
      std::cout << "1" << '\n';
    }
    else if (c > (a + b)) {
      std::cout << "2" << '\n';
    }
    else if (c < (a + b)) {
      std::cout << "3" << '\n';
    }
  }
  return 0;
}
