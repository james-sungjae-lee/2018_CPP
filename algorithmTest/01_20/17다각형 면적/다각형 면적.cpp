#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int polygon(int numDots);

ifstream inStream;


int main(int argc, char const *argv[]) {

  int numTestCases;
  int numDots;

  inStream.open("input.txt");

   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }

   inStream >> numTestCases;

   for (size_t i = 0; i < numTestCases; i++) {
     inStream >> numDots;
       polygon(numDots);
   }

  inStream.close();
  return 0;
}

int polygon(int numDots){
  int range = 0;
  int rotate;
  int arrX[1000] = {0};
  int arrY[1000] = {0};
  for (size_t i = 0; i < numDots; i++) {
    inStream >> arrX[i];
    inStream >> arrY[i];
  }
  arrX[numDots] = arrX[0];
  arrY[numDots] = arrY[0];
  for (size_t i = 0; i < numDots; i++) {
    range = range + ((arrX[i]*arrY[i+1]) - (arrX[i+1]*arrY[i]));
  }
  if (range < 0) {
    rotate = -1;
    range = -1 * range;
  }else{
    rotate = 1;
  }
  std::cout << range << " " << rotate << '\n';
  return 0;
}
