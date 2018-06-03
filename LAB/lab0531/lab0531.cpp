#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

std::vector<char> oneEncoder;
std::vector<char> oneDecoder;

template<typename T>
void print(const T& v){
  typename T::const_iterator it;
  cout << " ( ";
  for(it = v.begin(); it != v.end(); ++it){
    cout << *it;
  }
  cout << " ) " << endl;
}

void getinput(){

  map<string, string> dic;

  ifstream file("data", ios::in|ios::binary);

  if (file.is_open()) {
    while (!file.eof()) {
      oneEncoder.push_back(file.get());
      if (file.get() < 20) {
        int num = file.get();
        for (size_t i = 0; i < num; i++) {
          oneDecoder.push_back(file.get());
          if (file.get() < 20) {
            break;
          }
        }
        break;
      }
    }
  }
  file.close();
}

int main(int argc, char const *argv[]) {
  getinput();
  print(oneEncoder);
  print(oneDecoder);
  return 0;
}
