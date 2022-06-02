#include <iostream>
#include<graphics.h>
#include<conio.h>
#include <cstring>
#define PI 3.14
using namespace std;

void setBack(LPCTSTR address)
{
	IMAGE img;
	loadimage(&img ,address, 1080, 708);
	putimage(0, 0, &img);
}

void drawLogo()
{
	setfillcolor(YELLOW);
	fillcircle(1030, 658, 30);
	const POINT pts[] = { {1030, 628}, {1000, 658}, {1060, 658} };

	int c;
	double a;
	int x, y, rr = 30;
	for (a = 0; a < PI * 2+1.5; a += 0.001)
	{
		x = (int)(rr * cos(a) + 1030 + 0.5);
		y = (int)(rr * sin(a) + 658 + 0.5);
		c = (int)(a * 255 / PI + 0.5);
		setcolor(RGB(c, c, 0));
		line(1030, 658, x, y);
	}

	setlinestyle(0, 5);
	setlinecolor(GREEN);
	polygon(pts, 3);

	RECT r = { 1000, 660, 1060, 708 };
	setbkmode(1);
	settextcolor(WHITE);
	drawtext("NJTech",&r, DT_CENTER);
}

int main()
{
	initgraph(1080, 708);
	setBack("Spring.jpeg");
	drawLogo();
	system("pause");
	setBack("Summer.jpg");
	drawLogo();
	system("pause");
	setBack("Autumn.png");
	drawLogo();
	system("pause");
	setBack("Winter.jpg");
	drawLogo();
	system("pause");
	closegraph();
	return 0;
}