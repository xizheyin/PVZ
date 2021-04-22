#include "UI.h"

//在下面展示一些基础信息
void UI::ShowInfo(ChessBoard* chessbd, PlantShop* pshop) {
	Pos pos = GetPos(ROW_NUM,0);
	set_std_pos(pos.x, pos.y);
	cout << "+----------------------+---------------------+" << endl;
	cout << "|阳光总数|" << pshop->GetSun() << "  |得分总数|" << chessbd->GetScore() << endl;
	cout << "+----------------------+---------------------+";
}

//输出棋盘
void UI::ShowChessboard(ChessBoard* chessbd) {
	ios::sync_with_stdio(false);
	set_std_pos(0, 0);
	for (int i = 0; i < 4; i++) {//分割线
		cout << "+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+" << endl;
		if (i != 3) {
			cout << "|        |        |        |        |        |        |        |        |        |        |" << endl;
			cout << "                                                                                           " << endl;
			cout << "|        |        |        |        |        |        |        |        |        |        |" << endl;
		}
	}
	set_std_pos(0, 1);
	Object* obj=nullptr;
	Bullet* blt = nullptr;
	for (int i = 0; i < ROW_NUM; i++) {//显示存在的物体的名字
		for (int j = 0; j < COL_NUM; j++) {
			Pos pos = GetPos(i, j);

			set_std_pos(pos.x, pos.y);
			blt = chessbd->GetBullet(i, j);
			if (blt != nullptr) {
				cout << "●";//输出子弹！
			}
			for (int k = 0; k < chessbd->GetPlotSize(i,j); k++) {
				obj = nullptr;
				obj = chessbd->GetObject(i, j, k);
				if (obj->GetType() == Object::Plant_t) {
					if (static_cast<AbstractPlant*>(obj)->GetPlantType() == AbstractPlant::Cherry_t) {
						set_std_pos(pos.x - 3, pos.y + 1);
						cout << static_cast<Cherry*>(obj)->GetTimeLeft();
					}
					else if (static_cast<AbstractPlant*>(obj)->GetPlantType() == AbstractPlant::Pumpkin_t) {
						set_std_pos(pos.x - 3, pos.y + 1);
						cout << obj->GetName()<<""<< (100 * obj->GetHp()) / obj->GetMaxHp() << "%";
						continue;
					}
				}
				set_std_pos(pos.x - 3, pos.y - 1);
				cout << "" << (100*obj->GetHp()) / obj->GetMaxHp() << "%";
				set_std_pos(pos.x-2, pos.y);
				cout << obj->GetName();//输出植物和僵尸
				
			}			
		}
	}
	ShowShop();
	hide_std();
}

//买植物的UI
void UI::BuyPlant(ChessBoard* chessbd, PlantShop* pshop) {
	//this->ShowShop();
	char ch;
	while (1) {
		if (_kbhit()) {
			ch = _getch();//获取按下的按键
			if(ch>='0'&&ch<='9')break;
		}
		Sleep(200);
	}
	Object* obj = nullptr;
	RCPair rcp(-1,-1);
	bool Success = false;
	rcp=SelectArea(chessbd);
	switch (ch)
	{
	case '0'://太阳花
		obj = new SunFlower();//hp是10
		if (pshop->CheckEnough(PlantShop::SunFlower_t)) {
			Success=pshop->SettlePlant(obj, chessbd, rcp.row, rcp.col);
			if(Success)pshop->SubSun(PlantShop::SunFlower_t);
			return;
		}
		break;
	case '1'://豌豆射手
		obj = new PeaShooter();//利用默认参数列表，后续设置位置
		if (pshop->CheckEnough(PlantShop::PeaShooter_t)) {
			Success=pshop->SettlePlant(obj, chessbd, rcp.row, rcp.col);
			if(Success)pshop->SubSun(PlantShop::PeaShooter_t);
			return;
		}
		break;
	case '2'://坚果墙
		obj = new NutWall();
		if (pshop->CheckEnough(PlantShop::NutWall_t)) {
			Success = pshop->SettlePlant(obj, chessbd, rcp.row, rcp.col);
			if (Success)pshop->SubSun(PlantShop::NutWall_t);
			return;
		}
		break;
	case '3'://双发射手
		obj = new DoubleShooter();
		if (pshop->CheckEnough(PlantShop::DoubleShooter_t)) {
			Success = pshop->SettlePlant(obj, chessbd, rcp.row, rcp.col);
			if (Success)pshop->SubSun(PlantShop::PeaShooter_t);
			return;
		}
		break;
	case '4':
		obj = new IceShooter();
		if (pshop->CheckEnough(PlantShop::IceShooter_t)) {
			Success = pshop->SettlePlant(obj, chessbd, rcp.row, rcp.col);
			if (Success)pshop->SubSun(PlantShop::IceShooter_t);
			return;
		}
		break;
	case '5':
		obj = new HighNut();
		if (pshop->CheckEnough(PlantShop::IceShooter_t)) {
			Success = pshop->SettlePlant(obj, chessbd, rcp.row, rcp.col);
			if (Success)pshop->SubSun(PlantShop::HighNut_t);
			return;
		}
		break;
	case '6':
		obj = new Squash();
		if (pshop->CheckEnough(PlantShop::Squash_t)) {
			Success = pshop->SettlePlant(obj, chessbd, rcp.row, rcp.col);
			if (Success)pshop->SubSun(PlantShop::Squash_t);
			return;
		}
		break;
	case '7':
		obj = new Cherry();
		if (pshop->CheckEnough(PlantShop::Cherry_t)) {
			Success = pshop->SettlePlant(obj, chessbd, rcp.row, rcp.col);
			if (Success)pshop->SubSun(PlantShop::Cherry_t);
			return;
		}
		break;
	case '8':
		obj = new Garlic();
		if (pshop->CheckEnough(PlantShop::Garlic_t)) {
			Success = pshop->SettlePlant(obj, chessbd, rcp.row, rcp.col);
			if (Success)pshop->SubSun(PlantShop::Garlic_t);
			return;
		}
		break;
	case '9':
		obj = new Pumpkin();
		if (pshop->CheckEnough(PlantShop::Pumpkin_t)) {
			Success = pshop->SettlePlant(obj, chessbd, rcp.row, rcp.col);//南瓜头就穿进去一个空obj
			if (Success)pshop->SubSun(PlantShop::Pumpkin_t);
			return;
		}
		break;
	default:
		BuyPlant(chessbd,pshop);
		break;
	}
	return;
}

//选择地块
const RCPair UI::SelectArea(ChessBoard* chessbd) {
	RCPair rcp(-1, -1);

	char chInput;//定义一个char型变量存储按下按键的值
	int r = 0, c = 1;
	Pos pos = GetPos(r, c);
	set_std_pos(pos.x, pos.y);
	this->ShowChessboard(chessbd);
	while (1) {
		
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
				if (judge_pos(r, c - 3)) {
					c-=3;
					pos = GetPos(r, c);
					set_std_pos(pos.x, pos.y);
				}
				break;
			case 77://右
				if (judge_pos(r, c + 3)) {
					c+=3;
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
			this->ShowChessboard(chessbd);
			PrintSelectBox(r, c);
		}
	}
}

void UI::PrintSelectBox(int r, int c) {
	Pos pos = GetPos(r, c);
	int x = pos.x, y = pos.y;
	set_std_color(FOREGROUND_GREEN);
	set_std_pos(x - 4, y - 2);
	cout << "+--------+";
	set_std_pos(x - 4, y - 1);
	cout << "|";
	set_std_pos(x - 4, y + 1);
	cout << "|";
	set_std_pos(x + 5, y - 1);
	cout << "|";
	set_std_pos(x + 5, y + 1);
	cout << "|";
	set_std_pos(x - 4, y + 2);
	cout << "+--------+";
	reset_std_color();
}

void UI::ShowShop() {
	Pos pos = GetPos(ROW_NUM+1, 0);
	set_std_pos(pos.x, pos.y);
	cout << "欢迎来到植物商店" << endl;
	cout << "+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+" << endl;
	cout << "|   0    |   1    |   2    |   3    |   4    |   5    |   6    |   7    |   8    |   9    |" << endl;
	cout << "| 太阳花 |豌豆射手| 坚果墙 |双发射手|寒冰射手| 高坚果 |  倭瓜  |  樱桃  |  大蒜  |  南瓜  |" << endl;
	cout << "|  ￥75  | ￥100  |  ￥60  | ￥150  | ￥120  | ￥150  |  ￥80  | ￥100  |  ￥100 |  ￥50  |" << endl;
	cout << "+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+" << endl;
}