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
	
	Piece(Kind k, Color c, int i, int x, int y) {
		kind = k;
		color = c;
		id = i;
		xPos = x;
		yPos = y;
	}


};



class PieceOverwiev {
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

	PieceOverwiev(Kind k, Color c) {
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
vector <PieceOverwiev> pieceOverwiev;

void makePieces() {
	for(int i = 0; i < )
}








int main() {



	return 0;
}