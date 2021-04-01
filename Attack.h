#pragma once
#include "Bullet.h"



/*
* 攻击类!
* object的攻击函数返回一个攻击类对象
* 其中有各种不同的功能
*/



class Attack
{
public:
	enum {
		Plant,
		Zombie,
		PeaShooter,
		NormalZombie
	};

	Attack(int _attacktype) { attacktype = _attacktype; }
	Attack(const Attack& rh) {
		attacktype = rh.attacktype;
		bullet = rh.bullet;
	}
	Attack& operator=(const Attack& rh) {
		attacktype = rh.attacktype;
		bullet = rh.bullet;
	}
	//设置子弹，某个植物有子弹
	void SetBullet(Bullet* _bullet) { bullet = _bullet; }
	//获取子弹，由control模块发出！
	Bullet* GetBullet() { return bullet; }
	//获取攻击类型
	int GetAttackType()const { return attacktype; }
	//设置攻击值
	void SetATK(int atk) { ATK = atk; }
	//获得攻击值
	int GetATK()const { return ATK; }

private:
	//攻击类型
	int attacktype;
	//攻击值
	int ATK;
	//子弹
	Bullet* bullet;
};

