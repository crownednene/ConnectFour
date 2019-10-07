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


//function to check if there was a win



int main() {
	//creating variables
	bool win, done;
	int i, j, n, in;

	//initializing variables
	win = 0;
	done = 0;
	//i = 0;
	j = 0;
	n = 5;
	i = n;
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


		for (; i != 0; i--) {
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

		win = true;

		//cout << "Place a piece ('O') on the board by entering a column number:\n";



	} while (!win && done);





	return 0;
}