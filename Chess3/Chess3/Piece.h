#include "..\std_lib_facilities.h"
enum class Kind { Pawn, Rook, knight, Bishop, Queen, King, NONE };
enum class Color {white, black, NONE};
#pragma once

struct Cordinate
{
public:
	int xPos = 0;
	int yPos = 0;
	Cordinate(){}
	Cordinate(int x, int y) :xPos(x), yPos(y){}

};

class Piece{
	Kind kind;
	Color color;
	int id = 0;
	Cordinate cordinate;
public:
	Kind getKind() const;
	Color getColor() const;
	int getId() const;
	Cordinate getCordinate() const;

	void changePos(Cordinate);

	Piece();
	Piece(Kind,Color,int,Cordinate);

};




ostream& operator<<(ostream&, const Cordinate&);
ostream& operator<<(ostream&, Piece);

bool operator==(const Piece&, const Piece&);
bool operator==(const Cordinate&, const Cordinate&);
