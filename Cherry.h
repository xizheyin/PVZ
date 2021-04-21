#pragma once
#include "AbstractPlant.h"
class Cherry :
    public AbstractPlant
{
public:
    //构造函数
    Cherry(int r = -1, int c = -1);
    //析构函数
    ~Cherry();
    //重定义攻击函数
    Attack AttackEnemy(int time);
    //重定义获取姓名函数
    string GetName()const { if (timeleft > 2) return string("樱桃"); else return string("红樱桃"); }
    void Update() {}
    int GetTimeLeft()const { return timeleft; }
private:
    int timeleft;
};

