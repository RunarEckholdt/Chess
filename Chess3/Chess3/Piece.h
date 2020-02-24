#include "..\std_lib_facilities.h"
enum class Kind { Pawn, Rook, Knight, Bishop, Queen, King, NONE };
enum class Color {White, Black, NONE};
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
	int getXPos() const;
	int getYPos() const;

	void changePos(Cordinate);

	~Piece();
	Piece();
	Piece(Kind,Color,int,Cordinate);

};




ostream& operator<<(ostream&, const Cordinate&);
ostream& operator<<(ostream&, const Piece&);

bool operator==(const Piece&, const Piece&);
bool operator==(const Cordinate&, const Cordinate&);





