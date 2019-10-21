#include "Player.h"

Player::Player(int x, int y, int width, int height, Color c, int player1or2)
	:
	x(x),
	y(y),
	c(c),
	width(width),
	height(height),
	player1or2(player1or2)
{
}

void Player::drawPlayer(Graphics& gfx)
{
	for (int int_y = y; int_y < y + height; ++int_y)
	{
		for (int int_x = x; int_x < x + width; ++int_x)
		{
			gfx.PutPixel(int_x, int_y, c);
		}
	}
}

void Player::movePlayer(MainWindow& wnd, Graphics& gfx, float dt)
{
	//Screen Limit
	//Down
	if (y + height + 15 >= gfx.ScreenHeight)
	{
		y = gfx.ScreenHeight - height - 15;
	}
	//Up
	if (y - 15 <= 0)
	{
		y = 15;
	}

	//Moving
	if (player1or2 == 2)
	{
		//UP
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			y -= velocity*dt;
		}
		//DOWN
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			y += velocity * dt;
		}
	}
	else
	{
		//UP
		if (wnd.kbd.KeyIsPressed('W'))
		{
			y -= velocity * dt;
		}
		//DOWN
		if (wnd.kbd.KeyIsPressed('S'))
		{
			y += velocity * dt;
		}
	}
}

int Player::getX()
{
	return x;
}

int Player::getY()
{
	return y;
}

int Player::getWidth()
{
	return width;
}

int Player::getHeight()
{
	return height;
}

Color Player::getColor()
{
	return c;
}


