#include "board.hpp"

void DrawBoard()
{
	printf("   ");
	for (int i = 0; i < 8; i++) {
		putchar('a'+i);
		putchar(' ');
	}
	putchar('\n');
	for (int y = 0; y < 8; y++) {
		putchar('1'+y);
		putchar(' ');
		for (int x = 0; x < 8; x++) {
			putchar('|');
			putchar(CellsForDrawing[Board[y][x]]);
		}
		putchar('|');
		putchar('\n');
	}
}

