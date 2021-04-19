#include "CastZombie.h"

CastZombie::CastZombie(int r)
	:
	AbstractZombie(HP_NORMAL_ZOMBIE, r, TIME_GAP_NORMAL_ZOMBIE),
	castgap(TIME_GAP_CAST),
	ball(NUM_OF_BALL)
{
}

CastZombie::~CastZombie() {
}

Attack CastZombie::AttackEnemy(int time) {
	Attack atk(Attack::CastZombie_Cast_t);
	if (ball > 0) {
		if (time % castgap == 0) {
			ball--;
			atk.SetType(Attack::CastZombie_Cast_t);
			atk.SetATK(2);
		}
		else {
			atk.SetType(Attack::None);
		}
	}
	else {
		atk.SetType(Attack::CastZombie_Car_t);
		atk.SetATK(10000);
	}
	return atk;
}