#include <iostream>
using namespace std;

class Time{
private:
  int hour;
  int minute;
  int second;
public:
  Time();
  Time(int h, int m, int s);
  void setTime(int h, int m, int s);
  void printInfo();
};

Time::Time(){
  setTime(0, 0, 0);
}

Time::Time(int h, int m, int s){
  setTime(h, m, s);
}

void Time::setTime(int h, int m, int s){
  hour = ((h >= 0 && h < 24) ? h : 0);
  minute = ((m >= 0 && m < 60) ? m : 0);
  second = ((s >= 0 && s < 60)? s : 0);
}

void Time::printInfo() {
  std::cout << hour << " " << minute << " " << second << '\n';
}

int main(int argc, char const *argv[]) {
  Time time1;
  time1.printInfo();

  Time time2(13, 27, 6);
  time2.printInfo();

  Time time3(99, 66, 77);
  time3.printInfo();  

  return 0;
}
