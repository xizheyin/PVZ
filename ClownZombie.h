#pragma once
#include "AbstractZombie.h"
class ClownZombie :
    public AbstractZombie
{
public:
    //构造函数
    ClownZombie(int r);
    //析构函数
    ~ClownZombie();
    //重定义攻击函数
    Attack AttackEnemy(int time);
    //重定义名称函数
    string GetName()const { return string("小丑"); }

    void Update() { }
private:
};

