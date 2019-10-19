#include "Ball.h"

Ball::Ball(int x, int y,int dim, Color c)
	:
	x(x),
	y(y),
	c(c),
	dim(dim)
{
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
