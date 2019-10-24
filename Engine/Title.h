#pragma once
#include "Graphics.h"
#include "MainWindow.h"
#include "Ball.h"

class Title
{
public:
	void startGame(MainWindow& wnd);
	void drawMenu(Graphics& gfx, MainWindow& wnd);



	bool isStarted = false;
private:
};