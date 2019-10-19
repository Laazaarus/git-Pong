#pragma once
#include "Graphics.h"
#include "MainWindow.h"

class Player
{
public:
	Player(int x, int y, int width, int height, Color c, int player1or2);
	void drawPlayer(Graphics& gfx);
	void movePlayer(MainWindow& wnd);
		
private:
	int x;
	int y;
	int width;
	int height;
	int player1or2;
	Color c;
};