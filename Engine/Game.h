/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Player.h"
#include "Ball.h"
#include "Board.h"

class Game
{
public:
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void drawBall(int x, int y, int r, int g, int b);
	void drawPallet(int x, int y, int r, int g, int b);
	void drawWinner(int x, int y);
	int screenLimitX(int x, int vx);
	int screenLimitY(int y, int vy);
	bool collisionTestPalett(int x, int y, int a, int b);
	bool collisionTestWall(int x, int y, int a);
	void drawPixel5(int x, int y, int r, int g, int b);
	void showScore(int x, int y, int s, int r, int g, int b);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	Player play1,play2;
	Ball bll;
	Board brd;
	int ballX = 400;
	int ballY = 200;
	int ballVX = 0;
	int ballVY = 0;
	int pallet1X = 100;
	int pallet1Y = 300;
	int pallet2X = 700;
	int pallet2Y = 300;
	int r = 255;
	int g = 255;
	int b = 255;
	bool inhibit = false;
	bool collisionWall = false;
	bool collisionPalett = false;
	int score1 = 0;
	int score2 = 0;
	/********************************/
};