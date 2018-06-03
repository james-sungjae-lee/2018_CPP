#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int main(int argc, char const *argv[]) {
  map<string, string> dic;
  dic["boy"] = "소년";

  std::cout << "boy의 의미 : "<< dic["boy"] << '\n';
  std::cout << "unknown의 의미 : "<< dic["unknown"] << '\n';
  return 0;
}
