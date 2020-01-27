#include "Piece.h"
#include "MovementCheck.h"
#include "../std_lib_facilities.h"

MovementCheck mcheck;
bool running = true;

class CinError {};

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
		case Kind::Pawn:
			piecesLeft = 8;
			break;
		case Kind::Rook:
			piecesLeft = 2;
			break;
		case Kind::Knight:
			piecesLeft = 2;
			break;
		case Kind::Bishop:
			piecesLeft = 2;
			break;
		case Kind::Queen:
			piecesLeft = 1;
			break;
		case Kind::King:
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
	Color c = Color::White;
	for (int y = 0; y < 2; y++) {
			for (int i = 1; i <= 8; i++) {//making pawns first round white, second round black
				Piece piece(Kind::Pawn, c, id, i, 2+5*y);
				pieces.push_back(piece);
				id++;
			}
			c = Color::Black;
			id = 17;
		}
	id = 9;
	c = Color::White;
	for (int y = 0; y < 2; y++) {
		for (int i = 0; i < 2; i++) {//making rooks
			Piece piece(Kind::Rook, c, id, 1+7*i, 1 + 7 * y);
			pieces.push_back(piece);
			id++;
		}
		id = 25;
		c = Color::Black;
	}
	id = 11;
	c = Color::White;
	for (int y = 0; y < 2; y++) {
		for (int i = 0; i < 2; i++) {//making knights
			Piece piece(Kind::Knight, c, id, 2 + 5 * i, 1 + 7 * y);
			pieces.push_back(piece);
			id++;
		}
		id = 27;
		c = Color::Black;
	}

	id = 13;
	c = Color::White;
	for (int y = 0; y < 2; y++) {
		for (int i = 0; i < 2; i++) {//making bishop
			Piece piece(Kind::Bishop, c, id, 3 + 3 * i, 1 + 7 * y);
			pieces.push_back(piece);
			id++;
		}
		id = 29;
		c = Color::Black;
	}
	id = 15;
	c = Color::White;
	for (int y = 0; y < 2; y++) {//making queens
		Piece piece(Kind::Queen, c, id, 4, 1 + 7 * y);
		pieces.push_back(piece);
		id = 31;
		c = Color::Black;
	}
	id = 16;
	c = Color::White;
	for (int y = 0; y < 2; y++) {//making kings
		Piece piece(Kind::King, c, id, 5, 1 + 7 * y);
		pieces.push_back(piece);
		id = 32;
		c = Color::Black;
	}



	
}

string stringPiece(Color color,Kind kind) {
	string text = "";
	if (color == Color::White)
		text.append("White ");
	else
		text.append("Black ");
	switch (kind)
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
	return text;
}


void printBoard() {
	system("CLS");
	String Board[8][8];
	for (int i = 0; i < 32; i++) {
		string text = stringPiece(pieces[i].getColor(), pieces[i].getKind());
		Board[pieces[i].getYPos() - 1][pieces[i].getXPos() - 1].append(text);
	}
	for (int y = 8; y >= 1; y--) {
		cout << y;
		for (int i = 0; i < 8; i++) {
			cout <<setw(1)<< "[" << setw(12) << Board[y-1][i]<< setw(1) << "]";
		}
		cout << endl;
	}
	for (int i = 1; i <= 8; i++) 
		cout << setw(14) << i;
	cout << endl;
}

int* DeltaPos(int curPos[], int newPos [],int* deltaPos) {
	deltaPos[0] = newPos[0] - curPos[0]; //x
	deltaPos[1] = newPos[1] - curPos[1]; //y
	cout << "Deltapos: " << deltaPos[0] << " " << deltaPos[1] << endl;
	return deltaPos;
}

bool allowedPath() {
	return true;
}

bool checkMovement(int deltaPos[],Piece piece,int newPos[]) {
	switch (piece.getKind())
	{
	case Kind::Pawn:
		cout << "Checking movement for pawn\n";
		if (mcheck.allowedPawnMovement(deltaPos, piece.getColor(), piece.getYPos(), newPos,PieceAtPos(newPos)) && allowedPath())
			return true;
		break;
	case Kind::Rook:
		if (mcheck.allowedRookMovement(deltaPos, piece.getColor(), newPos,PieceAtPos(newPos)) && allowedPath())
			return true;
		break;
	case Kind::Knight:
		break;
	case Kind::Bishop:
		break;
	case Kind::Queen:
		break;
	case Kind::King:
		break;
	default:
		break;
	}
	return false;
}


int* readCords(int* pos) {
	try {
		for (int i = 0; i < 2; i++) {
			cin >> pos[i];
			if (!cin)throw CinError {};
		}
		return pos;
	}
	catch(CinError){
		cin.clear();
		cin.ignore(10000, '\n');
		cerr << "Invalid input\n";
		return readCords(pos);
	
	}
}

void player1() {
	printBoard();
	while (true) {
		cout << "Piece to move: ";
		int pos[2];
		readCords(pos);
		Piece piece = PieceAtPos(pos);
		if (piece.getColor() != Color::White) {
			cerr << "You are not allowed to move this piece";
		}
		else {
			string pieceString = (stringPiece(piece.getColor(), piece.getKind()));
			cout << "Where do you want to move this " << pieceString << "?\n";
			int newPos[2];
			readCords(newPos);
			int dP[2];
			DeltaPos(pos, newPos, dP);
			if (checkMovement(dP, piece, newPos)) {
				cout << "Movement sucess\n";
				piece.changePos(newPos[0], newPos[1]);
				for (int i = 0; i < 32; i++) {
					if (piece.getId() == pieces[i].getId())
						pieces[i] = piece;
				}
				return;
			}
			else
				cerr << "Movement not allowed\n";
		}
	}


}

void player2() {
	return;
}

void game() {
	
	makePieces();
	//printBoard();
	while (running) {
		player1();
		player2();
	}
}



int main() {
	game();


	return 0;
}