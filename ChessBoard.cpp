#include "ChessBoard.h"
#include"Config.h"


//构造函数
ChessBoard::ChessBoard()
	://初始化列表 一些基本配置
	row_num(ROW_NUM), //行数
	col_num(COL_NUM), //列数
	square_height(SQUARE_HEIGHT),//格子竖直间距
	square_width(SQUARE_WIDTH)//格子水平间距
{
	for (int i = 0; i < row_num; i++) {//对行列数组初始化
		vector<Object*> row;
		vec.push_back(row);
		for (int j = 0; j < col_num; j++) {
			//初始应该全是nullptr
			Object* p = nullptr;
			//Object* p = new Object(0,100);//*********************************************************
			vec[i].push_back(p);
		}
	}
}
//析构
ChessBoard::~ChessBoard() {
	for (int i = 0; i < row_num; i++) {//释放所有植物和僵尸的空间
		for (int j = 0; j < col_num; j++) {
			if (vec[i][j] != nullptr) {
				delete vec[i][j];
			}
		}
	}
}

//显示函数
void ChessBoard::Show() {
	for (int i = 0; i < 4; i++) {//分割线
		cout << "*****************************************************************************"<<endl<<endl<<endl;
	}
	Update();//更新状态
	set_std_pos(0, 1);
	for (int i = 0; i < row_num; i++) {//显示存在的物体的名字
		for (int j = 0; j < col_num; j++) {
			set_std_pos(j * square_width,2+ i * square_height);
			if (vec[i][j] != nullptr) {
				cout<<vec[i][j]->GetName();
			}
			else {
				cout << "None";
			}
		}
	}
}
//更新状态
void ChessBoard::Update() {
	for (int i = 0; i < row_num; i++) {
		for (int j = 0; j < col_num; j++) {
			set_std_pos(i * square_height, j * square_width);
			if (vec[i][j] != nullptr) {
				if (vec[i][j]->GetStatus() == Object::Dead) {
					Object* del = vec[i][j];
					vec[i][j] = nullptr;
					delete[] del;
				}
			}
		}
	}
}
