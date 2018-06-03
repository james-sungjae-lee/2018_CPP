#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int lineIntersection(int Ax1, int Ay1, int Ax2, int Ay2, int Bx1, int By1, int Bx2, int By2);

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
     int Ax1, Ay1, Ax2, Ay2;
     int Bx1, By1, Bx2, By2;

     inStream >> Ax1;
     inStream >> Ay1;
     inStream >> Ax2;
     inStream >> Ay2;
     inStream >> Bx1;
     inStream >> By1;
     inStream >> Bx2;
     inStream >> By2;
     lineIntersection(Ax1, Ay1, Ax2, Ay2, Bx1, By1, Bx2, By2);
   }

  inStream.close();
  return 0;
}

int lineIntersection(int Ax1, int Ay1, int Ax2, int Ay2, int Bx1, int By1, int Bx2, int By2){

  bool bool1;
  bool bool2;

  bool bool3;
  bool bool4;

  if (Ax1 != Ax2) {
    int temp;
    temp = Ax1;
    Ax1 = Bx1;
    Bx1 = temp;

    temp = Ay1;
    Ay1 = By1;
    By1 = temp;

    temp = Ax2;
    Ax2 = Bx2;
    Bx2 = temp;

    temp = Ay2;
    Ay2 = By2;
    By2 = temp;

  }

  if (Ay1 > Ay2) {
    int temp;
    temp = Ay1;
    Ay1 = Ay2;
    Ay2 = temp;
  }
  if (Bx1 > Bx2) {
    int temp;
    temp = Bx1;
    Bx1 = Bx2;
    Bx2 = temp;
  }

  if ((Ay1 <= By1) && (By1 <= Ay2)) {
    bool1 = true;
  }else{
    bool1 = false;
  }
  if ((Bx1 <= Ax1) && (Ax1 <= Bx2)) {
    bool2 = true;
  }else{
    bool2 = false;
  }
  if ((Ax1 == Bx1) || (Ax1 == Bx2)) {
    bool3 = true;
  }else{
    bool3 = false;
  }
  if ((By1 == Ay1) || (By1 == Ay2)) {
    bool4 = true;
  }else{
    bool4 = false;
  }

  if ((bool1 && bool2)&&(!bool3 && !bool4)) {
    std::cout << "1" << '\n';
  }else if ((bool1 && bool2)&&(bool3 || bool4)) {
    std::cout << "2" << '\n';
  }else{
    std::cout << "0" << '\n';
  }

  return 0;
}
