#pragma once
#include"Object.h"

class AbstractPlant:public Object
{
public:
	AbstractPlant(int x, int y, int Hp);//不存在默认构造函数
	~AbstractPlant();

	virtual void show()const = 0;
	virtual void die() = 0;

private:
	int Hp;
	int x, y;
};

