#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool checkKim(string s){
  if (s.find("김") != string::npos) {
    return true;
  }else{
    return false;
  }
}

int main(int argc, char const *argv[]) {
  string names[5] = {"김철수", "박문수", "강감찬", "김유신", "이순신"};
  std::vector<string> vec(&names[0], &names[5]);

  std::vector<string>::iterator it;
  it = vec.begin();
  while (true) {
    it = find_if(it, vec.end(), checkKim);
    if (it == vec.end()) {
      break;
    }
    std::cout << "위치 "<< distance(vec.begin(), it) + 1 << "번째에서 "<< *it<< "가 발견됨"<< '\n';
    it++;
  }
  return 0;
}
