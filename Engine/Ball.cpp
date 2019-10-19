#include "Ball.h"

Ball::Ball(int x, int y, int dim, Color c)
	:
	x(x),
	y(y),
	c(c),
	dim(dim)
{
	std::mt19937 rng;
	std::uniform_int_distribution<int> start(0, 1);
	whoStarts = start(rng);
}

void Ball::drawBall(Graphics& gfx)
{
	for (int int_y = y; int_y < y + dim; ++int_y)
	{
		for (int int_x = x; int_x < x + dim; ++int_x)
		{
			gfx.PutPixel(int_x, int_y, c);
		}
	}
}

void Ball::collisionBall(Player& play1, Player& play2, Graphics& gfx)
{
	//Ball Hitbox
	const int left_box0 = x;
	const int right_box0 = x + dim;
	const int top_box0 = y;
	const int bottom_box0 = y + dim;
	//Player1 Hitbox
	const int left_box1 = play1.getX();
	const int right_box1 = play1.getX() + play1.getWidth();
	const int top_box1 = play1.getY();
	const int bottom_box1 = play1.getY() + play1.getHeight();
	//Player2 Hitbox
	const int left_box2 = play2.getX();
	const int right_box2 = play2.getX() + play2.getWidth();
	const int top_box2 = play2.getY();
	const int bottom_box2 = play2.getY() + play2.getHeight();
	//Colision Check
	if ((left_box0 <= right_box1 &&
		right_box0 >= left_box1 &&
		top_box0 <= bottom_box1 &&
		bottom_box0 >= top_box1)
		||
		(left_box0 <= right_box2 &&
		right_box0 >= left_box2 &&
		top_box0 <= bottom_box2 &&
		bottom_box0 >= top_box2))
	{
		vx = -vx;
		//vy = -vy;
	}
}


void Ball::ballScript(Graphics& gfx, Board& brd)
{
	//Ball wall limits an behaviours
	//
	//Up Wall
	if (y - 5 <= 0)
	{
		y = 6;
		vy = -vy;
	}
	//Down Wall
	if (y + 5 + dim >= gfx.ScreenHeight)
	{
		y = gfx.ScreenHeight - 6 - dim;
		vy = -vy;
	}
	//Right Wall
	if (x + 5 + dim >= gfx.ScreenWidth)
	{
		x = gfx.ScreenWidth - 6 - dim;
		vx = -vx;
	}
	//Left Wall
	if (x - 5 <= 0)
	{
		x = 6;
		vx = -vx;
	}
	//Ball movement
	x += vx;
	y += vy;
}

void Ball::startBall()
{
	if (isStarted)
	{
	}
	else
	{
		isStarted = true;
		if (whoStarts == 0)
		{
			vx = -4;
			vy = 4;
		}
		else
		{
			vx = 4;
			vy = 4;
		}
	}
}