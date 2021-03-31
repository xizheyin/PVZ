#pragma once
#include<string>
#include"Config.h"
#include"Attack.h"
#include"Bullet.h"
using namespace std;

class Object
{
public:
	//状态，健康和死亡，每次更新时候棋盘会检查状态，如果死亡就移除掉它
	enum Status { Healthy, Dead };
	//Object的种类，包括植物和僵尸
	enum Type { Plant_t, Zombie_t,Bullet_t };

	//构造函数，种类为参数
	Object(int ty,int Hp,int r,int c);
	//析构函数
	~Object();
	//根据种类来获得名字，以便输出
	virtual string GetName()const;
	//获得当前种类
	int GetType()const;
	//获得当前状态
	int GetStatus()const;
	//获得当前行列
	RCPair GetRC()const { return RCPair(row, col); }
	//攻击他人
	virtual Attack AttackEnemy() = 0;
	//收到攻击减一点血
	void Isattacked(int hurt);
	//死去，改变状态
	void die();
	void SetRC(int r,int c) { row = r; col = c; }
protected:
	int myhp;
	Type mytype;
	Status mystatus;
	int row, col;
};

