#include <iostream>
using namespace std;

enum RCODE { SUCCESS, ERROR };

RCODE getline(int x1, int y1, int x2, int y2, float &slope, float &yintercept){
  if (x1 == x2) {
    return ERROR;
  }else{
    slope = (float)(y2 - y1) / (float)(x2 - x1);
    yintercept = y1 - slope * x1;
    return SUCCESS;
  }
}
int main(int argc, char const *argv[]) {
  float s, y;
  if (getline(3, 3, 6, 6, s, y) == ERROR) {
    std::cout << "에러" << '\n';
  }else{
    std::cout << s << " " << y << '\n';
  }
  return 0;
}
