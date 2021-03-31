#pragma once
#include "Object.h"
class AbstractZombie :
    public Object
{
public:
    //构造函数
    AbstractZombie(int hp,int r);
    //析构函数
    ~AbstractZombie();
    void SetSpeed(int sp) { speed = sp; }
    int GetSpeed()const { return speed; }
private:
    int speed;
};

