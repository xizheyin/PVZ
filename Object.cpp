#include "Object.h"


Object::Object(int ty, int Hp) {
	mytype = (Type)ty;
	myhp = Hp;
}

Object::~Object() {

}

string Object::GetName()const {
	switch (mytype)
	{
	case Plant:return string("Plant"); break;
	case Zombies:return string("Zombies"); break;
	case Pea:return string("Pea"); break;
	case Flower:return string("Flower"); break;
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

void Object::Attack() {

}

void Object::Isattacked() {
	myhp--;
	if (myhp <= 0)die();
}

void Object::die() {
	mystatus = Dead;
}