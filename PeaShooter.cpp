#include "PeaShooter.h"

//构造函数
PeaShooter::PeaShooter(int hp,int r,int c)
	:
	AbstractPlant(hp,r,c)//类型是植物
{

}

//析构函数
PeaShooter::~PeaShooter() {

}

//豌豆射手的攻击函数
//设置一个ATK为1的子弹！
Attack PeaShooter::AttackEnemy() {
	Attack atk(Attack::PeaShooter);
	Bullet* blt = new Bullet(1,row,col);
	atk.SetBullet(blt);
	return atk;
}