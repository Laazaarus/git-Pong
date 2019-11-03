#include "Ball.h"

Ball::Ball(Vec2& loc_init, int dim, Color c)
	:
	loc(loc_init),
	c(c),
	dim(dim)
{
	
}

void Ball::drawBall(Graphics& gfx)
{
	for (int int_y = loc.y; int_y < loc.y + dim; ++int_y)
	{
		for (int int_x = loc.x; int_x < loc.x + dim; ++int_x)
		{
			gfx.PutPixel(int_x, int_y, c);
		}
	}
}

void Ball::collisionBall(Player& play1, Player& play2, Graphics& gfx)
{
	//Ball Hitbox
	const int left_box0 = loc.x;
	const int right_box0 = loc.x + dim;
	const int top_box0 = loc.y;
	const int bottom_box0 = loc.y + dim;
	//Player1 Hitbox
	const int left_box1 = play1.getPos().x;
	const int right_box1 = play1.getPos().x + play1.getWidth()+5;
	const int top_box1 = play1.getPos().y;
	const int bottom_box1 = play1.getPos().y + play1.getHeight()+5;
	//Player2 Hitbox
	const int left_box2 = play2.getPos().x;
	const int right_box2 = play2.getPos().x + play2.getWidth()+5;
	const int top_box2 = play2.getPos().y;
	const int bottom_box2 = play2.getPos().y + play2.getHeight()+5;
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
		PlaySound(TEXT("hit.wav"), NULL, SND_FILENAME | SND_ASYNC);
		vel.x = -vel.x;
		if (loc.x > 400)
		{
			c = play2.getColor();
		}
		else
		{
			c = play1.getColor();
		}
	}
}

void Ball::ballScript(Graphics& gfx, Board& brd, float dt)
{
	//Ball wall limits an behaviours
	//
	//Up Wall
	if (loc.y - 15 <= 0)
	{
		PlaySound(TEXT("hit.wav"), NULL, SND_FILENAME | SND_ASYNC);
		loc.y = 16;
		vel.y = -vel.y;
	}
	//Down Wall
	if (loc.y + 15 + dim >= gfx.ScreenHeight)
	{
		PlaySound(TEXT("hit.wav"), NULL, SND_FILENAME | SND_ASYNC);
		loc.y = gfx.ScreenHeight - 16 - dim;
		vel.y = -vel.y;
	}
	//Right Wall
	if (loc.x + 15 + dim >= gfx.ScreenWidth)
	{
		PlaySound(TEXT("hurt.wav"), NULL, SND_FILENAME | SND_ASYNC);
		loc.x = gfx.ScreenWidth - 16 - dim;
		ballLost();
	}
	//Left Wall
	if (loc.x - 15 <= 0)
	{
		PlaySound(TEXT("hurt.wav"), NULL, SND_FILENAME | SND_ASYNC);
		loc.x = 16;
		ballLost();
	}
	//Ball movement
	loc.x += vel.x*dt;
	loc.y += vel.y*dt;
}

void Ball::ballLost()
{
	c = Colors::White;
	loc.x = 395;
	loc.y = 200;
	vel.x = 0;
	vel.y = 0;
	isStarted = false;
}

void Ball::startBall(MainWindow& wnd)
{
	//Randomization of who the heck actually starts (will be change to be used only on the first ball)
	//Later the person who got a score will start :)
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> start (0,1);
	int whoStarts = start(rng);

	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		if (isStarted)
		{
		}
		else
		{
			PlaySound(TEXT("hit.wav"), NULL, SND_FILENAME | SND_ASYNC);
			isStarted = true;
			if (whoStarts == 0)
			{
				vel.x = -velocity;
				vel.y = velocity;
			}
			else if (whoStarts == 1)
			{
				vel.x = velocity;
				vel.y = velocity;
			}
		}
	}
}