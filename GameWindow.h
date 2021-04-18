#pragma once
#include"ChessBoard.h"
#include"GameControl.h"
#include"PlantShop.h"
#include"UI.h"
#include<Windows.h>
#include<iostream>

using namespace std;
class GameWindow
{
public:
	//构造函数
	GameWindow();
	//析构函数
	~GameWindow();
	//游戏函数，通过一个循环，每次更新棋盘和刷新屏幕
	void Play();
	//更新函数，利用gamectrl来控制chessbd
	void Update();
	//刷新屏幕
	void Show();
	void Pause();
	void GameOver();
	void PlayMusic();
private:
	GameControl* gamectrl;
	ChessBoard* chessbd;
	PlantShop* pshop;
	UI* ui;
};