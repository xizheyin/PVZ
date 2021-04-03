#include "PlantShop.h"
#include<conio.h>


//构造函数
PlantShop::PlantShop() {
	sun = INIT_SUN;
}

//析构函数
PlantShop::~PlantShop() {

}



//安放植物，包括选择地块之类的
bool PlantShop::SettlePlant(Object* obj, ChessBoard* chessbd,int r,int c) {
	return chessbd->AddPlant(static_cast<AbstractPlant*>(obj), r, c);
}

