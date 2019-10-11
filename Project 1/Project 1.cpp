#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

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

//function to insert the value into the board
void insertBoard(int input, char player, char arry[6][7]) {
	int i = 0;

	for (i = 6; i >= 0; i--) {
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
	char compare1;
	int locArry[2] = {0, 0};
	compare1 = '0';
	i = 6 - 1;
	j = 7 - 1;
	empty_space = 0;

	for (i = 6 - 1; i >= 0; i--) {

		for (j = 7 - 1; j >= 0; j--) {

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

				else if ((compare1 == arry[i - 1][j - 1]) && (compare1 == arry[i - 2][j - 2]) && (compare1 == arry[i - 3][j - 3])) {
					if (compare1 == 'X') {
						cout << "DIAGONAL WIN 1 FOR X!\n";
					}
					else if (compare1 == 'O') {
						cout << "DIAGONAL WIN 1 FOR O!\n";
					}
					return true;
				}

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


//function that resets every place on the board to '.'
void resetBoard(char arry[6][7]) {
	int i, j;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 7; j++) {
			arry[i][j] = '.';
		}
	}
}

//have an artificial player try to beat the player
void aiPlayer(char arry[6][7]) {
	//int i, j;
	//char compare1;

	//for (i = 6 - 1; i >= 0; i--) {

	//	for (j = 7 - 1; j >= 0; j--) {

	//		if (arry[i][j] != '.') {
	//			compare1 = arry[i][j];
	//			if ((compare1 == arry[i - 1][j]) && (compare1 == arry[i - 2][j]) && (compare1 == arry[i - 3][j])) {

	//			}
	//			else if ((compare1 == arry[i][j - 1]) && (compare1 == arry[i][j - 2]) && (compare1 == arry[i][j - 3])) {

	//			}

	//			else if ((compare1 == arry[i - 1][j - 1]) && (compare1 == arry[i - 2][j - 2]) && (compare1 == arry[i - 3][j - 3])) {

	//			}

	//			else if ((compare1 == arry[i - 1][j + 1]) && (compare1 == arry[i - 2][j + 2]) && (compare1 == arry[i - 3][j + 3])) {

	//			}
	//			else {
	//				continue;
	//			}
	//		}
	//		else {
	//			
	//		}
	//	}
	//}

}
 
int main() {
	//creating variables
	bool win;
	int i, j, n, in;
	char player1, player2, repeat;

	//initializing variables
	win = 0;
	repeat = 'y';
	i = 0;
	j = 0;
	n = 5;
	in = 0;
	player1 = 'X';
	player2 = 'O';

	//creating and initializing the board
	char board[6][7] = {};
	
	do {
		resetBoard(board);
			   
		do {
			viewBoard(board);
			cout << "Player X: Place your piece on the board by entering a column number:\n";
			cin >> in;

			while (cin.fail() || in < 1 || in > 7) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Input not recognized. Please pick a valid column number!\n";
				cin >> in;
			}
			in = in - 1;

			insertBoard(in, player1, board);
			win = checkBoard(board);
			viewBoard(board);

			if (win == 0) {
				cout << "Player O: Place your piece on the board by entering a column number:\n";
				cin >> in;

				while (cin.fail() || in < 1 || in > 7) {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout << "Input not recognized. Please pick a valid column number!\n";
					cin >> in;

				}

				in = in - 1;
				insertBoard(in, player2, board);
				win = checkBoard(board);
				//viewBoard(board, boardCol);
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