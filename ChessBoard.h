#pragma once
#include"Object.h"
#include"AbstractPlant.h"
#include"AbstractZombie.h"
#include"PeaShooter.h"
#include"NormalZombie.h"
#include<vector>
using namespace std;

class ChessBoard
{
public:
	struct Pos {
		int x, y;
		Pos(int _x, int _y) { x = _x; y = _y; }
	};
	//获得实际位置，是（x，y）二元组
	Pos GetPos(int row, int col) { return Pos(col * square_width, 2 + row * square_height); }
	
	
	//构造函数
	ChessBoard();
	//析构函数
	~ChessBoard();
	//显示函数
	void Show();
	//更新状态
	void Update();
	//在某位置添加植物，如果不行返回false
	bool AddPlant(AbstractPlant* plant,int row,int col);
	//在某行添加僵尸
	void AddZombie(AbstractZombie* zombie,int row);
	//添加某个子弹
	void AddBullet(Bullet* blt);
	//获得最大行数
	int GetMaxRow()const { return maxrow; }
	//获得最大列数
	int GetMaxCol()const { return maxcol; }
	//得到当前行列的Object指针
	Object* GetObject(int r, int c) { return yard[r][c]; }
	//得到当前行列的子弹指针
	Bullet* GetBullet(int r, int c) { return bulletyard[r][c]; }
	//清除行列的子弹
	void ClearBullet(int r, int c);
private:
	//清除当前行列的Obj
	void ClearObj(int i,int j);
	//查看僵尸是否适合前移
	bool CheckPos(int r,int c);
	//僵尸进行移动
	void ZombieMove(int i, int j);
	//子弹进行移动
	void BulletMove(int i, int j);


	//最大行数
	int maxrow;
	//最大列数
	int maxcol;
	//格子竖直上的差距
	int square_height;
	//格子水平上的差距
	int square_width;
	//存储行列上的植物和僵尸
	vector<vector<Object*>> yard;
	//单独用一个子弹yard存储子弹
	vector<vector<Bullet*>> bulletyard;
};

