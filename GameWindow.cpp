#include "GameWindow.h"



GameWindow::GameWindow():chessboard(new ChessBoard()) {

}
GameWindow::~GameWindow() {
	delete chessboard;
}

void GameWindow::Show() {
	system("cls");
	while (1) {
		system("cls");
		chessboard->Show();
		Sleep(1000);
	}
}