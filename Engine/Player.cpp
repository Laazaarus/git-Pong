#include "Player.h"

Player::Player(Vec2& loc_init, int width, int height, Color c, int player1or2)
	:
	loc(loc_init),
	c(c),
	width(width),
	height(height),
	player1or2(player1or2)
{
}

void Player::drawPlayer(Graphics& gfx)
{
	for (int int_y = loc.y; int_y < loc.y + height; ++int_y)
	{
		for (int int_x = loc.x; int_x < loc.x + width; ++int_x)
		{
			gfx.PutPixel(int_x, int_y, c);
		}
	}
}

void Player::movePlayer(MainWindow& wnd, Graphics& gfx, float dt)
{
	//Screen Limit
	//Down
	if (loc.y + height + 15 >= gfx.ScreenHeight)
	{
		loc.y = gfx.ScreenHeight - height - 15;
	}
	//Up
	if (loc.y - 15 <= 0)
	{
		loc.y = 15;
	}

	//Moving
	if (player1or2 == 2)
	{
		//UP
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			loc.y -= velocity*dt;
		}
		//DOWN
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			loc.y += velocity * dt;
		}
	}
	else
	{
		//UP
		if (wnd.kbd.KeyIsPressed('W'))
		{
			loc.y -= velocity * dt;
		}
		//DOWN
		if (wnd.kbd.KeyIsPressed('S'))
		{
			loc.y += velocity * dt;
		}
	}
}

Vec2 Player::getPos()
{
	return loc;
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


