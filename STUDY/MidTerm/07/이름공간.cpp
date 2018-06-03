#include <iostream>
using namespace std;

int mode;

namespace Graphics{
  int mode;
  int x, y;
  void draw() {
    std::cout << "Graphics 의 draw" << '\n';
  };
}

namespace Network{
  int mode, speed;
  void draw() {
    std::cout << "Network 의 draw" << '\n';
  }
}
int main(int argc, char const *argv[]) {
  Network::draw();
  Graphics::draw();
  return 0;
}
