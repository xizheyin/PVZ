#include"Config.h"

//设置输出颜色
void set_std_color(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);;
    SetConsoleTextAttribute(hConsole, color);
}

//重置输出颜色
void reset_std_color() {
    set_std_color(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
}

//设置光标位置
void set_std_pos(int x, int y)
{
    HANDLE winHandle;//句柄
    COORD pos = { x,y };
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    //设置光标位置 
    SetConsoleCursorPosition(winHandle, pos);
}

void hide_std() {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
    CursorInfo.bVisible = false; //隐藏控制台光标
    SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态

}

//利用row和col获得x和y
Pos GetPos(int row, int col) { return Pos(1 + col * SQUARE_WIDTH, 2 + row * SQUARE_HEIGHT); }

//判断是否超界
bool judge_pos(int row, int col) {
    return (row >= 0 && col >= 0 && row < ROW_NUM&& col < COL_NUM);
}

//生成随机数，Max是随机数最大值
int random_num(int Max) {
    srand(time(NULL));
    return rand() % Max;
}

//基于某个种子生成随机数
int random_num_based_seed(int Max, int seed) {
    srand(seed);
    return rand() % Max;
}