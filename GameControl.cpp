#include "GameControl.h"



//更新棋盘上生物的状态（开始攻击）
//让棋盘上的生物进行攻击
void GameControl::UpdateChessbd(ChessBoard* chessbd) {

	//对棋盘上所有方格进行遍历
	for (int i = 0; i < ROW_NUM; i++) {
		for (int j = 0; j < COL_NUM; j++) {

			//遍历所有子弹
			Bullet* blt = chessbd->GetBullet(i, j);
			if (blt != nullptr)BulletControl(blt, chessbd);
			
			//遍历所有生物
			Object* obj = chessbd->GetObject(i, j);//获得i行j列的生物
			if (obj == nullptr)continue;
			switch (obj->GetType())
			{
			case Object::Plant_t://如果生物是植物的话，那么就转进植物的控制模块
				PlantControl(obj,chessbd);
				break;
			case Object::Zombie_t://如果生物是僵尸的话，那么转进僵尸的控制模块
				ZombieControl(obj,chessbd);
				break;
			default:
				break;
			}


		}
	}
}

//控制植物攻击，目前只有豌豆射手
void GameControl::PlantControl(Object* obj,ChessBoard* chessbd) {
	//RCPair rc = obj->GetRC();
	Attack attack=obj->AttackEnemy();
	switch (attack.GetAttackType())
	{
	case Attack::PeaShooter:
		chessbd->AddBullet(attack.GetBullet());
		break;
	default:
		break;
	}
}


//控制僵尸攻击，目前只有普通僵尸
void GameControl::ZombieControl(Object* obj,ChessBoard* chessbd) {
	Attack attack = obj->AttackEnemy();
	RCPair rc = obj->GetRC();
	int ATK = 0;
	Object* enemy = nullptr;
	switch (attack.GetAttackType())
	{
	case Attack::Zombie:
		ATK = attack.GetATK();
		enemy = chessbd->GetObject(rc.row, rc.col-1);//找到前面的植物，
		if (obj != nullptr) {
			if (obj->GetType() == Object::Plant_t) {
				obj->Isattacked(ATK);
			}
		}
		break;

	default:
		break;
	}
}

//控制子弹进行攻击，记住，攻击当前和前面的一个人，因为僵尸和子弹同时动
void GameControl::BulletControl(Bullet* blt, ChessBoard* chessbd) {
	int r = blt->GetRow();
	int c = blt->GetCol();
	Object* obj = chessbd->GetObject(r,c);//当前的
	if (obj != nullptr) {
		if (obj->GetType() == Object::Zombie_t) {
			obj->Isattacked(blt->GetATK());
		}
		chessbd->ClearBullet(r, c);
	}
	obj = chessbd->GetObject(r, c + 1);//子弹前面的一个
	if (obj != nullptr) {
		if (obj->GetType() == Object::Zombie_t) {
			obj->Isattacked(blt->GetATK());
		}
		chessbd->ClearBullet(r, c);
	}
}

