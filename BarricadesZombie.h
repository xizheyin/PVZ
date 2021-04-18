#pragma once
#include "AbstractZombie.h"
class BarricadesZombie 
    :public AbstractZombie
{

public:
    //构造函数
    BarricadesZombie(int r);
    //析构函数
    ~BarricadesZombie();
    //重定义攻击函数
    Attack AttackEnemy(int time);
    //重定义名称函数
    string GetName()const { return string("路障"); }
    void Update() { }
private:

};

