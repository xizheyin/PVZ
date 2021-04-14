#pragma once
#include"AbstractPlant.h"


class NutWall
	:public AbstractPlant
{
public:
	//构造函数
	NutWall(int r = -1, int c = -1);
	//析构函数
	~NutWall();
	//重定义攻击函数
	Attack AttackEnemy(int time);
	//重定义名称函数
	string GetName()const { return string("坚果墙"); }

	void Update() { }
};

