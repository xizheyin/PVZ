#pragma once
#include"ChessBoard.h"


class GameControl
{
public:
	GameControl() { }
	~GameControl() { }
	void UpdateChessbd(ChessBoard* chessbd);
	void PlantControl(Object* obj, ChessBoard* chessbd);
	void ZombieControl(Object* obj, ChessBoard* chessbd);
	void BulletControl(Bullet* blt, ChessBoard* chessbd);

private:
	
};

