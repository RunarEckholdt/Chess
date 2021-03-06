#include"AllowedPath.h"

//using namespace std;

void setup();
void createBoard();
void gameOver();
Cordinate readCords();
void player(bool);
void generatePieces(vector<Piece>&);
Piece* PieceAtPos(Cordinate pos);
void printBoard();
void movement(Piece* piece, Cordinate newPos);
bool checkMovement(int deltaPos[], Piece* piece, Cordinate newPos);
void updatePieceAtBoard(Piece* piece, Cordinate newPos);



MovementCheck mCheck;
AllowedPath aPath;
PieceOverview whiteOverview(Color::White);
PieceOverview blackOverview(Color::Black);

class CinError {};


bool running = true;
vector <Piece> pieces;
Piece* board[8][8];


int main()
{
	
	setup();
	while (running) {
		player(true);
		player(false);
	}
	gameOver();
	

}

void setup() {
	generatePieces(pieces);
	createBoard();
	
}

void createBoard() {
	for (Piece& piece : pieces) {
		if (piece.getXPos() > 0 && piece.getYPos() > 0) { //hvis brikken ikke er flyttet av brettet (d�d)
			board[piece.getYPos() - 1][piece.getXPos() - 1] = &piece; //possisjonerer brikken i en array etter kordinatene dens

		}
	}
}

void gameOver() {
	printBoard();
	if (whiteOverview.piecesLeft(Kind::King) == 0) {
		cout << "Player 2 wins!" << endl;
	}
	else if (blackOverview.piecesLeft(Kind::King) == 0) {
		cout << "Player 1 wins!" << endl;
	}
}

int* DeltaPos(Cordinate curPos, Cordinate newPos, int* deltaPos) {
	deltaPos[0] = newPos.xPos - curPos.xPos; //x
	deltaPos[1] = newPos.yPos - curPos.yPos; //y
	//cout << "Deltapos: " << deltaPos[0] << " " << deltaPos[1] << endl;
	return deltaPos;
}

Cordinate readCords() {
	int x, y;
	try {
		cin >> x >>y;
		if (!cin)throw CinError{};
		return Cordinate(x,y);
	}
	catch (CinError) {
		cin.clear();
		cin.ignore(10000, '\n');
		cerr << "Invalid input\n";
		return readCords();

	}
}

void player(bool isWhite) {
	printBoard();
	if (isWhite) cout << "Player 1: " << endl; 
	else cout << "Player 2: " << endl;

	while (true) {
		cout << "Piece to move: ";
		Cordinate pos = readCords();
		Piece* piece = PieceAtPos(pos);
		if (piece == nullptr) {
			cerr << "There is no piece here to move\n";
		}
		else if (piece->getColor() == Color::Black&&isWhite || piece->getColor() == Color::White && !isWhite) {
			cerr << "You are not allowed to move this piece\n";
		}
		else 
		{
			cout << "Where do you want to move this " << *piece << "?\n";
			Cordinate newPos = readCords();
			int dP[2];
			DeltaPos(pos, newPos, dP);
			if (checkMovement(dP, piece, newPos)) {
				movement(piece, newPos);
				return;
			}
			else
				cerr << "Movement not allowed\n";
		}
	}
}

void generatePieces(vector<Piece>& pieces) {
	int id = 1;
	Color c = Color::White;
	for (int y = 0; y < 2; y++) {
		for (int i = 1; i <= 8; i++) {//making pawns first round white, second round black
			Cordinate startPos(i, 2 + 5 * y);
			Piece piece(Kind::Pawn, c, id, startPos);
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
			Cordinate startPos(1 + 7 * i, 1 + 7 * y);
			Piece piece(Kind::Rook, c, id, startPos);
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
			Cordinate startPos(2 + 5 * i, 1 + 7 * y);
			Piece piece(Kind::Knight, c, id, startPos);
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
			Cordinate startPos(3 + 3 * i, 1 + 7 * y);
			Piece piece(Kind::Bishop, c, id, startPos);
			pieces.push_back(piece);
			id++;
		}
		id = 29;
		c = Color::Black;
	}
	id = 15;
	c = Color::White;
	for (int y = 0; y < 2; y++) {//making queens
		Cordinate startPos(4, 1 + 7 * y);
		Piece piece(Kind::Queen, c, id, startPos);
		pieces.push_back(piece);
		id = 31;
		c = Color::Black;
	}
	id = 16;
	c = Color::White;
	for (int y = 0; y < 2; y++) {//making kings
		Cordinate startPos(5, 1 + 7 * y);
		Piece piece(Kind::King, c, id, startPos);
		pieces.push_back(piece);
		id = 32;
		c = Color::Black;
	}
}

 
Piece* PieceAtPos(Cordinate pos) {
	if (board[pos.yPos - 1][pos.xPos - 1] != nullptr)return board[pos.yPos - 1][pos.xPos - 1];
	return nullptr;
}



void printBoard() {
	system("CLS");
	for (int y = 8; y >= 1; y--) {
		
		cout << y;
		for (int i = 0; i < 8; i++) {
			if(board[y - 1][i]!=nullptr)cout << setw(1) << "[" << setw(12) << *board[y - 1][i] << setw(1) << "]";
			else cout << setw(1) << "[" << setw(12) << "" << setw(1) << "]";
			
		}
		cout << endl;
		
	}
	for (int i = 1; i <= 8; i++)
		cout << setw(14) << i;
	cout << endl;
}

bool checkMovement(int deltaPos[], Piece* piece, Cordinate newPos) {
	if (aPath.allowedPosition(newPos, *piece, PieceAtPos(newPos)) && aPath.allowedPath(deltaPos, *piece, newPos)) {
		switch (piece->getKind())
		{
		case Kind::Pawn:
			cout << "Checking movement for pawn\n";
			if (mCheck.allowedPawnMovement(deltaPos, piece->getColor(), piece->getYPos(), PieceAtPos(newPos)))
				return true;
			break;
		case Kind::Rook:
			if (mCheck.allowedRookMovement(deltaPos))
				return true;
			break;
		case Kind::Knight:
			if (mCheck.allowedKnightMovement(deltaPos))
				return true;
			break;
		case Kind::Bishop:
			if (mCheck.allowedBishopMovement(deltaPos))
				return true;
			break;
		case Kind::Queen:
			if (mCheck.allowedQueenMovement(deltaPos))
				return true;

			break;
		case Kind::King:
			if (mCheck.allowedKingMovement(deltaPos))
				return true;
			break;
			return false;
		}
	}
}

void movement(Piece* piece, Cordinate newPos) {
	
	Piece* pieceNewPos = PieceAtPos(newPos);
	
	if (pieceNewPos != nullptr) {//hvis det er en brikke der, endre posisjonen dens ut av kartet
		if (pieceNewPos->getKind() == Kind::King)
			running = false;
		updatePieceAtBoard(pieceNewPos, Cordinate(-1, -1));
		pieceNewPos->changePos(Cordinate(-1, -1));//-1 representerer at brikken er d�d
		if (pieceNewPos->getColor() == Color::Black) 
			blackOverview.regDeadPiece(pieceNewPos->getKind());
		else 
			whiteOverview.regDeadPiece(pieceNewPos->getKind());
	}
	if (pieceNewPos == nullptr) delete pieceNewPos;
	updatePieceAtBoard(piece, newPos);
	piece->changePos(newPos);
	
	

}

void updatePieceAtBoard(Piece* piece, Cordinate newPos) {
	board[piece->getYPos() - 1][piece->getXPos() - 1] = nullptr;
	if (newPos.yPos > 0 && newPos.xPos > 0) {
		board[newPos.yPos - 1][newPos.xPos - 1] = piece;
	}
}