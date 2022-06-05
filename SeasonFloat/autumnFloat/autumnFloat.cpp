#include <easyx.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include<vector>

using namespace std;


const int MAXleaf = 40;	// 枫叶总数
const int SCREEN_W = 1000;
const int SCREEN_H = 500;



struct Leaf
{
	int x;	
	double	y;
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
	
	putimage(leaf[i].x, leaf[i].y, &img2, SRCAND);
	putimage(leaf[i].x, leaf[i].y, &img1, SRCPAINT);
	leaf[i].y += leaf[i].step;  //控制速度
	if (leaf[i].y > SCREEN_H)
	{
		InitStar(i);

	}
	putimage(leaf[i].x, leaf[i].y, &img2, SRCAND);
	putimage(leaf[i].x, leaf[i].y, &img1, SRCPAINT);
}

void draw()
{
	loadimage(&img1, _T("./1.png"));
	loadimage(&img2, _T("./2.png"));
	static bool Flg = true;
	if (Flg)
	{
		for (int i = 0; i < MAXleaf; i++)
			InitStar(i);
		Flg = false;
	}
	
	static int cnt = 0;cnt++;
	
	while (cnt ==70)
	{
		BeginBatchDraw();
		setbkcolor(RED);//设置背景色为红色
		cleardevice();
		for (int i = 0; i < MAXleaf;i++)
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

