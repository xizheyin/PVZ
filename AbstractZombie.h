#pragma once
#include "Object.h"


//存放了有关僵尸的共性属性

class AbstractZombie :
    public Object
{
public:
    //构造函数
    AbstractZombie(int hp,int r);
    //析构函数
    ~AbstractZombie();
    //设置速度值
    void SetSpeed(int sp) { speed = sp; }
    //获取速度值
    int GetSpeed()const { return speed; }

private:
    //僵尸移动的速度
    int speed;
};

