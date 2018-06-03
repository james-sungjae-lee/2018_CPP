#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int triangle(double Ax,double Ay,double Bx,double By,double Cx,double Cy);

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
     double Ax, Ay, Bx, By, Cx, Cy;
     inStream >> Ax >> Ay >> Bx >> By >> Cx >> Cy;
     triangle(Ax, Ay, Bx, By, Cx, Cy);
   }

  inStream.close();
  return 0;
}

int triangle(double Ax,double Ay,double Bx,double By,double Cx,double Cy){
  double a = 0.5 * ((Bx - Ax)*(Cy - Ay) - (Cx - Ax)*(By - Ay));
  double b = 2 * a;

  if (a < 0) {
    b = -1 * b;
    std::cout << b <<  " -1" << '\n';
  }else if (a > 0) {
    std::cout << b<< " 1" <<'\n';
  }else{
    std::cout << b << " 0" << '\n';
  }

  return 0;
}
