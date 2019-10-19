/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	play1(100, 250, 10, 50, Colors::Cyan, 1),
	play2(700, 250, 10, 50, Colors::Magenta, 2),
	bll(400-5, 200, 10, Colors::White)
{
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	//Start a ball
	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		bll.startBall();
	}
	//Player & BallMovement
	play1.movePlayer(wnd, gfx);
	play2.movePlayer(wnd, gfx);
	bll.ballScript(gfx, brd);
	//Colision 
	bll.collisionBall(play1, play2, gfx);
	//Score System
}

void Game::ComposeFrame()
{
	//Ball
	bll.drawBall(gfx);
	play1.drawPlayer(gfx);
	play2.drawPlayer(gfx);
	//Center Line
	for (int i = 0; i < 599; i++)
	{
		i += 5;
		gfx.PutPixel(400, i, r, g, b);
	}
	//
}