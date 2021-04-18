#include "PaperZombie.h"


PaperZombie::PaperZombie(int r)
	:
	AbstractZombie(HP_PAPER_ZOMBIE, r, TIME_GAP_PAPER_ZOMBIE)
{
}

PaperZombie::~PaperZombie() {
}


Attack PaperZombie::AttackEnemy(int time) {
	Attack atk(Attack::PaperZombie_t);
	atk.SetATK(1);
	return atk;
}

void PaperZombie::Isattacked(int hurt) {
	myhp -= hurt;
	if (myhp < (myhpmax / 2))movegap =1;
	if (myhp <= 0)die();
}