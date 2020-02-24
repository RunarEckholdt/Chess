#pragma once
#include "PieceOverview.h"
class MovementCheck
{
public:
	bool allowedPawnMovement(int deltaPos[],Color,int yPos,Piece* pieceAtPos);
	bool allowedRookMovement(int deltaPos[]);
	bool allowedKnightMovement(int deltaPos[]);
	bool allowedBishopMovement(int deltaPos[]);
	bool allowedQueenMovement(int deltaPos[]);
	bool allowedKingMovement(int deltaPos[]);
};

