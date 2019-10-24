#pragma once
#include "Graphics.h"
#include "MainWindow.h"
#include "Ball.h"
#include "Title.h"

class Title
{
public:
	//Menu
	void startGame(MainWindow& wnd);
	void drawMenu(Graphics& gfx, MainWindow& wnd);
	//Buttons
	void drawButton(Graphics& gfx, MainWindow& wnd, int x, int y, int width, int height);
	void isButtClicked(MainWindow& wnd);

	bool isStarted = false;
private:
	const int butt1_x = 275;
	const int butt2_x = 275;
	const int butt3_x = 275;

	const int butt1_y = 500;
	const int butt2_y = 400;
	const int butt3_y = 300;

	const int width = 250;
	const int height = 50;
};