#include "Object.h"


Object::Object(int ty, int Hp,int r,int c) {
	mytype = (Type)ty;
	myhp = Hp;
	row = r;
	col = c;
}

Object::~Object() {

}

string Object::GetName()const {
	switch (mytype)
	{
	case Plant_t:return string("Plant"); break;
	case Zombie_t:return string("Zombie"); break;
	default:
		break;
	}
}

int Object::GetType()const {
	return mytype;
}

int Object::GetStatus()const {
	return mystatus;
}


void Object::Isattacked(int hurt) {
	myhp -= hurt;
	if (myhp <= 0)die();
}

void Object::die() {
	mystatus = Dead;
}