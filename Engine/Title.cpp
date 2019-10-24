#include "Title.h"

void Title::startGame(MainWindow& wnd)
{
	//WIP - activable by pressing on a button by mouse
	if (wnd.kbd.KeyIsPressed(VK_RETURN))
	{
		isStarted = true;
	}
}

void Title::drawMenu(Graphics& gfx, MainWindow& wnd)
{
	for (int y = 200; y < 400; ++y)
	{
		for (int x = 300; x < 600; ++x)
		{
			gfx.PutPixel(x, y, Colors::Magenta);
		}
	}
}
