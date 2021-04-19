#pragma once
#include "Bullet.h"

/*攻击类! object的攻击函数返回一个攻击类对象 其中有各种不同的功能*/
class Attack
{
public:
	enum {//攻击类型，到时候control模块根据攻击类型确定具体的攻击
		None,
		PeaShooter_t,
		NormalZombie_t,
		BarricadesZombie_t,
		PaperZombie_t,
		PolesZombie_t,
		SunFlower_t,
		NutWall_t
	};
	//构造函数，参数是攻击类型
	Attack(int _attacktype);
	//拷贝构造函数
	Attack(const Attack& rh);
	//赋值函数
	Attack& operator=(const Attack& rh);
	//获取攻击类型
	int GetAttackType()const { return attacktype; }
	//设置子弹，某个植物有子弹
	void SetBullet(Bullet* _bullet) { bullet = _bullet; }
	//获取子弹，由control模块发出！
	Bullet* GetBullet() { return bullet; }
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