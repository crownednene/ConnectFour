#include <iostream>
#include <cstring>

using namespace std;

//displays the board in it's current state
void viewBoard(char arry[6][7]) {
	int a, b;
	a = 0;
	b = 0;
	
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
void insertBoard(int bsize,int input, char player, char arry[6][7]) {
	int i = 0;

	for (i = bsize; i != 0; i--) {
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
	int a, b;
	char compare1, compare2;
	int locArry[2] = {0, 0};
	compare1 = '0';
	compare2 = '0';
	a = 6 - 1;
	b = 7 - 1;

	for (; a > 0; a--) {
		for (; b > 0; b--) {
			if (arry[a][b] != '.') {
				compare1 = arry[a][b];
				if ((compare1 == arry[a - 1][b]) && (compare1 == arry[a - 2][b]) && (compare1 == arry[a - 3][b])) {
					cout << "WIN!";
					return true;
				}
				else if ((compare1 == arry[a][b-1]) && (compare1 == arry[a][b-2]) && (compare1 == arry[a][b-3])) {
					cout << "WIN!";
					return true;
				}
				//doesnt work
				else if ((compare1 == arry[a - 1][b - 1]) && (compare1 == arry[a - 2][b - 2]) && (compare1 == arry[a - 3][b - 3])) {
					cout << "WIN!";
					return true;
				}
				//doesnt work
				else if ((compare1 == arry[a - 1][b + 1]) && (compare1 == arry[a - 2][b + 2]) && (compare1 == arry[a - 3][b + 3]) && b ) {
					cout << "WIN!";
					return true;
				}
				else {
					continue;
				}
			}	
		}
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