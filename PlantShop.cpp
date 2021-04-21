#include "PlantShop.h"
#include<conio.h>

//构造函数
PlantShop::PlantShop() {
	sun = INIT_SUN;
}

//析构函数
PlantShop::~PlantShop() {

}

void PlantShop::SubSun(Type type) {
	switch (type)
	{

	case PeaShooter_t:
		sun -= PEASHOOTER_COST;
		break;
	case SunFlower_t:
		sun -= SUNFLOWER_COST;
		break;
	case NutWall_t:
		sun -= NUTWALL_COST;
		break;
	case DoubleShooter_t:
		sun -= NUTWALL_COST;
		break;
	case IceShooter_t:
		sun -= ICESHOOTER_COST;
		break;
	case HighNut_t:
		sun -= HIGHNUT_COST;
		break;
	case Squash_t:
		sun -= SQUASH_COST;
		break;
	case Cherry_t:
		sun -= CHERRY_COST;
		break;
	default:
		break;
	}
}

bool PlantShop::CheckEnough(Type type) {
	int cost = 0;
	switch (type) {
	case PeaShooter_t:
		cost = PEASHOOTER_COST;
		break;
	case SunFlower_t:
		cost = SUNFLOWER_COST;
		break;
	case NutWall_t:
		cost = NUTWALL_COST;
		break;
	case DoubleShooter_t:
		cost = DOUBLESHOOTER_COST;
		break;
	case IceShooter_t:
		cost = ICESHOOTER_COST;
		break;
	case HighNut_t:
		cost = HIGHNUT_COST;
		break;
	case Squash_t:
		cost = SQUASH_COST;
		break;
	case Cherry_t:
		cost = CHERRY_COST;
		break;
	default:
		break;
	}
	if ((sun - cost) >= 0)return true;
	else return false;
}

//安放植物，包括选择地块之类的
bool PlantShop::SettlePlant(Object* obj, ChessBoard* chessbd,int r,int c) {
	return chessbd->AddPlant(static_cast<AbstractPlant*>(obj), r, c);
}

