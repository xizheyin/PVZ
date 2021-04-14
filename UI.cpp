#include "UI.h"


//在下面展示一些基础信息
void UI::ShowInfo(ChessBoard* chessbd, PlantShop* pshop) {
	Pos pos = GetPos(ROW_NUM,0);
	set_std_pos(pos.x, pos.y);
	cout << "阳光总数:" << pshop->GetSun() << "     ";
	cout << "得分总数:" << chessbd->GetScore() << endl;
}


//输出棋盘
void UI::ShowChessboard(ChessBoard* chessbd) {
	ios::sync_with_stdio(false);
	//cin.tie(0);
	for (int i = 0; i < 4; i++) {//分割线
		cout << "************************************************************************************************" << endl << endl << endl << endl;
	}
	set_std_pos(0, 1);
	Object* obj=nullptr;
	Bullet* blt = nullptr;
	for (int i = 0; i < ROW_NUM; i++) {//显示存在的物体的名字
		for (int j = 0; j < COL_NUM; j++) {
			Pos pos = GetPos(i, j);
			for (int k = 0; k < chessbd->GetPlotSize(i,j); k++) {
				obj = nullptr;
				obj = chessbd->GetObject(i, j, k);
				
				set_std_pos(pos.x, pos.y);
				if (obj != nullptr) {
					cout << obj->GetName();//输出植物和僵尸
				}
				else {
					//cout << "N";
				}
			}
			blt = chessbd->GetBullet(i, j);
			set_std_pos(pos.x, pos.y);
			if (blt != nullptr) {
				cout << "*";//输出子弹！
			}
		}
	}
}





//买植物的UI
void UI::BuyPlant(ChessBoard* chessbd, PlantShop* pshop) {
	system("cls");
	this->ShowShop();
	//this->ShowChessboard(chessbd);
	int n = -1;
	cin >> n;
	Object* obj = nullptr;
	RCPair rcp(-1,-1);
	bool Success = false;
	if (Confirm(n)) {//是否确认购买
		rcp=SelectArea(chessbd);
		switch (n)
		{
		case 1://太阳花
			obj = new SunFlower(10);//hp是10
			if (pshop->CheckEnough(PlantShop::SunFlower_t)) {
				Success=pshop->SettlePlant(obj, chessbd, rcp.row, rcp.col);
				if(Success)pshop->SubSun(PlantShop::SunFlower_t);
				return;
			}
			break;
		case 2://豌豆射手
			obj = new PeaShooter(10);//利用默认参数列表，后续设置位置
			if (pshop->CheckEnough(PlantShop::PeaShooter_t)) {
				Success=pshop->SettlePlant(obj, chessbd, rcp.row, rcp.col);
				if(Success)pshop->SubSun(PlantShop::PeaShooter_t);
				return;
			}
			break;
		default:
			WrongInput();//错误输入，显示相关信息并且重新进入
			BuyPlant(chessbd,pshop);
			break;
		}
	}
	BuyPlant(chessbd,pshop);
	return;
}

//错误信息提示
void UI::WrongInput() {
	cout << endl << endl;
	set_std_color(FOREGROUND_RED);
	cout << "Illegal Input！！！ Please reinput！！！";
	reset_std_color();
}

//显示确认信息，看是不是真的要买这个植物！
bool UI::Confirm(int n) {
	string plantname;
	switch (n)
	{
	case 1: plantname = "SunFlower"; break;
	case 2: plantname = "PeaShooter"; break;
	default: break;
	}
	cout << "Are you sure to buy No." << n << " " << plantname << "？" << endl;
	cout << "Input “y” or “n” ：";
	string a;
	cin >> a;
	if (a == "y")return true;
	else return false;
}

//选择地块
const RCPair UI::SelectArea(ChessBoard* chessbd) {
	RCPair rcp(-1, -1);

	char chInput;//定义一个char型变量存储按下按键的值
	int r = 0, c = 0;
	Pos pos = GetPos(r, c);
	set_std_pos(pos.x, pos.y);
	while (1) {
		system("cls");
		this->ShowChessboard(chessbd);
		PrintSelectBox(r, c);
		if (_kbhit())//如果有按键按下
		{
			chInput = _getch();//获取按下的按键
			switch (chInput) {//根据按下的按键来进行相应的光标移动
			case 72://上
				if (judge_pos(r - 1, c)) {
					r--;
					pos = GetPos(r, c);
					set_std_pos(pos.x, pos.y);
				}
				break;
			case 80://下
				if (judge_pos(r + 1, c)) {
					r++;
					pos = GetPos(r, c);
					set_std_pos(pos.x, pos.y);
				}
				break;
			case 75://左
				if (judge_pos(r, c - 1)) {
					c--;
					pos = GetPos(r, c);
					set_std_pos(pos.x, pos.y);
				}
				break;
			case 77://右
				if (judge_pos(r, c + 1)) {
					c++;
					pos = GetPos(r, c);
					set_std_pos(pos.x, pos.y);
				}
				break;
			case 13://回车，表示确定,直接返回
				return RCPair(r, c);
				break;
			default:
				break;
			}
		}
	}

}


void UI::PrintSelectBox(int r, int c) {
	Pos pos = GetPos(r, c);
	int x = pos.x, y = pos.y;
	set_std_color(FOREGROUND_RED);
	set_std_pos(x - 1, y - 1);
	cout << "###";
	set_std_pos(x - 1, y);
	cout << "#";
	set_std_pos(x + 1, y);
	cout << "#";
	set_std_pos(x - 1, y + 1);
	cout << "###";
	reset_std_color();
}


void UI::ShowShop() {
	system("cls");
	cout << "************************************" << endl;
	cout << "      Welcome to Plant Shop!!!      " << endl;
	cout << "************************************" << endl;
	cout << "You can buy any plant if you have enough money!" << endl;
	cout << "The optional plants are as follows <^*^>" << endl;
	cout << "1.SunFlower" << " "
		 << "2.PeaShooter" << " "
		 << endl;
	cout << "Please input your choice:";
}