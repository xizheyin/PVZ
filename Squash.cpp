#include "Squash.h"

//构造函数
Squash::Squash(int r, int c)
	:
	AbstractPlant(HP_SQUASH, r, c)//类型是植物
{
}

//析构函数
Squash::~Squash() {

}

//豌豆射手的攻击函数
//设置一个ATK为1的子弹！
Attack Squash::AttackEnemy(int time) {
	Attack atk(Attack::Squash_t);
	atk.SetATK(10000);
	return atk;
}
