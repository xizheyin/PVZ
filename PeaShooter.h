#pragma once
#include "AbstractPlant.h"
class PeaShooter :
    public AbstractPlant
{
public:
    //构造函数
    PeaShooter(int hp, int r = -1, int c = -1);
    //析构函数
    ~PeaShooter();
    //重定义攻击函数
    Attack AttackEnemy(int time);
    //重定义获取姓名函数
    string GetName()const { return string("豌豆手"); }

    void Update(){}
private:
    int timegap;
};

