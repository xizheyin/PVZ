#include "AbstractPlant.h"

//构造函数
AbstractPlant::AbstractPlant(int pt,int hp,int r,int c)
	:
	Object(0,hp,r,c)//调用基类构造函数！ 
{
	planttype = pt;
	mytype = Object::Plant_t;//设置我的类型是植物
}
//析构函数
AbstractPlant::~AbstractPlant() {
}