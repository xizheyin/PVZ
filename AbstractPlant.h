#pragma once
#include"Object.h"


//继承物体类，里面存放了有关植物共性的属性



class AbstractPlant
	:public Object
{
public:
	AbstractPlant(int hp,int r,int c);//不存在默认构造函数
	~AbstractPlant();

private:
};

