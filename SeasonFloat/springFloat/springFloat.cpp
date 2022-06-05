#include <easyx.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include<vector>

using namespace std;



const int MAXflower = 50;  //数量
const int SCREEN_W = 1000;
const int SCREEN_H = 500;
const int flower_SLEEP = 20;   //下落速度

struct Flower
{
	double	x;
	int		y;
	double	step;

};

Flower flower[MAXflower];
IMAGE img1;
IMAGE img2;
void InitStar(int i)
{
	flower[i].x = rand() % 1000;
	flower[i].y = rand() % 100;
	flower[i].step = (rand() % 5000) / 1000.0 + 1;
}


void MoveStar(int i)
{
	setlinecolor(RGB(0, 0, 0));
	setfillcolor(RGB(0, 0, 0));
	putimage((int)flower[i].x, flower[i].y, &img2, SRCAND);
	putimage((int)flower[i].x, flower[i].y, &img1, SRCPAINT);
	flower[i].y += flower[i].step;  //下落幅度
	if (flower[i].y > SCREEN_H)	InitStar(i);


	putimage((int)flower[i].x, flower[i].y, &img2, SRCAND);
	putimage((int)flower[i].x,flower[i].y, &img1, SRCPAINT);
}


int main()
{
	srand((unsigned)time(NULL));
	initgraph(SCREEN_W, SCREEN_H);
	loadimage(&img1, _T("./5.png"));
	loadimage(&img2, _T("./6.png"));

	for (int i = 0; i < MAXflower; i++)
	{
		InitStar(i);
		flower[i].x = rand() % SCREEN_W;
	}


	while (1)
	{
		BeginBatchDraw();
		setbkcolor(RED);
		cleardevice();
		for (int i = 0; i < MAXflower; i++)
			MoveStar(i);
		EndBatchDraw();
		Sleep(flower_SLEEP);
	}


	closegraph();
}

