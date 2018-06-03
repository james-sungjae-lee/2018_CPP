#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class MyPoint
{
public:
	// constructors
	MyPoint();
	MyPoint(int coordX, int coordY);
	MyPoint(const MyPoint& p);
	// accessor functions
	int getX() const;
	int getY() const;
	// mutator function
	void setX(int x);
	void setY(int y);
	// comparison operators
	bool operator== (const MyPoint& p) const;
	bool operator!= (const MyPoint& p) const;
	// utility functions
	int dist2sqr(const MyPoint& p) const; // 직선거리(Euclidean distance)의 제곱을 계산
	int dist1(const MyPoint& p) const; // 직각거리(rectilinear distance)를 계산
public:
	int x, y;
};
// constructors
MyPoint::MyPoint()
	:x(0), y(0) // set default to origin (0,0)
{
}
MyPoint::MyPoint(int coordX, int coordY)
	: x(coordX), y(coordY)
{
}
MyPoint::MyPoint(const MyPoint& p)
{
	x = p.getX();
	y = p.getY();
}
// accessor functions
int MyPoint::getX() const
{
	return x;
}
int MyPoint::getY() const
{
	return y;
}
// mutator functions
void MyPoint::setX(int coordX)
{
	x = coordX;
}
void MyPoint::setY(int coordY)
{
	y = coordY;
}
bool MyPoint::operator== (const MyPoint& p) const
{
	if (p.getX() == x && p.getY() == y) {
		return true;
	}
	return false;
}
bool MyPoint::operator!= (const MyPoint& p) const
{
	return !operator==(p);
}
// 직선거리(Euclidean distance)의 제곱을 계산
int MyPoint::dist2sqr(const MyPoint& p) const
{
	int result = 0;
	int px = p.getX();
	int py = p.getY();

	result = (x - px) * (x - px) + (y - py) * (y - py);

	return result;

}
// 직각거리(rectilinear distance)를 계산
int MyPoint::dist1(const MyPoint& p) const
{
	int result = 0;
	int px = p.getX();
	int py = p.getY();

	px = px - x;
	py = py - y;
	if (px < 0) {
		px = -px;
	}
	if (py < 0) {
		py = -py;
	}
	result = px + py;

	return result;

}

class MyLineSegment
{
public:
	// constructors
	MyLineSegment();
	MyLineSegment(const MyPoint& p, const MyPoint& q);
	MyLineSegment(const MyLineSegment& seg);
	// intersection test functions
	bool isEndOfSegment(const MyPoint & p) const;
	bool isOnSegment(const MyPoint& p) const;
	bool properIntersection(const MyLineSegment &s) const;
	bool improperIntersection(const MyLineSegment &s) const;
	bool isLeftSide(const MyPoint &p) const; // test whether p is to the left side ofthe direction from p1 to p2
	bool isCollinear(const MyPoint &p) const; // test whether p1, p2, p3 is collinear
												  // utility functions
	int length2sqr() const; // square of (Euclidean) length
private:
	MyPoint p1, p2;
	int getArea2(const MyPoint &p) const; // signed area of triangle p1, p2, p
};
// constructors
MyLineSegment::MyLineSegment()
	: p1(0, 0), p2(0, 0)
{
}
MyLineSegment::MyLineSegment(const MyPoint& p, const MyPoint& q)
	: p1(p), p2(q)
{
}
MyLineSegment::MyLineSegment(const MyLineSegment& s)
	: p1(s.p1), p2(s.p2)
{
}
// 점 p 가 삼각형의 꼭지점에 위치하는 지를 검사
bool MyLineSegment::isEndOfSegment(const MyPoint & p) const
{
	if (p == p1 || p == p2)
		return true;
	else
		return false;
}
// 점 p 가 삼각형의 꼭지점을 제외한 삼각형의 변 위에 위치하는 지를 검사
bool MyLineSegment::isOnSegment(const MyPoint& p) const
{
	if (isCollinear(p) && !isEndOfSegment(p)) {
		return true;
	}
	return false;
}
bool MyLineSegment::properIntersection(const MyLineSegment &s) const
{
	if (((s.isLeftSide(p1) && !s.isLeftSide(p2)) || (!s.isLeftSide(p1) && s.isLeftSide(p2)))
		&& ((isLeftSide(s.p1) && !isLeftSide(s.p2)) || (!isLeftSide(s.p1) && isLeftSide(s.p2)))
		&& !improperIntersection(s)) {
		return true;
	}
	return false;

}
bool MyLineSegment::improperIntersection(const MyLineSegment &s) const
{
	if (s.isEndOfSegment(p1) || s.isEndOfSegment(p2) || s.isOnSegment(p1) || s.isOnSegment(p2)
		|| isOnSegment(s.p1) || isOnSegment(s.p2) || isEndOfSegment(s.p1) || isEndOfSegment(s.p2)) {
		return true;
	}
	return false;
}
// square of (Euclidean) length
int MyLineSegment::length2sqr() const
{
	return p1.dist2sqr(p2);
}
// signed area of triangle p1, p2, p
int MyLineSegment::getArea2(const MyPoint &p) const // signed area of triangle p1, p2, p
{
	int p1x, p2x, px, p1y, p2y, py;
	p1x = p1.getX();
	p1y = p1.getY();
	p2x = p2.getX();
	p2y = p2.getY();
	px = p.getX();
	py = p.getY();
	return p1x * p2y - p1y * p2x +
		p1y * px - p1x * py +
		p2x * py - px * p2y;
}
// test whether p is to the left side of the direction from p1 to p2
bool MyLineSegment::isLeftSide(const MyPoint &p) const
{
	return getArea2(p) > 0;
}
// test whether p1, p2, p3 is collinear
bool MyLineSegment::isCollinear(const MyPoint &p) const
{
	return getArea2(p) == 0;
}


class MyTriangle{
public:
  enum TriangleType1 {NONTRIANGLE = 0, EQUILATERAL = 1, RIGHTTRIANGLE = 2, ISOSCELES = 3, SCALENE = 4};
  enum TriangleType2 {NOT_A_TRIANGLE = 0, RIGHT_TRIANGLE = 1, OBTUSE_TRIANGLE = 2, ACUTE_TRIANGLE = 3}; // constructors
  MyTriangle();
  MyTriangle (const MyPoint &a, const MyPoint &b, const MyPoint &c);
  MyTriangle (const MyTriangle& t);
  // test funtions
  bool isInside ( MyPoint& p) ;
  bool isOnBoundary ( MyPoint& p) ;
  bool isOutside (MyPoint& p);
	int sign(MyPoint p1, MyPoint p2, MyPoint p3){
		return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
	}
  // utility functions
  int getArea2() const;
  TriangleType1 getType1() const;
  TriangleType2 getType2() const;
public:
  MyPoint p1, p2, p3;
  int area2() const;
};

MyTriangle::MyTriangle() : p1(0, 0), p2(0, 0), p3(0, 0){

}

// set p1, p2, p3 be in counterclockwise order
MyTriangle::MyTriangle (const MyPoint& a, const MyPoint& b, const MyPoint& c) : p1(a), p2(b), p3(c){
  MyLineSegment s(p1, p2);
  if (! s.isLeftSide(p3)){
    MyPoint p;
    p = p1;
    p1 = p3;
    p3 = p;
  }
}

MyTriangle::MyTriangle(const MyTriangle& t) : p1(t.p1), p2(t.p2), p3(t.p3){
}

bool MyTriangle::isInside( MyPoint& p){
	bool b1, b2, b3;

	b1 = sign(p, p1, p2) < 0;
	b2 = sign(p, p2, p3) < 0;
	b3 = sign(p, p3, p1) < 0;

	return ((b1 == b2) && (b2 == b3));
}

bool MyTriangle::isOnBoundary( MyPoint& p){
	MyLineSegment s1(p1, p2), s2(p2, p3), s3(p3, p1);
	bool b1 = s1.isOnSegment(p) || s2.isOnSegment(p) || s3.isOnSegment(p);
	bool b2 = p == p1 || p == p2 || p == p3;
	return b1 || b2;
}

bool MyTriangle::isOutside( MyPoint& p) {
  if (isInside(p) || isOnBoundary(p)) {
    return false;
  }else{
    return true;
  }
}

int MyTriangle::getArea2() const{
  return abs(area2());
}

// return type of a triangle
MyTriangle::TriangleType1 MyTriangle::getType1() const{
  TriangleType1 type;
  int a, b, c;
  a = p1.dist2sqr(p2);
  b = p2.dist2sqr(p3);
  c = p3.dist2sqr(p1);

  if (c < a) {
    int temp;
    temp = c;
    c = a;
    a = temp;
  }
  if (c < b) {
    int temp;
    temp = c;
    c = b;
    b = temp;
  }


  if(getArea2() == 0){
    type = NONTRIANGLE;
  }else if (a + b == c) {
		type = RIGHTTRIANGLE;
  }else if (a == b && a == c) {
		type = EQUILATERAL;
  }else if (a == b || b == c || c == a) {
    type = ISOSCELES;
  }else{
    type = SCALENE;
  }
  return type;
}

MyTriangle::TriangleType2 MyTriangle::getType2() const{
  TriangleType2 type;

  int a, b, c;
  a = p1.dist2sqr(p2);
  b = p2.dist2sqr(p3);
  c = p3.dist2sqr(p1);

  if (c < a) {
    int temp;
    temp = c;
    c = a;
    a = temp;
  }
  if (c < b) {
    int temp;
    temp = c;
    c = b;
    b = temp;
  }

  if (getArea2() == 0) {
    type = NOT_A_TRIANGLE;
  }else if (c == (a + b)) {
    type = RIGHT_TRIANGLE;
  }else if (c > (a + b)) {
    type = OBTUSE_TRIANGLE;
  }else{
    type = ACUTE_TRIANGLE;
  }
  return type;
}

int MyTriangle::area2() const{
  int p1x, p2x, p3x, p1y, p2y, p3y;

  p1x = p1.getX();
  p1y = p1.getY();
  p2x = p2.getX();
  p2y = p2.getY();
  p3x = p3.getX();
  p3y = p3.getY();

  return p1x * p2y - p1y * p2x +
  p1y * p3x - p1x * p3y +
  p2x * p3y - p3x * p2y;
}

int main(int argc, char const *argv[]) {
  ifstream inStream;
  int numTestCases;

  inStream.open("input.txt");
  if (inStream.fail()) {
    std::cerr << "error" << '\n';
    exit(1);
  }
  inStream >> numTestCases;

  for (size_t i = 0; i < numTestCases; i++) {
    int p1x, p1y, p2x, p2y, p3x, p3y;
    int qx, qy;

    inStream >> p1x >> p1y >> p2x >> p2y >> p3x >> p3y;
    inStream >> qx >> qy;

    MyPoint p1(p1x, p1y), p2(p2x, p2y), p3(p3x, p3y);
    MyPoint q(qx, qy);
    MyTriangle tri(p1, p2, p3);
    if (tri.getArea2() == 0) {
      std::cout << "0" << '\n';
    }else{
      std::cout << tri.getArea2() << " ";
      std::cout << tri.getType1() << " " << tri.getType2() << " ";

      if (tri.isOnBoundary(q)) {
        std::cout << "2" << '\n';
      }else if (tri.isInside(q)) {
      	std::cout << "1" << '\n';
      }else if (tri.isOutside(q)) {
      	std::cout << "3" << '\n';
      }
    }
  }
  inStream.close();
  return 0;
}


















//
