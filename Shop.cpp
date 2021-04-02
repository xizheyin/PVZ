#include "Shop.h"
#include<conio.h>


//构造函数
Shop::Shop() {

}

//析构函数
Shop::~Shop() {

}

//主控逻辑函数
void Shop::BuyPlant(ChessBoard* chessbd) {
	this->Show();
	int n = -1;
	cin >> n;
	Object* obj = nullptr;
	if (Confirm(n)) {//是否确认购买
		switch (n)
		{
		case 1://太阳花
			obj = new SunFlower(10);//hp是10
			SettlePlant(obj, chessbd);
			break;
		case 2://豌豆射手
			obj = new PeaShooter(10);//利用默认参数列表，后续设置位置
			SettlePlant(obj, chessbd);
			break;
		default:
			WrongInput();//错误输入，显示相关信息并且重新进入
			BuyPlant(chessbd);
			break;
		}
	}
	else {
		BuyPlant(chessbd);
		return;
	}
	
}

//输出头
void Shop::Show() {
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

//错误信息提示
void Shop::WrongInput() {
	cout << endl << endl;
	set_std_color(FOREGROUND_RED);
	cout << "Illegal Input！！！ Please reinput！！！";
	reset_std_color();
}

//显示确认信息，看是不是真的要买这个植物！
bool Shop::Confirm(int n) {
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

//安放植物，包括选择地块之类的
void Shop::SettlePlant(Object* obj, ChessBoard* chessbd) {
	RCPair rcp=SelectArea(chessbd);
	bool flag = chessbd->AddPlant(static_cast<AbstractPlant*>(obj), rcp.row, rcp.col);
	if (!flag) {//如果安放不了的话，说明棋盘rc被占用了，所以要重新选择
		cout << "Position Occupied！Reselect！" << endl;
		SettlePlant(obj, chessbd);
	}
	return;
}

//选择地块
const RCPair Shop::SelectArea(ChessBoard* chessbd) {
	RCPair rcp(-1,-1);

	char chInput;//定义一个char型变量存储按下按键的值
	int r=0, c=0;
	Pos pos = GetPos(r, c);
	set_std_pos(pos.x, pos.y);
	while (1) {
		system("cls");
		chessbd->Show();
		PrintSelectBox(r, c);
		if (_kbhit())//如果有按键按下
		{
			chInput = _getch();//获取按下的按键
			switch (chInput) {//根据按下的按键来进行相应的光标移动
			case 72://上
				if (judge_pos(r - 1, c)) {
					r--;
					pos = GetPos(r , c);
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
				if (judge_pos(r , c-1)) {
					c--;
					pos = GetPos(r, c);
					set_std_pos(pos.x, pos.y);
				}
				break;
			case 77://右
				if (judge_pos(r , c+1)) {
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


void Shop::PrintSelectBox(int r, int c) {
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