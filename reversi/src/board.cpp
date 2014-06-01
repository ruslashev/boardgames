#include "board.hpp"

void DrawBoard(Cell Board[8][8], Player CurrentPlayer)
{
	const bool numbersOnTheRight = false;
	const bool background = true;
	const bool foreground = true;
	const bool showLegalMoves = true;

	if (numbersOnTheRight)
		printf("  ");
	else
		printf("   ");

	for (int i = 0; i < 8; i++) {
		printf("%c ", 'a'+i);
	}
	putchar('\n');

	for (int y = 0; y < 8; y++) {
		if (numbersOnTheRight)
			putchar(' ');
		else
			printf("%c ", '1'+y);

		for (int x = 0; x < 8; x++) {
			bool legalToPlace = LegalToPlace(x, y, Board, CurrentPlayer);
			if (background)
				printf("\x1b[42m");
			putchar('|');
			if (foreground) {
				if (Board[y][x] == CELL_WHITE)
					printf("\x1b[37m");
				else if (Board[y][x] == CELL_BLACK)
					printf("\x1b[30m");
				if (showLegalMoves)
					if (legalToPlace)
						printf("\x1b[31m");
			}
			if (showLegalMoves) {
				if (legalToPlace)
					putchar('.');
				else
					putchar(CellsForDrawing[Board[y][x]]);
			} else
				putchar(CellsForDrawing[Board[y][x]]);
			if (foreground || background)
				printf("\x1b[0m");
		}

		if (background)
			printf("\x1b[42m");
		if (numbersOnTheRight)
			printf("| %c\n", '1'+y);
		else
			putchar('|');
		if (background)
			printf("\x1b[0m");
			putchar('\n');
	}
}

bool LegalToPlace(int x, int y, Cell Board[8][8], Player CurrentPlayer)
{
	if (Board[y][x] != CELL_EMPTY)
		return false;
	int NewPositions[8][2] = {
		{ -1, -1 },
		{  0, -1 },
		{  1, -1 },
		{ -1,  0 },
		{  1,  0 },
		{ -1,  1 },
		{  0,  1 },
		{  1,  1 }
	};
	Cell neededColor = CurrentPlayer == PLAYER_BLACK ? CELL_WHITE : CELL_BLACK;
	int i = 0;
	int numFlipped = 0;
	int newx = x, newy = y;
	while (1) {
		if (i > 7)
			return false;
		int dx = NewPositions[i][0];
		int dy = NewPositions[i][1];
		newx += dx;
		newy += dy;
		if (newx < 0 || newx > 7 || newy < 0 || newy > 7) {
			i++;
			newx = x;
			newy = y;
			numFlipped = 0;
			continue;
		}
		if (Board[newy][newx] == CELL_EMPTY) {
			i++;
			newx = x;
			newy = y;
			numFlipped = 0;
			continue;
		}
		if (Board[newx][newy] == neededColor) {
			numFlipped++;
			continue;
		} else {
			if (numFlipped != 0)
				return true;
			else {
				i++;
				newx = x;
				newy = y;
				numFlipped = 0;
				continue;
			}
		}
	}
	return false;
}

