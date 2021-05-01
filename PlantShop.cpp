#include "PlantShop.h"
#include<conio.h>

//构造函数
PlantShop::PlantShop() {
	sun = INIT_SUN;
	for (int i = 0; i < 10; i++) {
		cur_cooling_times.push_back(0);
		cooling_times.push_back(COOLING[i]);
	}
}

//析构函数
PlantShop::~PlantShop() {
}

void PlantShop::SubSun(Type type) {
	switch (type)
	{
	case PeaShooter_t:sun -= PEASHOOTER_COST; break;
	case SunFlower_t:sun -= SUNFLOWER_COST; break;
	case NutWall_t:sun -= NUTWALL_COST; break;
	case DoubleShooter_t:sun -= NUTWALL_COST; break;
	case IceShooter_t:sun -= ICESHOOTER_COST; break;
	case HighNut_t:sun -= HIGHNUT_COST; break;
	case Squash_t:sun -= SQUASH_COST; break;
	case Cherry_t:sun -= CHERRY_COST; break;
	case Garlic_t:sun -= GARLIC_COST; break;
	default:break;
	}
	//把时间设置成冷却时间
	cur_cooling_times[type] = cooling_times[type];
}

bool PlantShop::CheckEnough(Type type) {
	int cost = 0;
	if (cur_cooling_times[type] > 0)return false;
	switch (type) {
	case SunFlower_t:cost = SUNFLOWER_COST; break;
	case PeaShooter_t:cost = PEASHOOTER_COST; break;
	case NutWall_t:cost = NUTWALL_COST; break;
	case DoubleShooter_t:cost = DOUBLESHOOTER_COST; break;
	case IceShooter_t:cost = ICESHOOTER_COST; break;
	case HighNut_t:cost = HIGHNUT_COST; break;
	case Squash_t:cost = SQUASH_COST; break;
	case Cherry_t:cost = CHERRY_COST; break;
	case Garlic_t:cost = GARLIC_COST; break;
	case Pumpkin_t:cost = PUMPKIN_COST; break;
	default:break;
	}
	if ((sun - cost) >= 0)return true;
	else return false;
}

//安放植物，包括选择地块之类的
bool PlantShop::SettlePlant(Object* obj, ChessBoard* chessbd,int r,int c) {
	return chessbd->AddPlant(static_cast<AbstractPlant*>(obj), r, c);
}



void PlantShop::UpdateTime() {
	if (time(NULL) - curtime >= 1) {
		for (int i = 0; i < 10;i++) {
			if (cur_cooling_times[i] > 0)
				cur_cooling_times[i]--;
		}
	}
	curtime = time(NULL);
}


vector<int> PlantShop::GetCoolingTime()const {
	return cur_cooling_times;
}