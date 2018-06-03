#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>

using namespace std;

int aliquot(long k);

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
     long k;
     inStream >> k;
     aliquot(k);
   }

  inStream.close();
  return 0;
}

int aliquot(long k){
  long count = 0;
  long sum = 0;

  for (size_t i = 1; i*i < k; i++) {
    if (k % i == 0) {
      count ++;
      sum += i;
      if (i > 1) {
        count++;
        sum += k/i;
      }
    }
    if (i*i == k) {
      count ++;
      sum += i;
    }
  }
  std::cout << count << " " << sum << '\n';
  return 0;
}
