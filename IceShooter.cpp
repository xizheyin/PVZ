#include "IceShooter.h"

//构造函数
IceShooter::IceShooter(int r, int c)
	:
	AbstractPlant(HP_ICESHOOTER, r, c),//类型是植物
	timegap(TIME_GAP_ICESHOOTER_ATTACK)
{
}

//析构函数
IceShooter::~IceShooter() {

}

//豌豆射手的攻击函数
//设置一个ATK为1的子弹！
Attack IceShooter::AttackEnemy(int time) {
	if (time % TIME_GAP_ICESHOOTER_ATTACK == 0) {
		Attack atk(Attack::IceShooter_t);
		Bullet* blt = new Bullet(1, row, col);
		blt->SetIce();
		atk.SetBullet(blt);
		return atk;
	}
	else
		return Attack(Attack::None);
}