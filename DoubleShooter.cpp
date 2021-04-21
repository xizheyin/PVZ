#include "DoubleShooter.h"


//构造函数
DoubleShooter::DoubleShooter(int r, int c)
	:
	AbstractPlant(HP_DOUBLESHOOTER, r, c),//类型是植物
	timegap(TIME_GAP_DOUBLESHOOTER_ATTACK)
{
}

//析构函数
DoubleShooter::~DoubleShooter() {

}

//豌豆射手的攻击函数
//设置一个ATK为1的子弹！
Attack DoubleShooter::AttackEnemy(int time) {
	if (time % TIME_GAP_DOUBLESHOOTER_ATTACK == 0|| time % TIME_GAP_DOUBLESHOOTER_ATTACK == 1) {
		Attack atk(Attack::DoubleShooter_t);
		Bullet* blt = new Bullet(1, row, col);
		atk.SetBullet(blt);
		return atk;
	}
	else
		return Attack(Attack::None);
}