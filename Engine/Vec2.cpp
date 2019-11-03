#include "Vec2.h"

Vec2::Vec2(int x_ini, int y_init)
	:
	x(x_ini),
	y(y_init)
{
}

Vec2 Vec2::operator+(Vec2& right_side) const
{
	return Vec2(x+right_side.x,y+right_side.y);
}

Vec2& Vec2::operator+=(Vec2& right_side)
{
	return *this = *this + right_side;
}

Vec2 Vec2::operator-(Vec2& right_side) const
{
	return Vec2(x - right_side.x, y - right_side.y);
}

Vec2& Vec2::operator-=(Vec2& right_side)
{
	return *this = *this = right_side;
}
