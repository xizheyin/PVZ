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

	case PlantShop::PeaShooter_t:
		sun -= 100;
		break;
	case PlantShop::SunFlower_t:
		sun -= 75;
		break;
	default:
		break;
	}
}


bool PlantShop::CheckEnough(Type type) {
	int cost = 0;
	switch (type) {
	case PeaShooter_t:
		cost = 100;
		break;
	case SunFlower_t:
		cost = 75;
		break;
	default:
		break;
	}
	if (sun - cost >= 0)return true;
	else false;
}



//安放植物，包括选择地块之类的
bool PlantShop::SettlePlant(Object* obj, ChessBoard* chessbd,int r,int c) {
	return chessbd->AddPlant(static_cast<AbstractPlant*>(obj), r, c);
}

