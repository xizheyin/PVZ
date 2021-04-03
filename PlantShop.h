#pragma once
#include"PeaShooter.h"
#include"SunFlower.h"
#include"ChessBoard.h"


class PlantShop
{
public:
	PlantShop();
	~PlantShop();
	
	//添加阳光
	void AddSun(int x) { sun += x; }
	//获取阳光
	int GetSun()const { return sun; }

	bool SettlePlant(Object* obj, ChessBoard* chessbd, int r, int c);




private:

	int sun;

};

