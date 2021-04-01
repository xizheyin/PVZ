#include "MainWindow.h"
#include"Config.h"
#include<iostream>
using namespace std;


//构造函数
MainWindow::MainWindow():gamewindow(new GameWindow()),optionwindow(new OptionWindow()) {
	
}

//析构函数
MainWindow::~MainWindow() {
	delete gamewindow;//析构创建的gamewindow对象
	delete optionwindow;//析构创建的optionwindow对象
}

//主窗口控制台
void MainWindow::show() {
	system("cls");
	ShowWindowHead();
	int n;
	while (cin >> n) {
		switch (n) {
		case 1://游戏窗口
			gamewindow -> Play();break;
		case 2://还没想好？
			break;
		case 3://退出窗口
			exitMainWindow();break;
		default://错误输入
			WrongInput();break;
		}
	}
}

//播放音乐！结尾彩蛋哦
void MainWindow::PlayMusic() {
	::PlaySound(TEXT("PVZ.wav"), NULL, SND_LOOP);
}


//退出窗口
void MainWindow::exitMainWindow() {
	system("cls");
	cout << "***********************************************" << endl;
	cout << "+           感谢你的使用，下次再见!           +" << endl;
	cout << "***********************************************" << endl;
	cout << endl << endl;
	set_std_color(FOREGROUND_RED|FOREGROUND_GREEN);
	cout << "Game Designed by YXZ from NJUCS19" << endl;
	reset_std_color();
	PlayMusic();
	Sleep(60000);
	exit(1);
}

//展示开头
void MainWindow::ShowWindowHead() {
	cout << "***********************************************" << endl;
	cout << "+   Welcome To My PLANTS And ZOMBIES World!   +" << endl;
	cout << "***********************************************" << endl;
	cout << "请你选择：   1.进入游戏    2.帮助    3.退出游戏" << endl;
}


//输错数字的后果，显示错误信息，然后重新显示
void MainWindow::WrongInput() {
	set_std_color(FOREGROUND_RED);
	cout << "您输入了错误数字，请重新输入" << endl;
	reset_std_color();
	Sleep(600);
	show();
}