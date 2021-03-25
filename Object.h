#pragma once
#include<string>
using namespace std;

class Object
{
public:
	Object(int type=0);
	~Object();
	enum Status
	{
		Healthy,
		Dead
	};
	enum Type {
		Plant,
		Zombies,
		Pea,
		Flower
	};
	string GetName()const;
	int GetType()const;
	int GetStatus()const;
	virtual void Attack();
	virtual void Isattacked();
	void die();
private:
	int hp;
	Type mytype;
	Status mystatus;
};

