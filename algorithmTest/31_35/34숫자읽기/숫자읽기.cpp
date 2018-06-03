#include <iostream>
#include <fstream>
using namespace std;

typedef unsigned int uint;

void expand(uint value,int count){
 const char * const ones[20] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
  "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
  "Eighteen", "Nineteen" };
 const char * const tens[10] = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
  "Eighty", "Ninety" };

 if (value >= 1000000000){
  expand(value / 1000000000,count);
  cout << "_Billion";
  count++;
  if (value % 1000000000){
   expand(value % 1000000000,count);
  }
 }
 else if (value >= 1000000){
  expand(value / 1000000,count);
  cout << "_Million";
  count++;
  if (value % 1000000){
   expand(value % 1000000,count);
  }
 }
 else if (value >= 1000)
 {
  expand(value / 1000,count);
  cout << "_Thousand";
  count++;
  if (value % 1000)
  {
   expand(value % 1000,count);
  }
 }
 else if (value >= 100)
 {
  expand(value / 100,count);
  cout << "_Hundred";
  count++;
  if (value % 100)
  {
   expand(value % 100,count);
  }
 }
 else if (value >= 20)
 {
  if (count == 0){
   cout << tens[value / 10];
  }
  else{
   cout << "_" << tens[value / 10];
  }
  count++;
  if (value % 10)
  {
   expand(value % 10,count);
  }
 }
 else
 {
  if (count == 0)
   cout << ones[value];
  else
   cout << "_" << ones[value];
 }
}

int main(int argc, char *argv[]){
 fstream infile;
 int numcases;

 infile.open("input.txt");

 infile >> numcases;

 while (numcases--){
  uint n;
  int count = 0;

  infile >> n;

  expand(n,count);
  cout << endl;
 }
}
