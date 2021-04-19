#pragma once
#include "AbstractZombie.h"
class PolesZombie :
    public AbstractZombie
{
public:
    //构造函数
    PolesZombie(int r);
    //析构函数
    ~PolesZombie();
    //重定义攻击函数
    Attack AttackEnemy(int time);
    //重定义名称函数
    string GetName()const { return string("撑杆"); }
    void Update() { }
    bool IsInit()const { return init; }
    void ChangeInit() { init = false; }
private:
    bool init;
};

