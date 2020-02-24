#pragma once
#include "MovementCheck.h"



class AllowedPath
{
public:
	bool allowedPath(int deltapos[], Piece& piece, Cordinate newPos);
	bool allowedPosition(Cordinate newPos,const Piece& piece, Piece* pieceAtPos);
};

