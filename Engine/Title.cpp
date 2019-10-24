#include "Title.h"

void Title::startGame(MainWindow& wnd)
{
	//WIP - activable by pressing on a button by mouse
	if (wnd.kbd.KeyIsPressed(VK_RETURN))
	{
		isStarted = true;
	}
}
//TOOODOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//TOOODOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//TOOODOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//TOOODOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//TOOODOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
void Title::drawMenu(Graphics& gfx, MainWindow& wnd)
{
	
	drawButton(gfx, wnd, butt1_x, butt1_y, width, height);
	drawButton(gfx, wnd, butt2_x, butt2_y, width, height);
	drawButton(gfx, wnd, butt3_x, butt3_y, width, height);
}

#include "Title.h"

void Title::drawButton(Graphics& gfx, MainWindow& wnd, int x, int y, int width, int height)
{
	for (int loop_y = y; loop_y < y + height; ++loop_y)
	{
		for (int loop_x = x; loop_x < x + width; ++loop_x)
		{
			gfx.PutPixel(loop_x, loop_y, Colors::White);
		}
	}
}

void Title::isButtClicked(MainWindow& wnd)
{
	int mouse_x;
	int mouse_y;

	//Button Hitbox
	const int left_box0 = butt1_x;
	const int right_box0 = butt1_x + width;
	const int top_box0 = butt1_y;
	const int bottom_box0 = butt1_y + height;
	//Player2 Hitbox
	if (wnd.mouse.LeftIsPressed())
	{
		mouse_x=wnd.mouse.GetPosX();
		mouse_y=wnd.mouse.GetPosY();
	}
	//Colision Check
	if (left_box0 <= mouse_x &&
		right_box0 >= mouse_x &&
		top_box0 <= mouse_y &&
		bottom_box0 >= mouse_y)
	{
		isStarted = true;
	}
		
}

