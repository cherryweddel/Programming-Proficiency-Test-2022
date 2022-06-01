#include <easyx.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include<vector>

using namespace std;

#define MAXflower 50	// 花总数
#define SCREEN_W 1000
#define SCREEN_H 500	
#define SOWN_RADIO 3	
#define flower_SLEEP 20	

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
	flower[i].y += flower[i].step;
	if (flower[i].y > SCREEN_H)	InitStar(i);


	putimage((int)flower[i].x, flower[i].y, &img2, SRCAND);
	putimage((int)flower[i].x,flower[i].y, &img1, SRCPAINT);
}


int main()
{
	srand((unsigned)time(NULL));
	initgraph(SCREEN_W, SCREEN_H);
	loadimage(&img1, _T("D:\\1\\5.png"));
	loadimage(&img2, _T("D:\\1\\6.png"));

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

