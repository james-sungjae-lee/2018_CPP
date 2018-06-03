#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){
 fstream infile;
 int numcases;

 infile.open("input.txt");

 infile >> numcases;

 while (numcases--){
  int data;
  int same[6][7] = { 0, };
  int hang[7] = { 5, 5, 5, 5, 5, 5, 5 };
  int i, j, k;
  int n;
  int res = 0;

  infile >> data;


  for (i = 0; i < data; i++){
   infile >> n;
   if (i % 2 == 0){
    same[hang[n - 1]--][n - 1] += 1;
   }
   else{
    same[hang[n - 1]--][n - 1] += 2;
   }
   for (j = 0; j < 6; j++){
    for (k = 0; k < 7; k++){
     if (k + 3 < 7){
      if ((same[j][k] == 1 && same[j][k + 1] == 1 && same[j][k + 2] == 1 && same[j][k + 3] == 1)){
       res = 1;
      }
      if (same[j][k] == 2 && same[j][k + 1] == 2 && same[j][k + 2] == 2 && same[j][k + 3] == 2){
       res = 2;
      }
     }
     if (j + 3 < 6 && k + 3 < 7){
      if ((same[j][k] == 1 && same[j + 1][k + 1] == 1 && same[j + 2][k + 2] == 1 && same[j + 3][k + 3] == 1)){
       res = 1;
      }
      if ((same[j][k] == 2 && same[j + 1][k + 1] == 2 && same[j + 2][k + 2] == 2 && same[j + 3][k + 3] == 2)){
       res = 2;
      }
     }
     if (j + 3 < 6 && k - 3 >= 0){
      if ((same[j][k] == 1 && same[j + 1][k - 1] == 1 && same[j + 2][k - 2] == 1 && same[j + 3][k - 3] == 1)){
       res = 1;
      }
      if ((same[j][k] == 2 && same[j + 1][k - 1] == 2 && same[j + 2][k - 2] == 2 && same[j + 3][k - 3] == 2)){
       res = 2;
      }
     }
     if (j + 3 < 6){
      if ((same[j][k] == 1 && same[j + 1][k] == 1 && same[j + 2][k] == 1 && same[j + 3][k] == 1)){
       res = 1;
      }
      if ((same[j][k] == 2 && same[j + 1][k] == 2 && same[j + 2][k] == 2 && same[j + 3][k] == 2)){
       res = 2;
      }
     }
    }
   }
  }
  cout << res;
  cout << endl;
 }
}
