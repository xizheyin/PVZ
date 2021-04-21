#pragma once
#include "AbstractPlant.h"
class HighNut :
    public AbstractPlant
{

public:
	//构造函数
	HighNut(int r = -1, int c = -1);
	//析构函数
	~HighNut();
	//重定义攻击函数
	Attack AttackEnemy(int time);
	//重定义名称函数
	string GetName()const { return string("高坚果"); }
	void Update() { }
};

