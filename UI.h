#pragma once
#include"ChessBoard.h"
#include"PlantShop.h"
#include<conio.h>




class UI
{

public:

	//**************************普通显示UI
	//展示棋盘
	void ShowChessboard(ChessBoard* chessbd);
	//在下面显示一些信息
	void ShowInfo(ChessBoard* chessbd, PlantShop* pshop);


	//**********************shop的UI
	//购买植物的UI
	void BuyPlant(ChessBoard* chessbd, PlantShop* pshop);
	void WrongInput();
	bool Confirm(int n);
	const RCPair SelectArea(ChessBoard* chessbd);
	void PrintSelectBox(int r, int c);
	void ShowShop();


private:


};

