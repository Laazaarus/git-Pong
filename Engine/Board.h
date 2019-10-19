#pragma once
#include "Graphics.h"
#include "Player.h"
#include "Ball.h"
class Board
{
public:
	void scoreUP(int player);
	void drawScore(Graphics& gfx, int x, int y, Color c);
	void goFaster(Ball& bll, Player& play1,Player& play2);
	//THIS MUST BE ON THE END
	void drawBoard(Graphics& gfx, Ball& bll, Player& play1, Player& play2, Color c);
	//
private:
	int player1Score = 0;
	int player2Score = 0;
	int scores = player1Score + player2Score;
};