#include "PieceOverview.h"



PieceOverview::PieceOverview(Color color){
	this->color = color;
	pawnsLeft = 8;
	rooksLeft = 2;
	knightsLeft = 2;
	bishopsLeft = 2;
	queensLeft = 1;
	kingsLeft = 1;
}

int PieceOverview::piecesLeft(Kind kind) const {
	switch (kind)
	{
	case Kind::Pawn:
		return pawnsLeft;
	case Kind::Rook:
		return rooksLeft;
	case Kind::Knight:
		return knightsLeft;
	case Kind::Bishop:
		return bishopsLeft;
	case Kind::Queen:
		return queensLeft;
	case Kind::King:
		return kingsLeft;
	default:
		return 0;
	}
}

void PieceOverview::regDeadPiece(Kind kind) {
	switch (kind)
	{
	case Kind::Pawn:
		pawnsLeft--;
		break;
	case Kind::Rook:
		rooksLeft--;
		break;
	case Kind::Knight:
		knightsLeft--;
		break;
	case Kind::Bishop:
		bishopsLeft--;
		break;
	case Kind::Queen:
		queensLeft--;
		break;
	case Kind::King:
		kingsLeft--;
		break;
	}
}