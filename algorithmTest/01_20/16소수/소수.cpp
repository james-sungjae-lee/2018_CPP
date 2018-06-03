#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int decimal(int k);

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
     decimal(k);
   }

  inStream.close();
  return 0;
}

int decimal(int k){
  for (size_t i = 2; i < k; i++) {
    if (k % i == 0) {
      std::cout << "0" << '\n';
      return 0;
    }
  }
  std::cout << "1" << '\n';
  return 0;
}
