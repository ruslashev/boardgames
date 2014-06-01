#include "board.hpp"

void DrawBoard()
{
	const bool numbersOnTheRight = true;
	
	if (numbersOnTheRight) {
		printf("  ");
		for (int i = 0; i < 8; i++) {
			printf("%c ", 'a'+i);
		}
		putchar('\n');
		for (int y = 0; y < 8; y++) {
			putchar(' ');
			for (int x = 0; x < 8; x++) {
				putchar('|');
				putchar(CellsForDrawing[Board[y][x]]);
			}
			printf("| %c\n", '1'+y);
		}
	} else {
		printf("   ");
		for (int i = 0; i < 8; i++) {
			printf("%c ", 'a'+i);
		}
		putchar('\n');
		for (int y = 0; y < 8; y++) {
			printf("%c ", '1'+y);
			for (int x = 0; x < 8; x++) {
				putchar('|');
				putchar(CellsForDrawing[Board[y][x]]);
			}
			printf("|\n");
		}
	}
}

