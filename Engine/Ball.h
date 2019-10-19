#pragma once
#include "Graphics.h"
#include "MainWindow.h"
#include "Player.h"
#include <random>

class Ball
{
public:
	Ball(int x, int y, Color c);
	void drawBall(Graphics& gfx);
	void collisionBall(Player& play1, Player& play2, Graphics& gfx);
private:
	int x;
	int y;
	int vx;
	int vy;
	Color c;

};