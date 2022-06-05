#include <easyx.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include<vector>

using namespace std;

const int MAXflower = 50;  //数量
const int SCREEN_W = 1000;
const int SCREEN_H = 500;

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

void draw()
{
	loadimage(&img1, _T("./5.png"));
	loadimage(&img2, _T("./6.png"));
	static bool Flg = true;
	if (Flg)
	{
		for (int i = 0; i < MAXflower; i++)
			InitStar(i);
		Flg = false;
	}
	static int cnt = 0;cnt++;
	while(cnt ==70)
	{
		BeginBatchDraw();
		setbkcolor(RED);//设置背景色为红色
		cleardevice();
		for (int i = 0; i < MAXflower;i++)
			MoveStar(i);
		cnt = 0;
		EndBatchDraw();
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

