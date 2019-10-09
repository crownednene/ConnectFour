#include <iostream>
#include <cstring>

using namespace std;

//displays the board in it's current state
void viewBoard(char arry[6][7]) {
	int i, j;
	i = 0;
	j = 0;
	
	cout << "1234567\n";
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 7; j++) {
			cout << arry[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

//function to insert the value into the board
void insertBoard(int bsize, int input, char player, char arry[6][7]) {
	int i = 0;

	for (i = bsize; i >= 0; i--) {
		if (arry[i][input] == '.') {
			arry[i][input] = player;
			break;
		}
		else if ((arry[i][input] != '.') && (i == 0)) {
			break;
		}
		else {
			continue;
		}
	}
}

//function to check if there was a win
bool checkBoard(char arry[6][7]) {
	int i, j, empty_space;
	char compare1, compare2;
	int locArry[2] = {0, 0};
	compare1 = '0';
	compare2 = '0';
	i = 6 - 1;
	j = 7 - 1;
	empty_space = 0;

	for (i = 6 - 1; i >= 0; i--) {
		//cout << "i: " << i << "\n";
		for (j = 7 - 1; j >= 0; j--) {
			//cout << "j: " << j << "\n";
			if (arry[i][j] != '.') {
				compare1 = arry[i][j];
				if ((compare1 == arry[i - 1][j]) && (compare1 == arry[i - 2][j]) && (compare1 == arry[i - 3][j])) {
					if (compare1 == 'X') {
						cout << "VERTICAL WIN FOR X!\n";
					}
					else if (compare1 == 'O') {
						cout << "VERTICAL WIN FOR O!\n";
					}
					
					return true;
				}
				else if ((compare1 == arry[i][j-1]) && (compare1 == arry[i][j-2]) && (compare1 == arry[i][j-3])) {
					if (compare1 == 'X') {
						cout << "HORIZONTAL WIN FOR X!\n";
					}
					else if (compare1 == 'O') {
						cout << "HORIZONTAL WIN FOR O!\n";
					}
					return true;
				}
				//doesnt work 
				else if ((compare1 == arry[i - 1][j - 1]) && (compare1 == arry[i - 2][j - 2]) && (compare1 == arry[i - 3][j - 3])) {
					if (compare1 == 'X') {
						cout << "DIAGONAL WIN 1 FOR X!\n";
					}
					else if (compare1 == 'O') {
						cout << "DIAGONAL WIN 1 FOR O!\n";
					}
					return true;
				}
				//doesnt work if one of the pieces is in column 1
				else if ((compare1 == arry[i - 1][j + 1]) && (compare1 == arry[i - 2][j + 2]) && (compare1 == arry[i - 3][j + 3])) {
					if (compare1 == 'X') {
						cout << "DIAGONAL WIN 2 FOR X!\n";
					}
					else if (compare1 == 'O') {
						cout << "DIAGONAL WIN 2 FOR O!\n";
					}
					return true;
				}
				else {
					continue;
				}
			}
			else {
				empty_space = empty_space + 1;
			}
		}
	}

	if (empty_space == 0) {
		cout << "DRAW! FULL BOARD\n";
		return true;
	}

	return false;
}


int main() {
	//creating variables
	bool win, done;
	int i, j, n, in;
	char player1, player2;

	//initializing variables
	win = 0;
	done = 1;
	i = 0;
	j = 0;
	n = 5;
	in = 0;
	player1 = 'X';
	player2 = 'O';

	//creating and initializing the board
	char board[6][7] = {
		{'.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.'}
	};

	viewBoard(board);

	do {
		cout << "Player X: Place your piece on the board by entering a column number:\n";
		cin >> in;
		in = in - 1;

		insertBoard(n, in, player1, board);
		win = checkBoard(board);
		viewBoard(board);

		if (win == 0) {
			cout << "Player O: Place your piece on the board by entering a column number:\n";
			cin >> in;
			in = in - 1;
			insertBoard(n, in, player2, board);
			win = checkBoard(board);
			viewBoard(board);
		}

	} while (!win);

	return 0;
}