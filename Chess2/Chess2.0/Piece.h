#include "../std_lib_facilities.h"
enum class Kind { Pawn, Rook, Knight, Bishop, Queen, King, NONE };
enum class Color { White, Black, NONE };
#pragma once

class Cordinates {
public:
	int xPos;
	int yPos;
	Cordinates(int x, int y) :xPos(x), yPos(y) {}
};

class Piece {
	Kind kind;
	Color color;
	int id;
	int xPos;
	int yPos;
public:
	Kind getKind();
	Color getColor();
	int getId();
	int getXPos();
	int getYPos();

	void changePos(int x, int y);
	vector <int> getPos();

	Piece();
	Piece(Kind k, Color c, int i, int x, int y);


};


ostream& operator<<(ostream&, Piece);