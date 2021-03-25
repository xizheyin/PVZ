#include "MainWindow.h"
#include"Config.h"
#include<iostream>
using namespace std;

MainWindow::MainWindow():gamewindow(new GameWindow()),optionwindow(new OptionWindow()) {
	
}
MainWindow::~MainWindow() {
	delete gamewindow;
	delete optionwindow;
}

void MainWindow::show() {
	system("cls");
	cout << "***********************************************" << endl;
	cout << "+   Welcome To My PLANTS And ZOMBIES World!   +" << endl;
	cout << "***********************************************" << endl;
	cout << "请你选择：   1.进入游戏    2.帮助    3.退出游戏" << endl;
	int n;
	
	while (cin >> n) {
		switch (n) {
		case 1:
			gamewindow -> Show();
			break;
		case 2:

			break;
		case 3:
			exitMainWindow();
			break;
		default:
			set_std_color(FOREGROUND_RED);
			cout << "您输入了错误数字，请重新输入" << endl;
			reset_std_color();
			Sleep(600);
			show();
			break;
		}
	}
}


void MainWindow::exitMainWindow() {
	system("cls");
	cout << "***********************************************" << endl;
	cout << "+           感谢你的使用，下次再见!           +" << endl;
	cout << "***********************************************" << endl;
	cout << endl << endl;
	set_std_color(FOREGROUND_RED|FOREGROUND_GREEN);
	cout << "Game Designed by YXZ from NJUCS19" << endl;
	reset_std_color();
	Sleep(2000);
	exit(1);
}