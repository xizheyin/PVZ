#include "ChessBoard.h"
#include"Config.h"


//构造函数
ChessBoard::ChessBoard()
	://初始化列表 一些基本配置
	maxrow(ROW_NUM), //行数
	maxcol(COL_NUM), //列数
	square_height(SQUARE_HEIGHT),//格子竖直间距
	square_width(SQUARE_WIDTH)//格子水平间距
{
	for (int i = 0; i < maxrow; i++) {//对行列数组初始化
		vector<Object*> Orow;
		vector<Bullet*> Brow;
		yard.push_back(Orow);
		bulletyard.push_back(Brow);
		for (int j = 0; j < maxcol; j++) {
			//初始应该全是nullptr，要初始化两个yard！！！
			Object* p = nullptr;
			Bullet* bp = nullptr;
			//Object* p = new Object(0,100);//*********************************************************
			yard[i].push_back(p);
			bulletyard[i].push_back(bp);
		}
	}
	PeaShooter* ps = new PeaShooter(10, 1, 0);
	yard[1][0] = ps;
	NormalZombie* pz = new NormalZombie(10, 1);
	RCPair rc = pz->GetRC();
	yard[rc.row][rc.col] = pz;
}

//析构
ChessBoard::~ChessBoard() {
	for (int i = 0; i < maxrow; i++) {//释放所有植物和僵尸的空间
		for (int j = 0; j < maxcol; j++) {
			if (yard[i][j] != nullptr) {
				delete yard[i][j];//释放植物和僵尸
				yard[i][j] = nullptr;
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
	if (yard[row][col] == nullptr) {
		yard[row][col] = plant;
	}
	else return false;
}

//添加僵尸
void ChessBoard::AddZombie(AbstractZombie* zombie,int row) {//添加一个僵尸
	yard[row][maxcol - 1] = zombie;
}


void ChessBoard::AddBullet(Bullet* blt) {
	bulletyard[blt->GetRow()][blt->GetCol()] = blt;
}

//显示函数
void ChessBoard::Show() {
	ios::sync_with_stdio(false);
	//cin.tie(0);
	for (int i = 0; i < 4; i++) {//分割线
		cout << "*****************************************************************************"<<endl<<endl<<endl;
	}
	Update();//更新状态
	set_std_pos(0, 1);
	for (int i = 0; i < maxrow; i++) {//显示存在的物体的名字
		for (int j = 0; j < maxcol; j++) {
			Pos pos = GetPos(i, j);
			set_std_pos(pos.x,pos.y);
			if (yard[i][j] != nullptr) {
				cout<<yard[i][j]->GetName();//输出植物和僵尸
			}
			else {
				//cout << "N";
			}
			set_std_pos(pos.x, pos.y);
			if (bulletyard[i][j] != nullptr) {
				cout << "*";//输出子弹！
			}
		}
	}
}
//更新状态
void ChessBoard::Update() {
	
	for (int i = 0; i < maxrow; i++) {
		for (int j = 0; j < maxcol; j++) {
			if (yard[i][j] != nullptr) {
				if (yard[i][j]->GetStatus() == Object::Dead) {//检查是不是死了，死了就清除
					ClearObj(i, j);
					continue;
				}
				if (yard[i][j]->GetType() == Object::Zombie_t) {//检查是不是僵尸，僵尸可以移动
					if (j == 0)cout << "游戏结束！";
					ZombieMove(i, j);
				}
				
			}
		}
	}

	for (int i = 0; i < maxrow; i++) {
		for (int j = maxcol-1; j >=0; j--) {
			if (bulletyard[i][j] != nullptr) {
				BulletMove(i, j);
			}
		}
	}
}


void ChessBoard::ClearObj(int i, int j) {
	Object* del = yard[i][j];//如果死了就清除！
	yard[i][j] = nullptr;
	delete del;
}

void ChessBoard::ClearBullet(int r, int c) {
	Bullet* blt = bulletyard[r][c];
	bulletyard[r][c] = nullptr;
	delete blt;
}

//检查僵尸是否适合移动到这个位置
bool ChessBoard::CheckPos(int r,int c) {
	if (c < 0)return false;
	if (yard[r][c] == nullptr)return true;
	else return false;

}

void ChessBoard::ZombieMove(int i,int j) {
	AbstractZombie* zmb = static_cast<AbstractZombie*>(yard[i][j]);
	int currow = i;
	int curcol = j;
	int nextrow = currow;
	int nextcol = curcol - zmb->GetSpeed();
	if (CheckPos(nextrow, nextcol)) {//当僵尸可以移动的话，就移动
		zmb->SetRC(nextrow, nextcol);//修改僵尸位置
		yard[nextrow][nextcol] = yard[currow][curcol];//修改棋盘
		yard[currow][curcol] = nullptr;
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