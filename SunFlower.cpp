#include "SunFlower.h"


SunFlower::SunFlower(int hp, int r , int c) 
	:
	AbstractPlant(hp, r, c)
{
	
}


SunFlower::~SunFlower() {

}




Attack SunFlower::AttackEnemy(int time) {
	return Attack(Attack::None);
}