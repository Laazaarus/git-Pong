#pragma once
#include "Graphics.h"
#include "MainWindow.h"

class Player
{
public:
	Player(int x, int y, int width, int height, Color c, int player1or2);
	void drawPlayer(Graphics& gfx);
	void movePlayer(MainWindow& wnd, Graphics& gfx);
	void speedUp();

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
	int playerSpeed = 8;
	Color c;
};