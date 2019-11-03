#pragma once
#include "Graphics.h"
#include "MainWindow.h"
#include "Vec2.h"

class Player
{
public:
	Player(Vec2& loc_init, int width, int height, Color c, int player1or2);
	void drawPlayer(Graphics& gfx);
	void movePlayer(MainWindow& wnd, Graphics& gfx, float dt);

	Vec2 getPos();
	int getWidth();
	int getHeight();
	Color getColor();

private:
	Vec2 loc;
	int width;
	int height;
	int player1or2;
	int time = 60;
	int speed = 9;
	int velocity = time * speed;
	Color c;
};