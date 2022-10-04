/*
 * Labo: tictactoe
 * Release date: TODO
 * Project: A small implementation in C++ of the game TicTacToe
 * Authors: Chloé Salamin and Samuel Roland
 */

#include <iostream>
#include <string>

using namespace std;

// Get the winner of a given table (1 = player 1, 2 = player 2, 3 = none of them)
int getWinner(int table[]) {
	int nbMatch1 = 0;
	int nbMatch2 = 0;
	int solutions[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, {3, 5, 7}, {1, 5, 9}};

	for (int *solution : solutions) {
		nbMatch1 = 0;
		nbMatch2 = 0;
		for (int i = 0; i < 3; i++) {
			if (table[solution[i] - 1] == 1) {
				nbMatch1++;
			}
			if (table[solution[i] - 1] == 2) {
				nbMatch2++;
			}
		}

		if (nbMatch1 == 3) {
			return 1;
		}
		if (nbMatch2 == 3) {
			return 2;
		}
	}
	return 3;
}

// Print a line of data of the table (with X O or " ")
void printDataLine(int lineIndex, int table[9]) {
	for (int i = 0; i < 3; i++) {
		cout << " ";

		switch (table[lineIndex * 3 + i]) {
		case 1:
			cout << "X";
			break;
		case 2:
			cout << "O";
			break;
		default:
			cout << " ";
			break;
		}
		cout << " ";

		if (i != 2) {
			cout << "|";
		}
	}
	cout << endl;
}

// Print an empty line with dashes and pipes
void printEmptyLine() { cout << "---|---|---" << endl; }

// Clear the screen (with cls or clear, depending on the OS)
void clearScreen() {
#ifdef _WIN32
	system("cls"); // windows
#else
	system("clear"); // linux
#endif
}

// Print a visual table in the console
void printTable(int table[9]) {
	clearScreen();
	cout << endl;
	// For the 3 lines
	for (int i = 0; i < 3; i++) {
		printDataLine(i, table);
		if (i != 2) {
			printEmptyLine();
		}
	}
	cout << endl;
}

int main() {
	// Testing samples
	// int table[9] = {1, 1, 1, 0, 0, 0, 0, 0, 0}; // 1 is winner
	// int table[9] = {1, 1, 0, 0, 0, 0, 0, 0, 0}; // 0 is winner
	// int table[9] = {1, 0, 1, 1, 1, 0, 1, 0, 0}; // 1 is winner
	// int table[9] = {1, 0, 1, 1, 1, 0, 0, 1, 0}; // no one is winner
	// int table[9] = {1, 1, 1, 0, 0, 0, 0, 0, 0}; // 1 is winner

	int table[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	int coord;
	int iteration = 0;

	// While there is not winner, ask for another case
	while (getWinner(table) == 3) {
		iteration++;
		printTable(table);
		cout << "Player " << (iteration % 2 == 1 ? "1: " : "2: ");

		do {
			cin >> coord;
			if (coord > 9 || coord < 1) {
				cout << "The case number must be between 1 and 9. Try again: ";
			} else if (table[coord - 1] != 0) {
				cout << "Case is already taken. Please give a new case: ";
			}
		} while (coord > 9 || coord < 1 || table[coord - 1] != 0);
		coord--;
		table[coord] = (iteration % 2 ? 1 : 2);
	}

	int winner = getWinner(table);

	printTable(table);

	cout << endl;
	cout << endl;
	cout << "The winner is "
	     << (winner != 3 ? "player " + to_string(winner) + " !" : " no one")
	     << endl;
}
