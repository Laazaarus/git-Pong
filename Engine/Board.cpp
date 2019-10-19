#include "Board.h"

void Board::scoreUP(int player)
{
	if (player == 1)
	{
		player1Score++;
	}
	else
	{
		player2Score++;
	}
}

void Board::goFaster(Ball& bll, Player& play1, Player& play2)
{
	if (scores&5==0)
	{
		play1.speedUp();
		play2.speedUp();
		bll.speedUp();
	}
}

void Board::drawBoard(Graphics& gfx, Ball& bll, Player& play1, Player& play2,Color c)
{
	//Drawing the st00pid line in the middle of the board -_-
	for (int i = 0; i < 599; i++)
	{
		i += 5;
		gfx.PutPixel(400, i, c);
	}
	//Score system
	//
	//Drawing score

	//SpeedUp
	goFaster(bll, play1, play2);
}
