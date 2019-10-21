#pragma once
#include "Graphics.h"
#include "MainWindow.h"

class Player
{
public:
	Player(int x, int y, int width, int height, Color c, int player1or2);
	void drawPlayer(Graphics& gfx);
	void movePlayer(MainWindow& wnd, Graphics& gfx, float dt);

	int getX();
	int getY();
	int getWidth();
	int getHeight();
	Color getColor();

private:
	int x;
	int y;
	int width;
	int height;
	int player1or2;
	int time = 60;
	int speed = 9;
	int velocity = time * speed;
	Color c;
};