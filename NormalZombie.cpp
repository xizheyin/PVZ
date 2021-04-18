#include "NormalZombie.h"


NormalZombie::NormalZombie(int r)
	:
	AbstractZombie(HP_NORMAL_ZOMBIE,r,TIME_GAP_NORMAL_ZOMBIE)
{	
}

NormalZombie::~NormalZombie() {
}


Attack NormalZombie::AttackEnemy(int time) {
	Attack atk(Attack::BarricadesZombie_t);
	atk.SetATK(1);
	return atk;
}