#include <iostream>
using namespace std;

class Complex{
  double real;
  double imag;

public:
  Complex();
  Complex(double a, double b);
  ~Complex();

  double getReal();
  double getImag();
  Complex add(const Complex &c);
  void print();
};

Complex::Complex(){
  real = 0;
  imag = 0;
}
Complex::Complex(double a, double b){
  real = a;
  imag = b;
}
Complex::~Complex(){
}

double Complex::getReal(){
  return (real);
}

double Complex::getImag(){
  return (imag);
}

Complex Complex::add(const Complex& c){
  Complex temp;
  temp.real = this->real + c.real;
  temp.imag = this->imag + c.imag;
  return (temp);
}

void Complex::print(){
  std::cout << real << " + " << imag << "i" << '\n';
}

int main(int argc, char const *argv[]) {
  Complex x(2, 3), y(4, 6), z;
  std::cout << "x" << '\n';
  x.print();

  std::cout << "y" << '\n';
  y.print();

  z = x.add(y);
  std::cout << "z = x + y" << '\n';
  z.print();
  return 0;
}
