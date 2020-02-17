#pragma once
#include "Piece.h"



class PieceOverview{
	Color color;
	int pawnsLeft;
	int rooksLeft;
	int knightsLeft;
	int bishopsLeft;
	int queensLeft;
	int kingsLeft;
public:
	PieceOverview(Color);
	int piecesLeft(Kind) const;
	void regDeadPiece(Kind);
};
