#include <easyx.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include<vector>

using namespace std;

#define MAXrain 500	
#define SCREEN_W 1000	
#define SCREEN_H 500	
#define RAIN_RADIO 3	
#define rain_SLEEP 0	

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


int main()
{
	srand((unsigned)time(NULL));
	initgraph(SCREEN_W, SCREEN_H);


	for (int i = 0; i < MAXrain; i++)
	{
		InitStar(i);
		rain[i].x = rand() % SCREEN_W;
	}


	while (1)
	{
		for (int i = 0; i < MAXrain; i++)
			MoveStar(i);
		Sleep(rain_SLEEP);
	}


	closegraph();
}

