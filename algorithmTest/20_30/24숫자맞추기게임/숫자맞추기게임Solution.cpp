#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
ifstream inStream;

int numGame();

int main(int argc, char const *argv[]) {
  int numTestCases;

  inStream.open("input.txt");

   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }

   inStream >> numTestCases;

   for (size_t i = 0; i < numTestCases; i++) {
     numGame();
   }

  inStream.close();
  return 0;
}

int numGame(){
  int result, num, strike, ball, testNum;
  int testn[4], checkn[4];
  int cstrike, cball;
  int check[10000];

  for (size_t i = 0; i < 10000; i++) {
    check[i] = 1;
  }

  inStream >> testNum;
  for (size_t i = 0; i < testNum; i++) {
    inStream >> num >> strike >> ball;

    testn[0] = num / 1000;
    testn[1] = (num / 100) % 10;
    testn[2] = (num / 10) % 10;
    testn[3] = num % 10;

    for (size_t k = 0; k < 10000; k++) {
      cstrike = 0;
      cball = 0;

      if (check[k] != 0) {
        checkn[0] = k / 1000;
        checkn[1] = (k / 100) % 10;
        checkn[2] = (k / 10) % 10;
        checkn[3] = k % 10;

        for (size_t l = 0; l < 4; l++) {
          if (testn[l] == checkn[l]) {
            cstrike ++;
          }else{
            for (size_t m = 0; m < 4; m++) {
              if (testn[l] == checkn[m] && testn[m] != checkn[m]) {
                cball ++;
                break;
              }
            }
          }
        }

        if ((strike != cstrike) || (ball != cball)) {
          check[k] = 0;
        }
      }
    }
  }

  result = 0;
  for (size_t i = 0; i < 10000; i++) {
    if (check[i] != 0) {
      result ++;
    }
  }

  if (result == 1) {
    for (size_t i = 0; i < 10000; i++) {
      if (check[i] != 0) {
        std::cout << i << '\n';
        break;
      }
    }
  }else if (result > 1) {
    std::cout << "-1" << '\n';
  }else{
    std::cout << "-2" << '\n';
  }
  return 0;
}
