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
private:
	int x, y;
};

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

int main(void) {
	ifstream inStream;
	int numTestCases;

	inStream.open("input.txt");
	if (inStream.fail()) {
		cerr << "Input Error.\n";
		exit(1);
	}

	inStream >> numTestCases;
	for (int i = 0; i<numTestCases; i++) {
		int ax, ay;
		int bx, by;
		int cx, cy;
		int dx, dy;

		inStream >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

		MyPoint pointA(ax, ay);
		MyPoint pointB(bx, by);
		MyPoint pointC(cx, cy);
		MyPoint pointD(dx, dy);

		MyLineSegment lineA(pointA, pointB);
		MyLineSegment lineB(pointC, pointD);

		if (lineA.properIntersection(lineB)) {
			cout << "1" << endl;
		}
		else if (lineA.improperIntersection(lineB)) {
			cout << "2" << endl;
		}
		else {
			cout << "0" << endl;
		}


	}
	inStream.close();
	return 0;
}
