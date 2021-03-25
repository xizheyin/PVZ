#pragma once
#include<string>
using namespace std;

class Object
{
public:
	//状态，健康和死亡，每次更新时候棋盘会检查状态，如果死亡就移除掉它
	enum Status { Healthy, Dead };
	//Object的种类，包括植物和僵尸
	enum Type { Plant, Zombies, Pea, Flower };

	//构造函数，种类为参数
	Object(int ty,int Hp);
	//析构函数
	~Object();
	//根据种类来获得名字，以便输出
	virtual string GetName()const;
	//获得当前种类
	int GetType()const;
	//获得当前状态
	int GetStatus()const;
	//攻击他人
	virtual void Attack() = 0;
	//收到攻击减一点血
	void Isattacked();
	//死去，改变状态
	void die();
private:
	int myhp;
	Type mytype;
	Status mystatus;
};

