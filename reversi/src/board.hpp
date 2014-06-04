#ifndef BOARD_HPP
#define BOARD_HPP

#include <fstream>

enum Cell { CELL_EMPTY, CELL_WHITE, CELL_BLACK };
const char CellsForDrawing[3] = { '_', 'o', 'o' };

enum Player { PLAYER_BLACK = 1, PLAYER_WHITE };

void DrawBoard(Cell Board[8][8], Player CurrentPlayer, int *legalMoves);
bool LegalToPlace(int x, int y, Cell Board[8][8], Player CurrentPlayer);
void Flip(int x, int y, Cell (*Board)[8][8], Player CurrentPlayer);
void CountScore(Cell Board[8][8], int *black, int *white);

#endif

