#include "Player.h"

Player::Player(int x, int y, int width, int height, Color c, int player1or2)
	:
	x(x),
	y(y),
	c(c),
	width(width),
	height(height)
{
}

void Player::drawPlayer(Graphics& gfx, int x, int y, Color c)
{
	for (int int_y = y; int_y < y + height; ++int_y)
	{
		for (int int_x = x; int_x < x + width; ++int_x)
		{
			gfx.PutPixel(int_x, int_y, c);
		}
	}
}

void Player::movePlayer(MainWindow& wnd, int player1or2)
{
	if (player1or2 == 1)
	{
		//UP
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			y -= 6;
		}
		//DOWN
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			y += 6;
		}
	}
	else
	{
		//UP
		if (wnd.kbd.KeyIsPressed('W'))
		{
			y -= 6;
		}
		//DOWN
		if (wnd.kbd.KeyIsPressed('S'))
		{
			y += 6;
		}
	}
}
