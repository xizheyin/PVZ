#pragma once
#include"PeaShooter.h"
#include"SunFlower.h"
#include"NutWall.h"
#include"DoubleShooter.h"
#include"IceShooter.h"
#include"HighNut.h"
#include"Squash.h"
#include"Cherry.h"
#include"ChessBoard.h"

class PlantShop
{
public:
	enum Type {
		None_t,
		Plant_t,
		PeaShooter_t,
		NormalZombie_t,
		SunFlower_t,
		NutWall_t,
		HighNut_t,
		DoubleShooter_t,
		IceShooter_t,
		Squash_t,
		Cherry_t
	};
	PlantShop();
	~PlantShop();
	//添加阳光
	void AddSun(int x) { sun += x; }
	//获取阳光
	int GetSun()const { return sun; }
	void SubSun(Type type);
	bool CheckEnough(Type type);
	bool SettlePlant(Object* obj, ChessBoard* chessbd, int r, int c);
private:
	int sun;
};

