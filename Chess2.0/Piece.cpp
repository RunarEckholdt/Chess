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
	color = Color::BLANK;
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
