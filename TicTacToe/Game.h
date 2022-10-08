#pragma once
class Game
{
public:
	bool firstPlayer = true;
	char board[10] = {'*',	'1', '2', '3',
							'4', '5', '6',
							'7', '8', '9'};

	void init();
	void gameLoop();
	void renderBoard();
	void setMark(char mark);
	bool checkWin();
};

