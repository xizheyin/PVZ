#include "Pumpkin.h"




Pumpkin::Pumpkin(int r, int c)
	:
	AbstractPlant(Pumpkin_t, HP_PUMPKIN, r, c)
{
}

Pumpkin::~Pumpkin() {

}

Attack Pumpkin::AttackEnemy(int time) {
	return Attack(Attack::None);
}