#include <easyx.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include<vector>

using namespace std;

#define MAXleaf 50	// 枫叶总数
#define SCREEN_W 1000
#define SCREEN_H 500	
#define SOWN_RADIO 3	
#define leaf_SLEEP 20	

struct Leaf
{
	double	x;	
	int		y;
	double	step;	
	
};

Leaf leaf[MAXleaf];
IMAGE img1;
IMAGE img2;
void InitStar(int i)
{
	leaf[i].x = rand() % 1000;
	leaf[i].y = rand() % 50;
	leaf[i].step = (rand() % 5000) / 1000.0 + 1;
}


void MoveStar(int i)
{
	setlinecolor(RGB(0, 0, 0));
	setfillcolor(RGB(0, 0, 0));
	
	putimage((int)leaf[i].x, leaf[i].y, &img2, SRCAND);
	putimage((int)leaf[i].x, leaf[i].y, &img1, SRCPAINT);
	leaf[i].y += leaf[i].step;
	if (leaf[i].y > SCREEN_H)	InitStar(i);

	putimage((int)leaf[i].x, leaf[i].y, &img2, SRCAND);
	putimage((int)leaf[i].x, leaf[i].y, &img1, SRCPAINT);
}


int main()
{
	srand((unsigned)time(NULL));
	initgraph(SCREEN_W, SCREEN_H);
	loadimage(&img1, _T("D:\\1\\1.png"));
	loadimage(&img2, _T("D:\\1\\2.png"));
	for (int i = 0; i < MAXleaf; i++)
	{
		InitStar(i);
		leaf[i].x = rand() % SCREEN_W;
	}


	while (1)
	{
		BeginBatchDraw();
		setbkcolor(RED);//设置背景色为红色
		cleardevice();
		for (int i = 0; i < MAXleaf; i++)
			MoveStar(i);
		EndBatchDraw();
		Sleep(leaf_SLEEP);

	}


	closegraph();
}

