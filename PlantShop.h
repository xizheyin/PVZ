#pragma once
#include"PeaShooter.h"
#include"SunFlower.h"
#include"NutWall.h"
#include"DoubleShooter.h"
#include"IceShooter.h"
#include"HighNut.h"
#include"Squash.h"
#include"Cherry.h"
#include"Garlic.h"
#include"Pumpkin.h"
#include"ChessBoard.h"
#include<time.h>

class PlantShop
{
public:
	enum Type {
		SunFlower_t,
		PeaShooter_t,
		NutWall_t,
		DoubleShooter_t,
		IceShooter_t,
		HighNut_t,
		Squash_t,
		Cherry_t,
		Garlic_t,
		Pumpkin_t
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
	void UpdateTime();
	vector<int> GetCoolingTime()const;
private:
	int sun;
	time_t curtime;
	vector<int> cooling_times;
	vector<int> cur_cooling_times;
};

