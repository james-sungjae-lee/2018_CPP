#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class LifeGame {
private:
	char **cell;
	int **next;
	int row;
	int col;
	int num;
public:
	LifeGame(int r, int c);
	void filecell(ifstream &instream);
	void deleteLifeGame();
	int checkcell(int, int);
	void nextLifeGame();
	void printLifeGame();
};


int main() {
	ifstream instream;
	instream.open("input.txt");
	int testcase;

	if (instream.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}

	instream >> testcase;


	for (int i = 0; i < testcase; i++) {
		int row, col, loop;
		instream >> row >> col >> loop;
		LifeGame *lifegame = new LifeGame(row, col);
		lifegame->filecell(instream);
		for (int l = 0; l < loop; l++)
			lifegame->nextLifeGame();
		lifegame->printLifeGame();
		lifegame->deleteLifeGame();
		delete lifegame;
	}


	return 0;
}


LifeGame::LifeGame(int r, int c)
{
	cell = NULL;
	next = NULL;
	row = r;
	col = c;
	num = 0;
}

void LifeGame::filecell(ifstream & instream)
{
	cell = new char*[row];
	next = new int *[row];
	for (int i = 0; i < row; i++) {
		cell[i] = new char[col + 1];
		next[i] = new int[col];
	}


	for (int r = 0; r < row; r++) {
		instream >> cell[r];
	}







}

void LifeGame::deleteLifeGame()
{
	for (int r = 0; r < row; r++) {
		delete[] cell[r];
		delete[] next[r];
	}
	delete[] next;
	delete[] cell;
}

int LifeGame::checkcell(int i, int j)
{
	int check = 0;

	if (j != 0 && i != 0) {
		if (cell[i - 1][j - 1] == 'O')
			check++;
	}
	if (j != 0) {
		if (cell[i][j - 1] == 'O')
			check++;
	}
	if (j != 0 && i != (row - 1)) {
		if (cell[i + 1][j - 1] == 'O')
			check++;
	}
	if (i != (row - 1)) {
		if (cell[i + 1][j] == 'O')
			check++;
	}
	if (i != (row - 1) && j != (col - 1)) {
		if (cell[i + 1][j + 1] == 'O')
			check++;
	}
	if (j != (col - 1)) {
		if (cell[i][j + 1] == 'O')
			check++;
	}
	if (i != 0 && j != (col - 1)) {
		if (cell[i - 1][j + 1] == 'O')
			check++;
	}
	if (i != 0) {
		if (cell[i - 1][j] == 'O')
			check++;
	}

	return check;
}

void LifeGame::nextLifeGame()
{
	num = 0;

	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			next[r][c] = checkcell(r, c);
		}
	}
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			if (next[r][c] <= 1 || next[r][c] >= 4)
				cell[r][c] = 'X';
			else if (next[r][c] == 2 && cell[r][c] == 'O') {
				cell[r][c] = 'O';
				num++;
			}
			else if (next[r][c] == 2 && cell[r][c] == 'X')
				cell[r][c] = 'X';
			else if (next[r][c] == 3) {
				cell[r][c] = 'O';
				num++;
			}
		}
	}

}

void LifeGame::printLifeGame()
{
	cout << num << endl;
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			cout << cell[r][c];
		}
		cout << endl;
	}
}
