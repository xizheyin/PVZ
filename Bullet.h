#pragma once



class Bullet
{

public:
	Bullet(int _ATK, int r, int c);
	~Bullet();
	//设置伤害值
	void SetATK(int atk) { ATK = atk; }
	//设置行
	void SetRow(int r) { row = r; }
	//设置列
	void SetCol(int c) { col = c; }
	//设置速度
	void SetSpeed(int sp) { speed = sp; }
	//获得伤害值
	int GetATK()const { return ATK; }
	//获得行数
	int GetRow()const { return row; }
	//获得列数
	int GetCol()const { return col; }
	//获得速度
	int GetSpeed()const { return speed; }

private:
	//子弹伤害值
	int ATK;
	//行，列
	int row,col;
	//子弹速度
	int speed;
};

