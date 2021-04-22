#include "Garlic.h"


Garlic::Garlic(int r, int c)
	:
	AbstractPlant(Garlic_t,HP_GARLIC, r, c)
{
}

Garlic::~Garlic() {

}

Attack Garlic::AttackEnemy(int time) {
	return Attack(Attack::None);
}