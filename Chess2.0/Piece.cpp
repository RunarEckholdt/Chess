#include "Piece.h"


Kind Piece::getKind() { return kind; }
Color Piece::getColor() { return color; }
int Piece::getId() { return id; }
int Piece::getXPos() { return xPos; }
int Piece::getYPos() { return yPos; }

void Piece::changePos(int x, int y) {
	xPos = x;
	yPos = y;
}

vector <int> Piece::getPos() {
	vector <int> pos;
	pos.push_back(xPos);
	pos.push_back(yPos);
	return pos;
}


Piece::Piece() {
	kind = Kind::NONE;
	color = Color::NONE;
	id = -1;
	xPos = 0;
	yPos = 0;
}

Piece::Piece(Kind k, Color c, int i, int x, int y) {
	kind = k;
	color = c;
	id = i;
	xPos = x;
	yPos = y;
}


ostream& operator<<(ostream& os, Piece piece) {
	string text = "";
	if (piece.getColor() == Color::White)
		text.append("White ");
	else
		text.append("Black ");
	switch (piece.getKind())
	{
	case Kind::Pawn:
		text.append("Pawn");
		break;
	case Kind::Rook:
		text.append("Rook");
		break;
	case Kind::Knight:
		text.append("Knigh");
		break;
	case Kind::Bishop:
		text.append("Bishop");
		break;
	case Kind::Queen:
		text.append("Queen");
		break;
	case Kind::King:
		text.append("King");
		break;
	default:
		break;
	}
	
	return os << text;
}
