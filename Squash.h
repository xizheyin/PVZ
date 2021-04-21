#pragma once
#include "AbstractPlant.h"
class Squash :
    public AbstractPlant
{
public:
    //构造函数
    Squash(int r = -1, int c = -1);
    //析构函数
    ~Squash();
    //重定义攻击函数
    Attack AttackEnemy(int time);
    //重定义获取姓名函数
    string GetName()const { return string("倭瓜"); }
    void Update() {}
private:
    
};

