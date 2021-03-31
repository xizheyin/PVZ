#pragma once
#include "AbstractZombie.h"
class NormalZombie :
    public AbstractZombie
{
public:
    NormalZombie(int hp,int r);
    ~NormalZombie();
    Attack AttackEnemy();
private:
};

