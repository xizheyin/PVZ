#pragma once
class Bullet
{

public:
	Bullet(int _ATK, int r, int c) {
		speed = 1;//子弹速度都是1
		ATK = _ATK;
		row = r;
		col = c;
	}

	void SetATK(int atk) { ATK = atk; }
	void SetRow(int r) { row = r; }
	void SetCol(int c) { col = c; }
	void SetSpeed(int sp) { speed = sp; }
	int GetATK()const { return ATK; }
	int GetRow()const { return row; }
	int GetCol()const { return col; }
	int GetSpeed()const { return speed; }

private:
	int ATK;
	int row,col;
	int speed;
};

