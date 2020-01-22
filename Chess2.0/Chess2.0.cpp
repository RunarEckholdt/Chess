#include "Piece.h"
#include "MovementCheck.h"

MovementCheck mcheck;

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

Piece PieceAtPos(int pos[]) {
	for (Piece x : pieces) {
		if (x.getXPos() == pos[0] && x.getYPos() == pos[1])
			return x;
	}
	Piece none;
	return none;
}

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

string stringPiece(Color color,Kind kind) {
	string text = "";
	if (color == White)
		text.append("White ");
	else
		text.append("Black ");
	switch (kind)
	{
	case Pawn:
		text.append("Pawn");
		break;
	case Rook:
		text.append("Rook");
		break;
	case Knight:
		text.append("Knigh");
		break;
	case Bishop:
		text.append("Bishop");
		break;
	case Queen:
		text.append("Queen");
		break;
	case King:
		text.append("King");
		break;
	default:
		break;
	}
	return text;
}


void printBoard() {
	system("CLS");
	String Board[8][8];
	for (int i = 0; i < 32; i++) {
		string text = stringPiece(pieces[i].getColor(), pieces[i].getKind());
		Board[pieces[i].getYPos() - 1][pieces[i].getXPos() - 1].append(text);
	}
	for (int y = 7; y >= 0; y--) {
		for (int i = 0; i < 8; i++) {
			cout << setw(14) << Board[y][i];
		}
		cout << endl;
	}
}

int* DeltaPos(int curPos[], int newPos []) {
	int deltaPos[] = { newPos[0] - curPos[0], newPos[1] - curPos[1] }; //where first value is x second value is y
	return deltaPos;
}

bool allowedPath();

bool checkMovement(int deltaPos[],Piece piece,int newPos[]) {
	switch (piece.getKind())
	{
	case Pawn:
		if (mcheck.allowedPawnMovement(deltaPos, piece.getColor(), piece.getYPos(), newPos,PieceAtPos(newPos)) && allowedPath())
			return true;
		break;
	case Rook:
		if (mcheck.allowedRookMovement(deltaPos, piece.getColor(), newPos,PieceAtPos(newPos)) && allowedPath())
			return true;
		break;
	case Knight:
		break;
	case Bishop:
		break;
	case Queen:
		break;
	case King:
		break;
	default:
		break;
	}
	return false;
}



bool isRed[8][8];



void game() {
	makePieces();
	printBoard();
}



int main() {
	game();


	return 0;
}