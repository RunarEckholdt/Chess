#include "Piece.h"



Kind Piece::getKind () const { return kind; }
Color Piece::getColor() const { return color; }
int Piece::getId() const { return id; }
Cordinate Piece::getCordinate() const { return cordinate; }
int Piece::getXPos() const { return cordinate.xPos; }
int Piece::getYPos() const { return cordinate.yPos; }

void Piece::changePos(Cordinate cordinate) {
	this->cordinate = cordinate;
}

Piece::~Piece(){}

Piece::Piece() {
	kind = Kind::NONE;
	color = Color::NONE;
}

Piece::Piece(Kind kind, Color color, int id, Cordinate cordinate){
	this->kind = kind;
	this->color = color;
	this->id = id;
	this->cordinate = cordinate;
}
	


ostream& operator<<(ostream& os, const Cordinate& cordinate){
	return os << "[" << cordinate.xPos << "," << cordinate.yPos << "]";
}

ostream& operator<<(ostream& os, const Piece& piece) {
	string s = "";
	switch (piece.getColor()) {
		case Color::White:
			s += "White";
			break;
		case Color::Black:
			s += "Black";
			break;
	}
	s += " ";
	switch (piece.getKind()){
		case Kind::Pawn:
			s += "Pawn";
			break;
		case Kind::Rook:
			s += "Rook";
			break;
		case Kind::Knight:
			s += "Knight";
			break;
		case Kind::Bishop:
			s += "Bishop";
			break;
		case Kind::Queen:
			s += "Queen";
			break;
		case Kind::King:
			s += "King";
			break;
	}
	return os << s;
}

bool operator==(const Piece& p1, const Piece& p2) {
	return p1.getId() == p2.getId();
}

bool operator==(const Cordinate& c1, const Cordinate& c2) {
	return c1.xPos == c2.xPos
		&& c1.yPos == c2.yPos;
}




