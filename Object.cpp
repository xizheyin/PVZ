#include "Object.h"



Object::Object(int type) {
	mytype = static_cast<Type>(type);
	mystatus = Healthy;
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
	hp--;
	if (hp == 0)die();
}

void Object::die() {
	mystatus = Dead;
}