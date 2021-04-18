#include "BarricadesZombie.h"

BarricadesZombie::BarricadesZombie(int r)
	:
	AbstractZombie(HP_BARRICADES_ZOMBIE, r, TIME_GAP_BARRICADES_ZOMBIE)
{
}

BarricadesZombie::~BarricadesZombie() {

}

Attack BarricadesZombie::AttackEnemy(int time) {
	Attack atk(Attack::BarricadesZombie_t);
	atk.SetATK(1);
	return atk;
}