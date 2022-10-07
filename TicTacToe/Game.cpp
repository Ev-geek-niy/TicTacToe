#include "Game.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

void Game::init() {
	gameLoop();

	cout << "Player " << firstPlayer << " win!";
	cin.ignore();
	cin.get();
}

void Game::gameLoop() {
	int index;

	while (!checkWin()) {
		char mark = firstPlayer ? 'X' : 'O';

		renderBoard();
		setMark(mark);

		if (checkWin())
			break;

		firstPlayer = !firstPlayer;
	}
}

void Game::setMark(char mark) {
	int index;
	while (true) {
		cout << "Player, choose cell to place " << mark << " : ";
		cin >> index;
		if (index <= 0 || index >= 10) {
			cout << "Wrong number" << endl;
		}
		else if (board[index] == 'X' || board[index] == 'O') {
			cout << "Already taken" << endl;
		}
		else {
			board[index] = mark;
			break;
		}
	}
}

bool Game::checkWin() {
		//Rows
	if (board[1] == board[2] && board[2] == board[3] ||
		board[4] == board[5] && board[5] == board[6] ||
		board[7] == board[8] && board[8] == board[9] ||
		//Columns
		board[1] == board[4] && board[4] == board[7] ||
		board[2] == board[5] && board[5] == board[8] ||
		board[3] == board[6] && board[6] == board[9] ||
		//Diagonals
		board[1] == board[5] && board[5] == board[9] ||
		board[3] == board[5] && board[5] == board[7])
		return true;
	else if (board[1] != '1' && board[2] != '2' && board[3] != '3' &&
			 board[4] != '4' && board[5] != '5' && board[6] != '6' &&
			 board[7] != '7' && board[8] != '8' && board[9] != '9')
	return false;
}

void Game::renderBoard() {
    system("cls");
	cout << "\n\n   Tic-tac-toe\n";
	cout << "Player 1 (X) | Player 0 (0)\n\n";

	cout << "     |     |     " << endl;
	cout << "  " << board[1] << "  |  " << board[2] << "  |  " << board[3] << "  " << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << board[4] << "  |  " << board[5] << "  |  " << board[6] << "  " << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << board[7] << "  |  " << board[8] << "  |  " << board[9] << "  " << endl;
	cout << "     |     |     " << endl;
}