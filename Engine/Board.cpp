#include "Board.h"

void Board::drawBoard(Graphics& gfx, Color c)
{
	//Drawing the st00pid line in the middle of the board -_-
	for (int i = 0; i < 599; i++)
	{
		i += 5;
		gfx.PutPixel(400, i, c);
	}
	//
}
