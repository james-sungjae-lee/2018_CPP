#include <iostream>
#include <cstring>
using namespace std;

class V{
  public:
    int x, y;
    explicit V(int x=0): x(x), y(0){ cout << this << " in constuction V("<<x<<")\n"; }
    V(int x, int y): x(x), y(y){ cout << this << " in constuction V("<<x<<","<<y<<")\n"; }
    V(V& v): x(v.x), y(v.y) { cout << this << " in constuction V(V)\n"; }
    V& operator=(const V& v){x=v.x; y=v.y; cout<< this << " <- " << &v << endl; return *this;}
    friend V operator+(const V& v,const V& w){V a; a.x=v.x+w.x; a.y=v.y+w.y; cout<< &a << " + "  << endl; return a;}
    friend ostream& operator<<(ostream &os,const V& v){ os<<"("<< v.x << "," << v.y << ")\n"; return os;}
    operator int() const { return x; }
};


V returnV(int v = 9)
{
   V r(v);
   return r;
}

V& returnVref(int v = 99)
{
   V r(v);
   return r;
}

int main()
{
	V v1, v2(1);
  int t = (int) v1;
  cout << t << endl;
  v1 = returnV(8);
  cout << v1 << endl;
  v1 = (V) 100;
  cout << v1 << endl;
  v1 = v1+v2;
  cout << v1 << endl;
	v2 = returnVref(88);
  cout << v2 << endl;
  cout << (int) v2 << endl;
}
