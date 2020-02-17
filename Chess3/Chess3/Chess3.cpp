#include"AllowedPath.h"

void setup();
void player(bool);
void generatePieces(vector<Piece>&);
Piece PieceAtPos(Cordinate pos);
void printBoard();


MovementCheck mCheck;
AllowedPath aPath;
PieceOverview whiteOverview(Color::White);
PieceOverview blackOverview(Color::Black);

class CinError {};


bool running = true;
vector <Piece> pieces;


int main()
{
	Piece a(Kind::Pawn, Color::White, 56, Cordinate(1, 4));
	cout << a << endl; 
	setup();
	/*while (myGlobals::running) {
		player(true);
		player(false);
	}*/
	

}

void setup() {
	generatePieces(pieces);
	printBoard();
}

void player(bool isWhite) {

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

 
Piece PieceAtPos(Cordinate pos) {

	for (Piece x : pieces) {
		if (x.getCordinate()==pos)
			return x;
	}
	Piece none;
	return none;
}



void printBoard() {
	system("CLS");
	Piece Board[8][8];
	for (Piece piece:pieces) {
		if (piece.getXPos() > 0 && piece.getYPos() > 0) { //hvis brikken ikke er flyttet av brettet (død)
			Board[piece.getYPos() - 1][piece.getXPos() - 1] = piece; //possisjonerer brikken i en array etter kordinatene dens
			
		}
	}
	for (int y = 8; y >= 1; y--) {
		/*cout << " ";
		for (int i = 0; i < 8; i++) {
			cout << setw(1) << "/" << setw(12) << "" << setw(1) << char(92);
		}
		cout << endl;*/
		cout << y;
		for (int i = 0; i < 8; i++) {
			cout << setw(1) << "[" << setw(12) << Board[y-1][i] << setw(1) << "]";
		}
		cout << endl;
		/*cout << " ";
		for (int i = 0; i < 8; i++) {
			cout << setw(1) << char(92) << setw(12) << "" << setw(1) << "/";
		}
		cout << endl;*/
		//cout << "----------------------------------------------------------------------------------------------------------------\n";
	}
	for (int i = 1; i <= 8; i++)
		cout << setw(14) << i;
	cout << endl;
}

