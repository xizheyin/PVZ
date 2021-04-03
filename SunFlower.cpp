#include "SunFlower.h"


SunFlower::SunFlower(int hp, int r , int c) 
	:
	AbstractPlant(hp, r, c)
{
	
}


SunFlower::~SunFlower() {

}




Attack SunFlower::AttackEnemy(int time) {
	
	if (time % TIME_GAP_CREATESUN) {
		Attack atk(Attack::SunFlower);
		atk.SetATK(1);
	}
	return Attack(Attack::None);
}