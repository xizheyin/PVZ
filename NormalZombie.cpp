#include "NormalZombie.h"


NormalZombie::NormalZombie(int hp,int r)
	:
	AbstractZombie(hp,r)
{
	SetSpeed(1);
}
NormalZombie::~NormalZombie() {

}


Attack NormalZombie::AttackEnemy(int time) {
	Attack atk(Attack::Zombie);
	atk.SetATK(1);
	return atk;
}