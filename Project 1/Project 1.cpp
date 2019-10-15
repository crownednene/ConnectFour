#include <iostream>
#include <cstring>
#include <climits>
#include <dos.h>

using namespace std;

//function that resets every place on the board to '.'
void resetBoard(char arry[6][7]) {
	int i, j;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 7; j++) {
			arry[i][j] = '.';
		}
	}
}

//displays the board in it's current state
void viewBoard(char arry[6][7]) {
	int i, j;
	i = 0;
	j = 0;
	
	//loop through the column numbers
	for (j = 1; j <= 7; j++) {
		cout << j;
	}
	cout << "\n";
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 7; j++) {
			cout << arry[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

//inserts the value into the board
void insertBoard(int input, char player, char arry[6][7]) {
	int i = 0;
	input = input - 1;
	
	for (i = 6; i >= 0; i--) {
		if (arry[0][input] == '.') {
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
		else{
			cout << "The column is full, please choose somewhere else to place your piece: ";
			cin >> input;
			while (cin.fail() || input < 1 || input > 7) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Input not recognized. Please pick a valid column number!\n";
				cin >> input;
			}
			insertBoard(input, player, arry);
		}

	}
}

//function to check if there was a win
bool checkBoard(char arry[6][7]) {
	int i, j, empty_space;
	char compare1;
	int locArry[2] = {0, 0};
	compare1 = '0';
	i = 6 - 1;
	j = 7 - 1;
	empty_space = 0;

	//definitely could've been done better but works
	for (i = 5; i >= 0; i--) {
		for (j = 6; j >= 0; j--) {
			if (arry[i][j] != '.') {
				compare1 = arry[i][j];
				//vertical wins
				if ((compare1 == arry[i - 1][j]) && (compare1 == arry[i - 2][j]) && (compare1 == arry[i - 3][j])) {
					if (compare1 == 'X') {
						cout << "VERTICAL WIN FOR X!\n";
					}
					else if (compare1 == 'O') {
						cout << "VERTICAL WIN FOR O!\n";
					}
					return true;
				}	
				else if ((compare1 == arry[i - 1][j]) && (compare1 == arry[i - 2][j]) && (compare1 == arry[i - 5][j])) {
					if (compare1 == 'X') {
						cout << "VERTICAL WIN (wrapped) FOR X!\n";
					}
					else if (compare1 == 'O') {
						cout << "VERTICAL WIN (wrapped) FOR O!\n";
					}
					return true;
				}
				else if ((compare1 == arry[i - 1][j]) && (compare1 == arry[i - 5][j]) && (compare1 == arry[i - 4][j])) {
					if (compare1 == 'X') {
						cout << "VERTICAL WIN (wrapped 2) FOR X!\n";
					}
					else if (compare1 == 'O') {
						cout << "VERTICAL WIN (wrapped 2) FOR O!\n";
					}
					return true;
				}
				else if ((compare1 == arry[i - 5][j]) && (compare1 == arry[i - 4][j]) && (compare1 == arry[i - 3][j])) {
					if (compare1 == 'X') {
						cout << "VERTICAL WIN (wrapped 3) FOR X!\n";
					}
					else if (compare1 == 'O') {
						cout << "VERTICAL WIN (wrapped 3) FOR O!\n";
					}
					return true;
				}
				//horizontal wins
				else if ((compare1 == arry[i][j - 1]) && (compare1 == arry[i][j - 2]) && (compare1 == arry[i][j - 3])) {
					if (compare1 == 'X') {
						cout << "HORIZONTAL WIN FOR X!\n";
					}
					else if (compare1 == 'O') {
						cout << "HORIZONTAL WIN FOR O!\n";
					}
					return true;
				}
				else if ((compare1 == arry[i][j - 1]) && (compare1 == arry[i][j - 2]) && (compare1 == arry[i][j - 6])) {
					if (compare1 == 'X') {
						cout << "HORIZONTAL WIN (wrapped) FOR X!\n";
					}
					else if (compare1 == 'O') {
						cout << "HORIZONTAL WIN (wrapped) FOR O!\n";
					}
					return true;
				}
				else if ((compare1 == arry[i][j - 1]) && (compare1 == arry[i][j - 6]) && (compare1 == arry[i][j - 5])) {
					if (compare1 == 'X') {
						cout << "HORIZONTAL WIN (wrapped 2) FOR X!\n";
					}
					else if (compare1 == 'O') {
						cout << "HORIZONTAL WIN (wrapped 2) FOR O!\n";
					}
					return true;
				}
				else if ((compare1 == arry[i][j - 6]) && (compare1 == arry[i][j - 5]) && (compare1 == arry[i][j - 4])) {
					if (compare1 == 'X') {
						cout << "HORIZONTAL WIN (wrapped 3) FOR X!\n";
					}
					else if (compare1 == 'O') {
						cout << "HORIZONTAL WIN (wrapped 3) FOR O!\n";
					}
					return true;
				}
				//diagonal wins 1
				else if ((compare1 == arry[i - 1][j - 1]) && (compare1 == arry[i - 2][j - 2]) && (compare1 == arry[i - 3][j - 3])) {
					if (compare1 == 'X') {
						cout << "DIAGONAL WIN 1 FOR X!\n";
					}
					else if (compare1 == 'O') {
						cout << "DIAGONAL WIN 1 FOR O!\n";
					}
					return true;
				}

				//diagonal wins 2
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
				return false;
			}
		}
	}
	
	//if the whole board is checked and there are no empty spots, then it's a draw
	if (empty_space == 0) {
		cout << "DRAW! FULL BOARD\n";
		return true;
	}
	return false;
}


//removes the bottom piece
void removeBoard(int input, char player, char arry[6][7]) {
	int i = 5;
	int in = 0;
	char temp = 'n';

	if (arry[i][input] == player) {
		for (i = 5; i > 0; i--) {
			temp = arry[i - 1][input];
			arry[i][input] = temp;
		}
		arry[0][input] = '.';
	}
	else {
		if (arry[i][input] == '.') {
			cout << "This is empty, please pick a different column\n";
		}
		else {
			cout << "This is not one of your pieces, please pick a different column\n";
		}
		cin >> in;
		in = in - 1;
	}	
}

 
int main() {
	//creating variables
	bool win;
	int i, j, n, in;
	char player1, player2, repeat, remove_mode;

	//initializing variables
	win = 0;
	i = 0;
	j = 0;
	n = 5;
	in = 0;
	player1 = 'X';
	player2 = 'O';
	repeat = 'y';
	remove_mode = 'n';


	//creating and initializing the board
	char board[6][7] = {};
	
	do {
		resetBoard(board);
		viewBoard(board);
		cout << "Play with  piece removal mode enabled? Y/N\n";
		cin >> remove_mode;

		while (cin.fail() || ((remove_mode != 'Y') && (remove_mode != 'y') && (remove_mode != 'N') && (remove_mode != 'n'))) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Input not recognized. Please pick Y or N.\n";
			cin >> remove_mode;
		}

		do {
			cout << "Player X: Place your piece on the board by entering a column number or 0 to remove one of your pieces at the bottom:\n";
			cin >> in;

			while (cin.fail() || in < 0 || in > 7) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Input not recognized. Please pick a valid column number!\n";
				cin >> in;
			}

			if (in == 0 && (remove_mode == 'y' || remove_mode == 'Y')) {
				cout << "Select the column whose piece you want removed (it must be one of your pieces):\n";
				cin >> in;
				in = in - 1;
				removeBoard(in, player1, board);
			}
			else {
				insertBoard(in, player1, board);
				win = checkBoard(board);
			}

			viewBoard(board);
			
			if (win == 0) {
				cout << "Player O: Place your piece on the board by entering a column number or 0 to remove one of your pieces at the bottom:\n";
				cin >> in;

				while (cin.fail() || in < 0 || in > 7) {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout << "Input not recognized. Please pick a valid column number!\n";
					cin >> in;
				}

				if (in == 0 && (remove_mode == 'y' || remove_mode == 'Y')) {
					cout << "Select the column whose piece you want removed (it must be one of your pieces):\n";
					cin >> in;
					in = in - 1;
					removeBoard(in, player2, board);
				}
				else {
					insertBoard(in, player2, board);
					win = checkBoard(board);
				}
				viewBoard(board);
			}

		} while (!win);

		cout << "Would you like to play again? Y/N\n";
		cin >> repeat;

		while ((repeat != 'Y') && (repeat != 'y') && (repeat != 'N') && (repeat != 'n')) {
			cout << "Input not recognized. Please pick Y/N\n";
			cin >> repeat;
		} 


	} while (repeat == 'Y' || repeat == 'y');
	

	return 0;
}