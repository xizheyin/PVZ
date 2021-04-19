#pragma once
#include "AbstractZombie.h"
class CastZombie :
    public AbstractZombie
{
public:
    //构造函数
    CastZombie(int r);
    //析构函数
    ~CastZombie();
    //重定义攻击函数
    Attack AttackEnemy(int time);
    //重定义名称函数
    string GetName()const { return string("投篮"); }

    void Update() { }
private:
    int ball;
    int castgap;
};

