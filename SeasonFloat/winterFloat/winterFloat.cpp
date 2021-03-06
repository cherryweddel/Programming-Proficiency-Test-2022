#include <easyx.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include<vector>

using namespace std;

const int MAXSnow = 800;
const int SCREEN_W = 1000;
const int SCREEN_H = 500;
const int SOWN_RADIO = 3;

struct Snow
{
	double	x;		
	int		y;
	double	step;	
	int		color;
	int     radui;		
};

Snow snow[MAXSnow];

// 初始化雪花
void InitStar(int i)
{
	snow[i].x = rand() % SCREEN_W;
	snow[i].y = rand() % SCREEN_H;
	snow[i].radui = rand() % SOWN_RADIO + 1;
	snow[i].step = (rand() % 5000) / 1000.0 + 1;
	snow[i].color = (int)(snow[i].step * 255 / 6.0 + 0.5);	// 速度越快，颜色越亮
	snow[i].color = RGB(snow[i].color, snow[i].color, snow[i].color);
}


void MoveStar(int i)
{


	setlinecolor(RGB(0, 0, 0));
	setfillcolor(RGB(0, 0, 0));
	
	fillcircle((int)snow[i].x, snow[i].y, snow[i].radui);
	snow[i].y += snow[i].step;

	if (snow[i].y > SCREEN_H)	InitStar(i);

	setfillcolor(snow[i].color);
	setlinecolor(snow[i].color);
	fillcircle((int)snow[i].x, snow[i].y, snow[i].radui);

}
	void draw()
	{
		static bool flg = true;
		if (flg)
		{
			for (int i = 0; i < MAXSnow; i++)
				InitStar(i);
			flg = false;
		}
		static int cnt = 0;cnt++;
		while (cnt == 5e6)
		{
			for (int i = 0; i < MAXSnow;i++)	
				MoveStar(i);
			cnt = 0;
		}
	}

int main()
{
	srand((unsigned)time(NULL));
	initgraph(SCREEN_W, SCREEN_H,1);

	while (1)
	{
		draw();
		
	}

	closegraph();
}

