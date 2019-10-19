#pragma once
#include "Graphics.h"
#include "MainWindow.h"

class Player
{
public:
	Player(int x, int y, int width, int height, Color c, int player1or2);
	void drawPlayer(Graphics& gfx,int x, int y, Color c);
	void movePlayer(MainWindow& wnd,int player1or2);
		
private:
	int x;
	int y;
	int width;
	int height;
	int player1or2;
	Color c;
};