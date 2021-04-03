#pragma once
#include"ChessBoard.h"
#include"PlantShop.h"

class GameControl
{
public:
	GameControl() { }
	~GameControl() { }
	void UpdateChessbd(ChessBoard* chessbd,PlantShop* pshop);
	void PlantControl(Object* obj, ChessBoard* chessbd,PlantShop* pshop);
	void ZombieControl(Object* obj, ChessBoard* chessbd);
	void BulletControl(Bullet* blt, ChessBoard* chessbd);

private:
	
};

