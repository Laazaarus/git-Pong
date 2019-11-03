#pragma once

struct Vec2
{
	Vec2() = default;
	Vec2(int x_ini, int y_init);
	//////////
	Vec2 operator+(Vec2& right_side) const;
	Vec2& operator+=(Vec2& right_side);
	Vec2 operator-(Vec2& right_side) const;
	Vec2& operator-=(Vec2& right_side);
	//////////
	int x;
	int y;
};