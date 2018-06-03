#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void MolToEng(string morse){
 string const morseCode[] = { ".-", "-...", "-.-.", "-..", ".", "..-.",
  "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
  ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
 string output = "";
 int len = morse.length();
 int index = 0;

 while (index < len){
  string mor = "";
  int count = 0;


  while (morse[index] != '|'&&index<len){
   if (morse[index] == '#'){
    count++;
    break;
   }
   else{
    mor += morse[index];
   }
   index++;
  }
  int pos = 0;

  while (morseCode[pos] != mor&&pos < 26){
   pos++;
  }
  output = 'A' + pos;

  index++;
  if (count == 0)
   cout << output;
  else
   cout <<output << "_";
 }
}

int main(int argc, char *argv[]){
 fstream infile;
 int numcases;

 infile.open("input.txt");

 infile >> numcases;

 while (numcases--){
  string morse;

  infile >> morse;

  MolToEng(morse);
  cout << endl;
 }
}
