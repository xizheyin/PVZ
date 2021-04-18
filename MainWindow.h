#pragma once
#include <cstdlib>
#include <windows.h>
#include"GameWindow.h"
#include"OptionWindow.h"
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

class MainWindow
{
public:
	//构造函数，初始化两个窗口类
	MainWindow();
	//析构函数
	~MainWindow();
	//主窗口显示
	void show();
private:
	void PlayMusic();
	//把窗口主体展示
	void ShowWindowHead();
	//选3，退出窗口
	void exitMainWindow();
	//输错了数字
	void WrongInput();
	//game窗口指针，减小依赖性
	GameWindow* gamewindow;
	//option窗口指针
	OptionWindow* optionwindow;
};

