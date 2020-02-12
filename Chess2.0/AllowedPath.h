#include "Piece.h"
#pragma once


class AllowedPath
{
public:
	bool allowedPath(int deltapos[],Piece& piece, int newPos[],vector <Piece>& pieces);
};






bool operator==(Cordinates p1, Cordinates p2);

