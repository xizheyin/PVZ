#include "GameControl.h"

//更新棋盘上生物的状态（开始攻击），让棋盘上的生物进行攻击
void GameControl::UpdateChessbd(ChessBoard* chessbd,PlantShop* pshop) {

	//对棋盘上所有方格进行遍历
	for (int i = 0; i < ROW_NUM; i++) {
		for (int j = 0; j < COL_NUM; j++) {



			//遍历所有子弹
			Bullet* blt = chessbd->GetBullet(i, j);
			if (blt != nullptr)BulletControl(blt, chessbd);
			
			for (int k = 0; k < chessbd->GetPlotSize(i, j); k++) {

				//遍历所有生物
				Object* obj = chessbd->GetObject(i, j, k);//获得i行j列的生物
				switch (obj->GetType())
				{

				case Object::Plant_t://如果生物是植物的话，那么就转进植物的控制模块
					PlantControl(obj, chessbd, pshop);
					break;
				case Object::Zombie_t://如果生物是僵尸的话，那么转进僵尸的控制模块
					ZombieControl(obj, chessbd);
					break;
				default:
					break;

				}

			}
		}
	}
}

//控制植物攻击，目前只有豌豆射手
void GameControl::PlantControl(Object* obj,ChessBoard* chessbd,PlantShop* pshop) {
	//来获得攻击对象
	Attack attack=obj->AttackEnemy(chessbd->GetTime());
	//如果发现攻击对象啥也不是就return
	if (attack.GetAttackType() == Attack::None)return;
	switch (attack.GetAttackType())
	{
	case Attack::IceShooter_t:
	case Attack::DoubleShooter_t:
	case Attack::PeaShooter_t:
		chessbd->AddBullet(attack.GetBullet());
		break;
	case Attack::SunFlower_t:
		pshop->AddSun(attack.GetATK());
		break;
	case Attack::NutWall_t:
		break;

	default:
		break;
	}
}

//控制僵尸攻击，目前只有普通僵尸
void GameControl::ZombieControl(Object* obj,ChessBoard* chessbd) {
	Attack attack = obj->AttackEnemy(chessbd->GetTime());
	RCPair rc = obj->GetRC();
	Object* enemy = nullptr;
	int rnum=0;
	if (rc.col == 0)return;
	switch (attack.GetAttackType())
	{
	case Attack::CastZombie_Car_t:
	case Attack::NormalZombie_t:
	case Attack::BarricadesZombie_t:
	case Attack::PaperZombie_t:
	case Attack::PolesZombie_t:
		if (chessbd->GetPlotSize(rc.row, rc.col - 1) > 0)enemy = chessbd->GetObject(rc.row, rc.col - 1, 0);//找到前面的植物，
		if (enemy != nullptr) {
			if (enemy->GetType() == Object::Plant_t) {
				enemy->Isattacked(attack.GetATK());
			}
		}
		break;
	case Attack::ClownZombie_t:
		rnum=random_num(100);
		if (rnum == 0||rc.col<=6) {
			for (int i = -1; i <= 1; i++) {//遍历3x3
				for (int j = -6; j <= 6; j++) {
					if (chessbd->GetPlotSize(rc.row + i, rc.col + j) > 0) {
						enemy = chessbd->GetObject(rc.row + i, rc.col + j, 0);
						enemy->Isattacked(attack.GetATK());//小丑也把自己炸死
					}
				}
			}
		}
		break;
	case Attack::CastZombie_Cast_t:
		for (int i = 0; i < rc.col; i++) {//找到当前行最左边的植物
			if (chessbd->GetPlotSize(rc.row, i) > 0) {
				enemy = chessbd->GetObject(rc.row, i, 0);
				if (enemy->GetType() == Object::Plant_t) {
					enemy->Isattacked(attack.GetATK());
				}
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
	bool flag = false;
	Object* obj = nullptr;
	if (chessbd->GetPlotSize(r, c) > 0) obj = chessbd->GetObject(r, c, 0);
	if (obj != nullptr) {
		if (obj->GetType() == Object::Zombie_t) {
			obj->Isattacked(blt->GetATK());
			if (blt->IsIce())static_cast<AbstractZombie*>(obj)->SpeedDown();
			flag = true;
		}
	}
	obj = nullptr;
	if (chessbd->GetPlotSize(r, c + 1) > 0)obj = chessbd->GetObject(r, c + 1, 0);//子弹前面的一个
	if (obj != nullptr) {
		if (obj->GetType() == Object::Zombie_t) {
			obj->Isattacked(blt->GetATK());
			if (blt->IsIce())static_cast<AbstractZombie*>(obj)->SpeedDown();
			flag = true;
		}
	}
	if(flag)chessbd->ClearBullet(r, c);
}

