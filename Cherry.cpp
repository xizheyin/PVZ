#include "Cherry.h"


//构造函数
Cherry::Cherry(int r, int c)
	:
	AbstractPlant(Cherry_t,HP_SQUASH, r, c)//类型是植物
{
	timeleft = 10;
	
}

//析构函数
Cherry::~Cherry() {

}

//豌豆射手的攻击函数
//设置一个ATK为1的子弹！
Attack Cherry::AttackEnemy(int time) {
	timeleft--;
	Attack atk(Attack::Cherry_t);
	if (timeleft <= 0) {
		atk.SetATK(10000);
	}
	else {
		atk.SetType(Attack::None);
	}
	return atk;
}