#include "../std_lib_facilities.h"
enum Kind {Pawn,Rook,Knight,Bishop,Queen,King};
enum Color {White,Black};




class Piece {
	Kind kind;
	Color color;
	int id;
	int xPos;
	int yPos;
public:
	Kind getKind() { return kind; }
	Color getColor() { return color; }
	int getId() { return id; }
	int getXPos() { return xPos; }
	int getYPos() { return yPos; }

	void changePos(int x, int y) {
		xPos = x;
		yPos = y;
	}

	vector <int> getPos() {
		vector <int> pos;
		pos.push_back(xPos);
		pos.push_back(yPos);
		return pos;
	}
	

	
	
	Piece(Kind k, Color c, int i, int x, int y) {
		kind = k;
		color = c;
		id = i;
		xPos = x;
		yPos = y;
	}


};



class PieceOverview {
	Kind kind;
	Color color;
	int piecesLeft;
public:
	Kind getKind() { return kind; }
	Color getColor() { return color; }
	int getPiecesLeft() { return piecesLeft; }

	void pieceDead() {
		piecesLeft--;
	}

	PieceOverview(Kind k, Color c) {
		kind = k;
		color = c;
		switch (kind)
		{
		case Pawn:
			piecesLeft = 8;
			break;
		case Rook:
			piecesLeft = 2;
			break;
		case Knight:
			piecesLeft = 2;
			break;
		case Bishop:
			piecesLeft = 2;
			break;
		case Queen:
			piecesLeft = 1;
			break;
		case King:
			piecesLeft = 1;
			break;
		default:
			break;
		}
	}

};

vector <Piece> pieces;
vector <PieceOverview> pieceOverview;

void makePieces() {
	int id = 1;
	Color c = White;
	for (int y = 0; y < 2; y++) {
			for (int i = 1; i <= 8; i++) {//making pawns first round white, second round black
				Piece piece(Pawn, c, id, i, 2+5*y);
				pieces.push_back(piece);
				id++;
			}
			c = Black;
			id = 17;
		}
	id = 9;
	c = White;
	for (int y = 0; y < 2; y++) {
		for (int i = 0; i < 2; i++) {//making rooks
			Piece piece(Rook, c, id, 1+7*i, 1 + 7 * y);
			pieces.push_back(piece);
			id++;
		}
		id = 25;
		c = Black;
	}
	id = 11;
	c = White;
	for (int y = 0; y < 2; y++) {
		for (int i = 0; i < 2; i++) {//making knights
			Piece piece(Knight, c, id, 2 + 5 * i, 1 + 7 * y);
			pieces.push_back(piece);
			id++;
		}
		id = 27;
		c = Black;
	}

	id = 13;
	c = White;
	for (int y = 0; y < 2; y++) {
		for (int i = 0; i < 2; i++) {//making bishop
			Piece piece(Bishop, c, id, 3 + 3 * i, 1 + 7 * y);
			pieces.push_back(piece);
			id++;
		}
		id = 29;
		c = Black;
	}
	id = 15;
	c = White;
	for (int y = 0; y < 2; y++) {//making queens
		Piece piece(Queen, c, id, 4, 1 + 7 * y);
		pieces.push_back(piece);
		id = 31;
		c = Black;
	}
	id = 16;
	c = White;
	for (int y = 0; y < 2; y++) {//making kings
		Piece piece(King, c, id, 5, 1 + 7 * y);
		pieces.push_back(piece);
		id = 32;
		c = Black;
	}



	
}

string stringKind(Kind kind) {
	switch (kind)
	{
	case Pawn:
		return "Pawn";
		break;
	case Rook:
		return "Rook";
		break;
	case Knight:
		return "Knight";
		break;
	case Bishop:
		return "Bishop";
		break;
	case Queen:
		return "Queen";
		break;
	case King:
		return "King";
		break;
	default:
		break;
	}
}






int main() {



	return 0;
}