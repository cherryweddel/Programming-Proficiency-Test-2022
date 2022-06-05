#include <easyx.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include<vector>

using namespace std;

const int MAXrain = 500;
const int SCREEN_W = 1000;
const int SCREEN_H = 500;

struct Rain
{
	double	x;		
	int		y;
	double	step;	
	int		color;	

};

Rain rain[MAXrain];


void InitStar(int i)
{
	rain[i].x = rand() % SCREEN_W;
	rain[i].y = rand() % SCREEN_H;
	rain[i].step = (rand() % 500) / 100.0 + 1;
	rain[i].color = (int)(rain[i].step * 255 / 6.0 + 0.5);	// 速度越快，颜色越亮
	rain[i].color = RGB(rain[i].color, rain[i].color, rain[i].color);
}


void MoveStar(int i)
{
	setlinecolor(RGB(0, 0, 0));
	setfillcolor(RGB(0, 0, 0));
	
	line((int)rain[i].x, rain[i].y, rain[i].x, rain[i].y + 15);

	rain[i].y += rain[i].step;
	if (rain[i].y > SCREEN_H)	InitStar(i);

	setfillcolor(rain[i].color);
	setlinecolor(rain[i].color);

	line((int)rain[i].x, rain[i].y, rain[i].x, rain[i].y + 15);
}



void draw()
{
	static bool flg = true;
	if (flg)
	{
		for (int i = 0; i < MAXrain; i++)
			InitStar(i);
		flg = false;
	}
	static int cnt = 0;cnt++;
	while (cnt == 5e6)
	{
		for (int i = 0; i < MAXrain;i++)
			MoveStar(i);
		cnt = 0;
	}

}
int main()
{
	srand((unsigned)time(NULL));
	initgraph(SCREEN_W, SCREEN_H);

	while (1)
	{
		draw();
	}

	closegraph();
}

