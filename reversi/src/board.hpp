#ifndef BOARD_HPP
#define BOARD_HPP

#include <fstream>

enum Cell { CELL_EMPTY, CELL_WHITE, CELL_BLACK };
const char CellsForDrawing[3] = { 'x', 'o', 'O' };
static Cell Board[8][8] = { { CELL_EMPTY } };

void DrawBoard();

#endif

