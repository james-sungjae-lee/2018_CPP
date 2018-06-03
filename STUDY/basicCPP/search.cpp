#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  string input;
  int i = 0;
  int cat_appearance = 0;

  std::cout << "Please enter a line of text : " << '\n';
  getline(cin, input, '\n');

  for (i = input.find("cat", 0); i < string::npos ; i = input.find("cat", i)) {
    cat_appearance++;
    i++;
  }
  std::cout << '\n'<< "The word cat appears "<<
   cat_appearance << " in the string" << '"' << input << '"' << '\n';



  return 0;
}
