#include <iostream>
#include <cstring>

using namespace std;

//displays the board in it's current state
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

//function to insert the value into the board
void insertBoard(char x, char arry[6][7]) {
	
}

//function to check if there was a win
	//only call this function after each player has gone 4 times(?)
bool checkBoard(char arry[6][7]) {
	//if win
	return true;

	//else
	//return false;
}


int main() {
	//creating variables
	bool win, done;
	int i, j, n, in;

	//initializing variables
	win = 0;
	done = 1;
	i = 0;
	j = 0;
	n = 5;
	in = 0;

	//creating and initializing the board
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
		in = in - 1;


		for (i = n; i != 0; i--) {
			if (board[i][in] == '.') {
				board[i][in] = 'X';
				break;
			}
			else if ((board[i][in] != '.') && (i == 0)) {
				break;
			}
			else {
				i--;
			}
		}


		viewBoard(board);

		cout << "Place a piece ('O') on the board by entering a column number:\n";
		cin >> in;
		in = in - 1;

		for (i = n; i != 0; i--) {
			if (board[i][in] == '.') {
				board[i][in] = '0';
				break;
			}
			else if ((board[i][in] != '.') && (i == 0)) {
				break;
			}
			else {
				i--;
			}
		}

		viewBoard(board);
		win = true;

	} while (!win && done);


	return 0;
}