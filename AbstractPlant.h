#pragma once
#include"Object.h"

//继承物体类，里面存放了有关植物共性的属性
class AbstractPlant
	:public Object
{
public:
    enum {
        PeaShooter_t,
        SunFlower_t,
        NutWall_t,
        HighNut_t,
        DoubleShooter_t,
        IceShooter_t,
        Squash_t,
        Cherry_t,
        Garlic_t,
        Pumpkin_t
    };

    AbstractPlant(int pt, int hp, int r, int c);//不存在默认构造函数
	~AbstractPlant();

    int GetPlantType()const { return planttype; }
protected:
    int planttype;
};

