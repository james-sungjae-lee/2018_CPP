#include <iostream>
#include <fstream>
#include <cstdlib>
#include <bitset>
#include <cstring>

using namespace std;

int parityBit(int num);

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
     int testNum;
     inStream >> testNum;
     parityBit(testNum);
   }

  inStream.close();
  return 0;
}

int parityBit(int num){
  int bitCount = 0;
  bitset<32> myBitset;
  myBitset = bitset<32>(num);
  for (size_t i = 0; i < 32; i++) {
    if (myBitset[i] == 1) {
      bitCount ++;
    }
  }
  if (bitCount % 2 == 0) {
    myBitset[31] = 0;
  }else{
    myBitset[31] = 1;
  }
  std::cout << myBitset.to_ulong() << '\n';



















  return 0;
}
