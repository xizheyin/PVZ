#pragma once
#include"Object.h"
#include<vector>
using namespace std;

class ChessBoard
{
public:
	ChessBoard();
	~ChessBoard();
	void Show();

private:
	void Update();

	int row_num;
	int col_num;
	int square_height;
	int square_width;
	vector<vector<Object*>> vec;
};

