#include "HighNut.h"


HighNut::HighNut(int r, int c)
	:
	AbstractPlant(HP_HIGHNUT, r, c)
{
}

HighNut::~HighNut() {

}

Attack HighNut::AttackEnemy(int time) {
	return Attack(Attack::HighNut_t);
}