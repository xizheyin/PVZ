#pragma once
#include"PeaShooter.h"
#include"SunFlower.h"
#include"ChessBoard.h"

class Shop
{
public:
	Shop();
	~Shop();
	//通过商店类控制棋盘植物放置
	void BuyPlant(ChessBoard* chessbd);
private:
	void Show();
	void WrongInput();
	bool Confirm(int n);
	void SettlePlant(Object* obj, ChessBoard* chessbd);

	void PrintSelectBox(int r,int c);

	//返回一个（row,col）二元组，表示存放的位置
	const RCPair SelectArea(ChessBoard* chessbd);
};

