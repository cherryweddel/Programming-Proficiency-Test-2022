#include<Windows.h>
#include <Mmsystem.h>
#include <iostream>
#pragma comment(lib,"winmm.lib")//播放音乐的库文件
using namespace std;

int main()
{
	void playsprmusic();//春天bgm
	{
		mciSendString(TEXT("open spring.mp3 alias spr"), 0, 0, 0);//打开音乐文件
		mciSendString(TEXT("play spr repeat"), 0, 0, 0);//播放音乐
		/*
		程序
		*/
		mciSendString(TEXT("stop spr repeat"), 0, 0, 0);//停止音乐
		mciSendString(TEXT("close spr"), 0, 0, 0);//关闭音乐文件
	}

	void playsummusic();//夏天bgm
	{
		mciSendString(TEXT("open summer.mp3 alias sum"), 0, 0, 0);//打开音乐文件
		mciSendString(TEXT("play sum repeat"), 0, 0, 0);//播放音乐
		/*
		程序
		*/
		mciSendString(TEXT("stop sum repeat"), 0, 0, 0);//停止音乐
		mciSendString(TEXT("close sum"), 0, 0, 0);//关闭音乐文件
	}
	
	void playautmusic();//秋天bgm
	{
		mciSendString(TEXT("open autumn.mp3 alias aut"), 0, 0, 0);//打开音乐文件
		mciSendString(TEXT("play aut repeat"), 0, 0, 0);//播放音乐
		/*
		程序
		*/
		mciSendString(TEXT("stop aut repeat"), 0, 0, 0);//停止音乐
		mciSendString(TEXT("close aut"), 0, 0, 0);//关闭音乐文件
	}
	
	void playwinmusic();//冬天bgm
	{
		mciSendString(TEXT("open winter.mp3 alias win"), 0, 0, 0);//打开音乐文件
		mciSendString(TEXT("play win repeat"), 0, 0, 0);//播放音乐
		/*
		程序
		*/
		mciSendString(TEXT("stop winter repeat"), 0, 0, 0);//停止音乐
		mciSendString(TEXT("close win"), 0, 0, 0);//关闭音乐文件
	}
	
		return 0;
}
