#pragma once
#include<Windows.h>
#include<iostream>
#include<time.h>

//最大行数和最大列数
const int ROW_NUM = 3;
const int COL_NUM = 32;
//行和行之间上下差距，左右差距
const int SQUARE_HEIGHT = 4;
const int SQUARE_WIDTH = 3;
//僵尸种类上限
const int MAX_KINDS_ZOMBIES = 6;
//僵尸产生的时间gap
const int TIME_GAP_CREATE_ZOMBIE = 10;

//普通僵尸移动的gap
const int TIME_GAP_NORMAL_ZOMBIE = 2;
//路障僵尸移动gap
const int TIME_GAP_BARRICADES_ZOMBIE = 2;
//读报僵尸移动gap
const int TIME_GAP_PAPER_ZOMBIE = 2;
//撑杆僵尸移动gap
const int TIME_GAP_POLES_ZOMBIE = 2;
//小丑僵尸移动gap
const int TIME_GAP_CLOWN_ZOMBIE = 2;
//投石僵尸移动gap
const int TIME_GAP_CAST_ZOMBIE = 2;

//普通僵尸基础生命
const int HP_NORMAL_ZOMBIE = 10;
//路障僵尸基础生命
const int HP_BARRICADES_ZOMBIE = 30;
//读报僵尸基础生命
const int HP_PAPER_ZOMBIE = 10;
//撑杆僵尸基础生命
const int HP_POLES_ZOMBIE = 10;
//小丑僵尸基础生命
const int HP_CLOWN_ZOMBIE = 10;
//投石僵尸基础生命
const int HP_CAST_ZOMBIE = 15;


//投石僵尸投篮gap
const int TIME_GAP_CAST = 2;

//投石僵尸初始篮球数
const int NUM_OF_BALL = 3;


//豌豆射手初始hp
const int HP_PEASHOOTER = 15;
//太阳花初始hp
const int HP_SUNFLOWER = 20;
//坚果墙初始hp
const int HP_NUTWALL = 120;
//双发射手初始hp
const int HP_DOUBLESHOOTER = 20;
//寒冰射手初始hp
const int HP_ICESHOOTER = 20;
//高坚果
const int HP_HIGHNUT = 240;
//倭瓜
const int HP_SQUASH = 10;
//樱桃
const int HP_CHERRY = 20;



//豌豆射手攻击gap
const int TIME_GAP_PEASHOOTER_ATTACK = 4;
//产生阳光gap
const int TIME_GAP_CREATESUN = 20;
//双发射手
const int TIME_GAP_DOUBLESHOOTER_ATTACK = 4;
//寒冰射手
const int TIME_GAP_ICESHOOTER_ATTACK = 4;


const int DOUBLESHOOTER_COST = 150;
const int NUTWALL_COST = 60;
const int PEASHOOTER_COST =100;
const int SUNFLOWER_COST = 75;
const int ICESHOOTER_COST = 120;
const int HIGHNUT_COST = 200;
const int SQUASH_COST = 80;
const int CHERRY_COST = 100;


//初始化阳光数目
const int INIT_SUN = 5000;



//设置颜色
void set_std_color(int color);
//重置颜色
void reset_std_color();
//设置光标位置
void set_std_pos(int x, int y);
//隐藏光标
void hide_std();

//结构体，行和列
struct RCPair{
	int row, col;
	RCPair(int r, int c) { row = r; col = c; }
};

//结构体，x和y
struct Pos {
	int x, y;
	Pos(int _x, int _y) { x = _x; y = _y; }
};
//获得实际位置，是（x，y）二元组
Pos GetPos(int row, int col);

//判断是不是超界了
bool judge_pos(int row, int col);

//随机数
int random_num(int Max);
int random_num_based_seed(int Max,int seed);