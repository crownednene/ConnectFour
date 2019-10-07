#include <iostream>
#include <cstring>

using namespace std;

void viewBoard(char arry[6][7]) {
	int a, b;
	cout << "1234567\n";
	for (a = 0; a < 6; a++) {
		for (b = 0; b < 7; b++) {
			cout << arry[a][b];
		}
		cout << "\n";
	}
	cout << "\n";
}


int main() {

	bool win, done;
	int i, j, n, in;

	win = 0;
	done = 0;
	i = 0;
	j = 0;
	n = 5;
	in = 0;

	char board[6][7] = {
		{'.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.'}
	};

	do {

		viewBoard(board);
		cout << "Place a piece ('X') on an available spot on the board by entering a column number:\n";
		cin >> in;
		do {
			if ((board[i][in] != 'X') && (board[i][in] != 'O')) {
				board[i][in] == 'X';
				break;
			}
			else if (board[i][in] != '.' && i == 0) {
				break;
			}
			else {
				i--;
			}
		} while (!done);


		viewBoard(board);
		win = true;

		//cout << "Place a piece ('O') on the board by entering a column number:\n";



	} while (!win && done);





	return 0;
}