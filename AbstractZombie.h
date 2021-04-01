#pragma once
#include "Object.h"
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

