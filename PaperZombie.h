#pragma once
#include "AbstractZombie.h"
class PaperZombie :
    public AbstractZombie
{
public:
    //构造函数
    PaperZombie(int r);
    //析构函数
    ~PaperZombie();
    //重定义攻击函数
    Attack AttackEnemy(int time);
    //重定义名称函数
    string GetName()const { return string("读报"); }

    void Isattacked(int hurt);
    void Update() { }
private:
};

