#pragma once
#include "Graphics.h"
#include "MainWindow.h"
#include "GigaPixel.h"
#include "Player.h"
#include "Board.h"
#include <random>

class Ball
{
public:
	Ball(int x, int y, int dim, Color c);
	void drawBall(Graphics& gfx);
	void collisionBall(Player& play1, Player& play2, Graphics& gfx);
	void ballScript(Graphics& gfx, Board& brd);
	void startBall();

private:

	int x;
	int y;
	int vx = 0;
	int vy = 0;
	int dim;
	int whoStarts;
	bool isStarted = false;
	Color c;
};