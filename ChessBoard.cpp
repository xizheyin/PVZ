#include "ChessBoard.h"
#include"Config.h"


ChessBoard::ChessBoard() {
	row_num = ROW_NUM;//一些基本配置
	col_num = COL_NUM;
	square_height=SQUARE_HEIGHT;
	square_width=SQUARE_WIDTH;
	for (int i = 0; i < row_num; i++) {//对行列数组初始化
		vector<Object*> row;
		vec.push_back(row);
		for (int j = 0; j < col_num; j++) {
			Object* p = new Object();//*********************************************************
			vec[i].push_back(p);
		}
	}
}
ChessBoard::~ChessBoard() {
	for (int i = 0; i < row_num; i++) {//释放所有植物和僵尸的空间
		for (int j = 0; j < col_num; j++) {
			if (vec[i][j] != nullptr) {
				delete vec[i][j];
			}
		}
	}
}

void ChessBoard::Show() {
	//cout << vec.size()<<" "<<vec[0].size()<<endl;
	for (int i = 0; i < 4; i++) {
		cout << "*****************************************************************************"<<endl<<endl<<endl;
	}
	
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
	set_std_pos(0, 1);
	for (int i = 0; i < row_num; i++) {
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
