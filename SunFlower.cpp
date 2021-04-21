#include "SunFlower.h"

SunFlower::SunFlower(int r , int c) 
	:
	AbstractPlant(HP_SUNFLOWER, r, c)
{
}

SunFlower::~SunFlower() {
}

Attack SunFlower::AttackEnemy(int time) {
	
	if (time % TIME_GAP_CREATESUN==0) {
		Attack atk(Attack::SunFlower_t);
		atk.SetATK(50);
		return atk;
	}
	return Attack(Attack::None);
}