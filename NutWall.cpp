#include "NutWall.h"




NutWall::NutWall(int r, int c)
	:
	AbstractPlant(80, r, c)
{

}


NutWall::~NutWall() {

}




Attack NutWall::AttackEnemy(int time) {
	/*
	if (time % TIME_GAP_CREATESUN == 0) {
		Attack atk(Attack::SunFlower);
		atk.SetATK(50);
		return atk;
	}*/
	
	return Attack(Attack::NutWall);
}