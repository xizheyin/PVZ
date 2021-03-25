#pragma once
#include"Object.h"
#include<vector>
using namespace std;

class ChessBoard
{
public:
	//构造函数
	ChessBoard();
	//析构函数
	~ChessBoard();
	//显示函数
	void Show();
private:
	//更新状态
	void Update();

	int row_num;
	int col_num;
	int square_height;
	int square_width;
	//存储行列上的植物和僵尸
	vector<vector<Object*>> vec;
};

