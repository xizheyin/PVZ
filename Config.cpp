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

//利用row和col获得x和y
Pos GetPos(int row, int col) { return Pos(col * SQUARE_WIDTH, 2 + row * SQUARE_HEIGHT); }

//判断是否超界
bool judge_pos(int row, int col) {
    return (row >= 0 && col >= 0 && row < ROW_NUM&& col < COL_NUM);
}