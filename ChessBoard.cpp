#include "ChessBoard.h"
#include"Config.h"


//构造函数
ChessBoard::ChessBoard()
	://初始化列表 一些基本配置
	maxrow(ROW_NUM), //行数
	maxcol(COL_NUM), //列数
	square_height(SQUARE_HEIGHT),//格子竖直间距
	square_width(SQUARE_WIDTH),//格子水平间距
	timecounter(0)//计时器
{
	for (int i = 0; i < maxrow+2; i++) {//对行列数组初始化
		vector<vector<Object*>>Orow;//这是一行地块，一行里的每个地块都有上述的一个vector
		vector<Bullet*> Brow;//子弹行
		
		yard.push_back(Orow);
		bulletyard.push_back(Brow);
		for (int j = 0; j < maxcol + 5; j++) {
			vector<Object*> objvec;//每一个地块都有一个vector，因为需要存放多个僵尸
			yard[i].push_back(objvec);//让行地块每一列都有一个空向量

			Bullet* bullet = nullptr;
			bulletyard[i].push_back(bullet);//让子弹行的每一列都有一个nullptr
		}
	}
}

//析构
ChessBoard::~ChessBoard() {
	for (int i = 0; i < maxrow; i++) {//释放所有植物和僵尸的空间
		for (int j = 0; j < maxcol; j++) {
			
			for (int k = 0; k < yard[i][j].size(); k++) {
				if (yard[i][j][k] != nullptr) {
					delete yard[i][j][k];//释放植物和僵尸
					yard[i][j][k] = nullptr;
				}
			}

			if (bulletyard[i][j] != nullptr) {
				delete bulletyard[i][j];//释放子弹
				bulletyard[i][j] = nullptr;
			}
		}
	}
}

//添加植物
bool ChessBoard::AddPlant(AbstractPlant* plant,int row,int col) {
	plant->SetRow(row);
	plant->SetCol(col);
	//如果这个地块向量是空的话，就push进去植物,因为植物不能重叠放，植物和僵尸不能重叠放
	if (yard[row][col].empty()) {
		yard[row][col].push_back(plant);
		return true;
	}
	else return false;
}

//添加僵尸
void ChessBoard::AddZombie(AbstractZombie* zombie,int row) {//添加一个僵尸
	yard[row][maxcol - 1].push_back(zombie);
}


void ChessBoard::AddBullet(Bullet* blt) {
	bulletyard[blt->GetRow()][blt->GetCol()] = blt;
}


//更新状态
bool ChessBoard::Update() {
	//每次更新时候都要让时间加1
	TimeUp();
	CreateZombie();
	//对i行j列进行遍历
	for (int i = 0; i < maxrow; i++) {
		for (int j = 0; j < maxcol; j++) {
			
			for (int k = yard[i][j].size() - 1; k >= 0; k--) {
				if (yard[i][j][k]->GetStatus() == Object::Dead) {//如果我遍历的这个死了
					if (yard[i][j][k]->GetType() == Object::Zombie_t)ScoreUp();
					ClearObj(i, j, k);
					continue;
				}
			}


			for (int k = yard[i][j].size() - 1; k >= 0; k--) {//检查完是不是死掉之后，检查是不是僵尸，是就移动
				if (yard[i][j][k]->GetType() == Object::Zombie_t) {
					if (j == 0)return false;//如果越界就游戏结束
					ZombieMove(i, j, k);
				}
			}

		}
	}

	//子弹从右向左遍历，因为子弹会右移，然后再次遍历就会继续往前走，导致bug
	for (int i = 0; i < maxrow; i++) {
		for (int j = maxcol-1; j >=0; j--) {
			if (bulletyard[i][j] != nullptr) {
				BulletMove(i, j);
			}
		}
	}
}

//清除Obj
void ChessBoard::ClearObj(int i, int j,int k) {
	delete yard[i][j][k];//释放（*it）指向的空间
	yard[i][j].erase(yard[i][j].begin()+k);//删除it
}

//清除子弹
void ChessBoard::ClearBullet(int r, int c) {
	Bullet* blt = bulletyard[r][c];
	bulletyard[r][c] = nullptr;
	delete blt;
}

//检查僵尸是否适合移动到这个位置
int ChessBoard::CheckPos(int r,int c,AbstractZombie* zmb) {//当空或者是僵尸，僵尸适合移动到这里
	if (c < 0)return false;
	if (yard[r][c].empty())return true;
	else if (yard[r][c][0]->GetType() == Object::Zombie_t)return 1;
	else if (yard[r][c][0]->GetType() == Object::Plant_t) {
		if (zmb->AttackEnemy(0).GetAttackType() == Attack::PolesZombie_t) {//利用攻击函数检查是不是撑杆僵尸
			PolesZombie* pz = static_cast<PolesZombie*>(zmb);
			if (pz->IsInit()) {//如果还没跳过植物过
				pz->ChangeInit(); return 2;
			}
			else return 0;
		}
		else return 0;
	}
	else return 0;
}

void ChessBoard::ZombieMove(int i,int j, int k) {
	AbstractZombie* zmb = static_cast<AbstractZombie*>(yard[i][j][k]);
	if (!(zmb->CanMove(timecounter)))return;
	int currow = i;
	int curcol = j;
	int nextrow = currow;
	int nextcol = curcol - 1;
	int speed = CheckPos(nextrow, nextcol, zmb);
	nextcol = curcol - speed;
	if (speed) {//当僵尸可以移动的话，就移动
		zmb->SetRC(nextrow, nextcol);//修改僵尸位置
		yard[nextrow][nextcol].push_back(zmb);//修改棋盘
		yard[currow][curcol].erase(yard[i][j].begin() + k);
	}
}

void ChessBoard::BulletMove(int i, int j) {
	Bullet* blt = bulletyard[i][j];
	int sp = blt->GetSpeed();
	if (sp + j >= maxcol-2) {//如果子弹过界了，就清除它
		delete blt;
	}
	else {//没过界就移动
		blt->SetCol(j + sp);
		bulletyard[i][j + sp] = blt;
	}
	bulletyard[i][j] = nullptr;
}

void ChessBoard::TimeUp() {
	timecounter++;
}

void ChessBoard::CreateZombie() {
	Object* obj = nullptr;
	NormalZombie* pz = nullptr;
	if (timecounter % TIME_GAP_CREATE_ZOMBIE==0) {
		int Row = random_num(ROW_NUM);
		switch ( random_num(MAX_KINDS_ZOMBIES) )
		{
		case 0:
			obj = new NormalZombie(Row);
			break;
		case 1:
			obj = new BarricadesZombie(Row);
			break;
		case 2:
			obj = new PaperZombie(Row);
			break;
		case 3:
			obj = new PolesZombie(Row);
		default:
			break;
		}

		RCPair rc = obj->GetRC();
		yard[rc.row][rc.col].push_back(obj);
	}
}


