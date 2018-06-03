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
   int k;
   for (size_t i = 0; i < numTestCases; i++) {
     inStream >> k;
     std::cout << k << '\n';
   }

  inStream.close();
  return 0;
}
