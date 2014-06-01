#include "board.hpp"
#include <fstream>

int main()
{
	Cell Board[8][8] = { { CELL_EMPTY } };

	Board[4][4] = CELL_WHITE;
	Board[4][3] = CELL_BLACK;
	Board[3][4] = CELL_BLACK;
	Board[3][3] = CELL_WHITE;

	DrawBoard(Board);

	return 0;
}

