#pragma once
#include "Object.h"

//存放了有关僵尸的共性属性
class AbstractZombie 
    :public Object
{
public:

    //构造函数
    AbstractZombie(int hp,int r,int gap);
    //析构函数
    ~AbstractZombie();
    bool CanMove(unsigned timercount)const { return (timercount % movegap == 0); }
    void SpeedDown() { if (!speeddown) { movegap *= 2; speeddown = true; } }
protected:
    //僵尸移动的速度(时间间隔)
    int movegap;
    bool speeddown;
};

