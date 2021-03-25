#pragma once
#include"ChessBoard.h"
#include<Windows.h>
#include<iostream>
using namespace std;
class GameWindow
{
public:
	GameWindow();
	~GameWindow();
	void Show();

private:
	ChessBoard* chessboard;

};

