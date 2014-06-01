#include "board.hpp"

void DrawBoard(Cell Board[8][8])
{
	const bool numbersOnTheRight = false;
	const bool background = true;
	const bool foreground = true;

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
			if (background)
				printf("\x1b[42m");
			putchar('|');
			if (foreground) {
				if (Board[y][x] == CELL_WHITE)
					printf("\x1b[37m");
				else if (Board[y][x] == CELL_BLACK)
					printf("\x1b[30m");
			}
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

