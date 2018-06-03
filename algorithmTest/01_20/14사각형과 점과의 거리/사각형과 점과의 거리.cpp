#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int squareToDot(int sx1, int sy1, int sx2, int sy2, int d1, int d2);

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
     int sx1, sy1, sx2, sy2;
     int x, y;
     inStream >> sx1 >> sy1 >> sx2 >> sy2 >> x >> y ;
     squareToDot(sx1, sy1, sx2, sy2, x, y);
   }

  inStream.close();
  return 0;
}

int squareToDot(int sx1, int sy1, int sx2, int sy2, int x, int y){
  int d1;
  int d2;

  if (sx1 <= x && x <= sx2) {
    if (sy1 <= y && y <= sy2) {
      d1 = 0;
      d2 = 0;
    }else if (y < sy1) {
      d1 = (sy1 - y) * (sy1 - y);
      d2 = sy1 - y;
    }else{
      d1 = (y - sy2) * (y - sy2);
      d2 = y - sy2;
    }
  }else{
    if (sy1 <= y && y <= sy2) {
      d1 = ((x>sx1) ? x - sx2 : sx1 - x)*((x>sx1) ? x - sx2 : sx1 - x);
      d2 = (x>sx1) ? x - sx2 : sx1 - x;
    }else if (y < sy1) {
      if (x < sx1) {
        d1 = (x - sx1)*(x - sx1) + (y - sy1)*(y - sy1);
        d2 = (sx1 - x) + (sy1 - y);
      }else{
        d1 = (x - sx2)*(x - sx2) + (y - sy1)*(y - sy1);
        d2 = (x - sx2) + (sy1 - y);
      }
    }else{
      if (x < sx1) {
        d1 = (x - sx1)*(x - sx1) + (y - sy2)*(y - sy2);
        d2 = (sx1 - x) + (y - sy2);
      }else{
        d1 = (x - sx2)*(x - sx2) + (y - sy2)*(y - sy2);
        d2 = (x - sx2) + (y - sy2);
      }
    }
  }
  std::cout << d1 << " " << d2 << '\n';
  return 0;
}
