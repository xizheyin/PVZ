#include "AbstractZombie.h"


AbstractZombie::AbstractZombie(int hp, int r)
	:
	Object(hp, hp, r, COL_NUM-2 )
{
	mytype = Object::Zombie_t;
}

AbstractZombie::~AbstractZombie() {

}