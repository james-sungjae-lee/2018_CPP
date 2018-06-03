#include <iostream>
#include <cstdlib>
#include <fstream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

int hammingNumber(int k);

int main(int argc, char const *argv[]) {
  int numTestCases;
  int k;
  ifstream inStream;

  inStream.open("input.txt");

   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }

   inStream >> numTestCases;

   for (size_t i = 0; i < numTestCases; i++) {
     inStream >> k;
     hammingNumber(k);
   }

  inStream.close();
  return 0;
}

int hammingNumber(int k){

  std::vector<unsigned int> v;

  for (size_t i = 1;  ; i *= 5) {
    for (size_t k = i;  ; k *= 3) {
      for (size_t j = k;  ; j *= 2) {
        v.push_back(j);
        if (j > UINT_MAX/2) {
          break;
        }
      }
      if (k > UINT_MAX/3) {
        break;
      }
    }
    if (i > UINT_MAX/5) {
      break;
    }
  }
  sort(v.begin(), v.end());
  std::cout << v[k-1] << '\n';

  return 0;
}
