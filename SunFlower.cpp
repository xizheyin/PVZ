#include "SunFlower.h"


SunFlower::SunFlower(int hp, int r , int c) 
	:
	AbstractPlant(hp, r, c)
{
	
}


SunFlower::~SunFlower() {

}




Attack SunFlower::AttackEnemy() {
	return Attack(Attack::None);
}