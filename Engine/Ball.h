#pragma once
#include "Graphics.h"
#include "MainWindow.h"
#include "GigaPixel.h"
#include "Player.h"
#include "Board.h"
#include "MainWindow.h"
#include <random>


class Ball
{
public:
	Ball(int x, int y, int dim, Color c);
	void drawBall(Graphics& gfx);
	void collisionBall(Player& play1, Player& play2, Graphics& gfx);
	void ballScript(Graphics& gfx, Board& brd, float dt);
	void ballLost();
	void startBall(MainWindow& wnd);

private:
	//

	//
	int x;
	int y;
	int vx = 0;
	int vy = 0;
	int time = 60;
	int speed = 7;
	int velocity = time * speed;
	int dim;
	bool isStarted = false;
	Color c;
};