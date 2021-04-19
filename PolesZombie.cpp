#include "PolesZombie.h"

PolesZombie::PolesZombie(int r)
	:
	AbstractZombie(HP_POLES_ZOMBIE, r, TIME_GAP_POLES_ZOMBIE)
{
	init = true;
}

PolesZombie::~PolesZombie() {
}

Attack PolesZombie::AttackEnemy(int time) {
	Attack atk(Attack::PolesZombie_t);
	atk.SetATK(1);
	return atk;
}