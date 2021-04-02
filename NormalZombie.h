#pragma once
#include "AbstractZombie.h"
class NormalZombie :
    public AbstractZombie
{
public:
    //构造函数
    NormalZombie(int hp,int r);
    //析构函数
    ~NormalZombie();
    //重定义攻击函数
    Attack AttackEnemy();
    //重定义名称函数
    string GetName()const { return string("NorZombie"); }
private:
};

