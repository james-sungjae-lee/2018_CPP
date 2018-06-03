#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

std::vector<char> oneEncoder;
std::vector<char> oneDecoder;

map<string, string> dic;

template<typename T>
void print(const T& v){
  typename T::const_iterator it;
  cout << " ( ";
  for(it = v.begin(); it != v.end(); ++it){
    cout << *it;
  }
  cout << " ) " << endl;
}

void getinput() {
  ifstream file("data", ios::in|ios::binary);

  if (file.is_open()) {
    for (size_t i = 0; i < 2522; i++) {
      while (!file.eof()) {
        oneEncoder.push_back(file.get());
        if (file.get() < 97) {
          break;
        }
      }
      while (!file.eof()) {
        oneDecoder.push_back(file.get());
        if (file.get() < 97) {
          break;
        }
      }
      print(oneEncoder);
      print(oneDecoder);
      string temp(oneEncoder.begin(), oneEncoder.end()-1);
      string temp2(oneDecoder.begin(), oneDecoder.end()-1);
      dic[temp] = temp2;
      oneEncoder.clear();
      oneDecoder.clear();
    }
  }
  file.close();
}

int main(int argc, char const *argv[]) {
  getinput();
  std::cout << '\n';
  std::cout << "dic : "<< dic["eezplezpz"] << '\n';
  return 0;
}









//
