#include "ClownZombie.h"

ClownZombie::ClownZombie(int r)
	:
	AbstractZombie(HP_CLOWN_ZOMBIE, r, TIME_GAP_CLOWN_ZOMBIE)
{
}

ClownZombie::~ClownZombie() {
}

Attack ClownZombie::AttackEnemy(int time) {
	Attack atk(Attack::ClownZombie_t);
	atk.SetATK(10000);
	return atk;
}
