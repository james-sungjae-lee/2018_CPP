#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

const int max_size = 50;

class MyMagicSquareEven {
public:
	MyMagicSquareEven() : size(0) {

	}
	MyMagicSquareEven(int n) : size(n) {
		if (n % 2 == 1 || n < 1 || n > max_size)
			exit(1);
		makeSquare();
		if (!checkSquare())
			exit(1);
	}
	void printSquare() const {
		for (int i = 0;i < size;i++) {
			for (int j = 0;j < size;j++)
				cout << square[i][j] << " ";
			cout << endl;
		}
	}

private:
	int square[max_size][max_size];
	int size;
	void makeSquare() {
		if (size % 4 == 0) {
			int num = 1;
			for (int i = 0;i < size;i++) {
				for (int j = 0;j < size;j++)
					square[i][j] = num++;
			}
			int y = 0, x = 0;
			for (int i = 0;i < (size / 4)*(size / 4);i++) {
				for (int k = 0;k < 4;k++) {
					square[y+k][x+k] = size * size + 1 - square[y+k][x+k];
					square[y + k][x + 3 - k] = size * size + 1 - square[y + k][x + 3 - k];
				}
				x += 4;
				if (x == size) {
					x = 0;
					y += 4;
				}
			}
		}
		else if(size % 4 == 2) {
			int y = 0, x = size / 2 -1;
			int num = 1;
			int k = size / 4;
			for (int i = 0;i < size;i++) {
				for (int j = 0;j < size;j++)
					square[i][j] = 0;
			}
			for (int i = 0;i < (size / 2)*(size / 2);i++) {
				int key;
				if (y / 2 == k && x / 2 == k)
					key = 1;
				else if (y / 2 == k + 1 && x / 2 == k)
					key = 0;
				else if (y / 2 <= k)
					key = 0;
				else if (y / 2 == k + 1)
					key = 1;
				else
					key = 2;
				switch (key)
				{
				case 0 :
					square[y][x+1] = num++;
					square[y + 1][x] = num++;
					square[y + 1][x+1] = num++;
					square[y][x] = num++;
					break;
				case 1:
					square[y][x] = num++;
					square[y + 1][x] = num++;
					square[y + 1][x+1] = num++;
					square[y][x+1] = num++;
					break;
				case 2:
					square[y][x] = num++;
					square[y + 1][x+1] = num++;
					square[y + 1][x] = num++;
					square[y][x+1] = num++;
					break;
				default:
					break;
				}
				int ny = y - 2;
				int nx = x + 2;
				if (ny < 0)
					ny = size - 2;
				if (nx >= size)
					nx = 0;
				if (square[ny][nx] != 0) {
					ny = y + 2;
					nx = x;
				}
				y = ny;
				x = nx;
			}
		}
	}
	bool checkSquare() {
		return true;
	}
};
int main() {
	ifstream inStream;
	int numTestCases;
	inStream.open("input.txt");
	if (inStream.fail()) {
		cerr << "Input file opening failed. \n";
		exit(1);
	}
	inStream >> numTestCases;
	for (int i = 0;i < numTestCases;i++) {
		int size;
		inStream >> size;
		MyMagicSquareEven evenSquare(size);
		evenSquare.printSquare();
	}
}
