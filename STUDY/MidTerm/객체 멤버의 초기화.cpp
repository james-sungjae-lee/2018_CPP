#include <iostream>
#include <cstring>
using namespace std;

class Point{
  int x, y;
public:
  Point(int a, int b) : x(a), y(b){

  }
};

class Rectangle{
  Point p1, p2;
public:
  Rectangle(int x1, int y1, int x2, int y2):p1(x1, y2), p2(x2,y1){
  }
};
