#pragma once
#include<string>
#include"Config.h"
#include"Attack.h"
#include"Bullet.h"
using namespace std;

/*
* “物体”虚基类
*  利用多态，一个object pointer可以指向任何植物或者僵尸
*  植物和僵尸的基类AbstractPlant和AbstractZombie继承它
*/

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
	virtual string GetName()const=0;
	//获得当前种类
	int GetType()const { return mytype; }
	//获得当前状态
	int GetStatus()const { return mystatus; }
	//获得当前行列
	RCPair GetRC()const { return RCPair(row, col); }
	//设置行
	void SetRow(int r) { row = r; }
	//设置列
	void SetCol(int c) { col = c; }
	//设置行列
	void SetRC(int r, int c) { row = r; col = c; }
	//获得行
	int GetRow()const { return row; }
	//获得列
	int GetCol()const { return col; }
	int GetHp()const { return myhp; }
	int GetMaxHp()const { return myhpmax; }
	//攻击他人,纯虚函数，不同的植物僵尸需要重新定义！
	virtual Attack AttackEnemy(int time) = 0;
	//virtual void Update();
	//收到攻击减一点血
	virtual void Isattacked(int hurt);
	//死去，改变状态
	void die();
	//设置行和列

	bool operator==(const Object* rhs)const { return (mytype == rhs->mytype && row == rhs->row && col == rhs->col); }

protected:
	//我的生命值
	int myhp;
	int myhpmax;
	//我的种类，上面定义了枚举类型
	Type mytype;
	//我的状态，健康or死亡，最后根据这个进行清除植物和僵尸
	Status mystatus;
	//行，列
	int row, col;
};

