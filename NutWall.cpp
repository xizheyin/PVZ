#include "NutWall.h"

NutWall::NutWall(int r, int c)
	:
	AbstractPlant(80, r, c)
{
}

NutWall::~NutWall() {

}

Attack NutWall::AttackEnemy(int time) {	
	return Attack(Attack::NutWall_t);
}