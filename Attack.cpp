#include "Attack.h"



Attack::Attack(int _attacktype)
	:
	attacktype(_attacktype)
{

}


Attack::Attack(const Attack& rh)
	:
	attacktype ( rh.attacktype),
	bullet ( rh.bullet),
	ATK (rh.ATK)
{

}


Attack& Attack::operator=(const Attack& rh) {
	attacktype = rh.attacktype;
	bullet = rh.bullet;
	ATK = rh.ATK;
	return *this;
}