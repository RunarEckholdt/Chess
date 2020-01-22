#include "Piece.h"
#pragma once
class MovementCheck {
public:
	bool allowedPawnMovement(int dP[], Color color, int yPos, int newPos[], Piece pieceAtPos); //dP = deltaPosition
	bool allowedRookMovement(int dP[], Color color, int newPos[], Piece pieceAtPos);
	bool allowedKnighMovement(int dP[], Color color, int newPos[], Piece pieceAtPos);
	bool allowedBishopMovement(int dP[], Color color, int newPos[], Piece pieceAtPos);
	bool allowedQueenMovement(int dP[], Color color, int newPos[], Piece pieceAtPos);
	bool allowedKingMovement(int dP[], Color color, int newPos[], Piece pieceAtPos);
};

