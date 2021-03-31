#pragma once
#include "AbstractPlant.h"
class PeaShooter :
    public AbstractPlant
{
public:
    PeaShooter(int hp,int r,int c);
    ~PeaShooter();
    Attack AttackEnemy();
};

