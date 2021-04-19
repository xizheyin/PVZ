#include "Object.h"

//构造函数
Object::Object(int ty, int Hp,int r,int c) {
	mytype = (Type)ty;
	mystatus = (Status)Healthy;
	myhp = Hp;
	row = r;
	col = c;
	myhpmax = Hp;
}

//析构函数
Object::~Object() {

}

//获得名字，方便输出
string Object::GetName()const {
	return string("Plant");
}

//受到攻击
void Object::Isattacked(int hurt) {
	myhp -= hurt;
	if (myhp <= 0)die();
}

//设置死亡状态
void Object::die() {
	mystatus = Dead;
}