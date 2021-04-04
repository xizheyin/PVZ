#include "SunFlower.h"


SunFlower::SunFlower(int hp, int r , int c) 
	:
	AbstractPlant(hp, r, c)
{
	
}


SunFlower::~SunFlower() {

}




Attack SunFlower::AttackEnemy(int time) {
	
	if (time % TIME_GAP_CREATESUN==0) {
		Attack atk(Attack::SunFlower);
		atk.SetATK(50);
		return atk;
	}
	return Attack(Attack::None);
}