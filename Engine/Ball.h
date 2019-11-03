#pragma once
#include "Graphics.h"
#include "MainWindow.h"
#include "GigaPixel.h"
#include "Player.h"
#include "Board.h"
#include "MainWindow.h"
#include "Vec2.h"
#include <random>


class Ball
{
public:
	Ball(Vec2& loc_init, int dim, Color c);
	void drawBall(Graphics& gfx);
	void collisionBall(Player& play1, Player& play2, Graphics& gfx);
	void ballScript(Graphics& gfx, Board& brd, float dt);
	void ballLost();
	void startBall(MainWindow& wnd);

private:
	//

	//
	Vec2 loc;
	Vec2 vel = { 0,0 };
	int time = 60;
	int speed = 7;
	int velocity = time * speed;
	short int dim;
	bool isStarted = false;
	Color c;
};