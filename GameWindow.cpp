#include "GameWindow.h"

//构造函数
GameWindow::GameWindow():chessbd(new ChessBoard()),gamectrl(new GameControl()) {

}

//析构函数
GameWindow::~GameWindow() {
	delete chessbd;
	delete gamectrl;
}

//游戏函数，通过一个循环，每次更新棋盘和刷新屏幕
void GameWindow::Play() {
	while (1) {
		this->Update();
		this->Show();
		Sleep(500);//每隔0.5秒刷新一次
	}
}

//更新函数，利用gamectrl来控制chessbd
void GameWindow::Update() {
	gamectrl->UpdateChessbd(chessbd);//对植物等Object状态进行更新
	chessbd->Update();//棋盘的内容进行更新
}

//刷新屏幕
void GameWindow::Show() {
	system("cls");
	chessbd->Show();//棋盘显示
}