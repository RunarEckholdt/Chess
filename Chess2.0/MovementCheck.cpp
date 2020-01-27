#include "MovementCheck.h"

bool MovementCheck::allowedPawnMovement(int dP[], Color color, int yPos, int newPos[], Piece pieceAtPos) {//dP = deltaPosition
	if (color == Color::White) {
		if (dP[0] == 0 && pieceAtPos.getId() == -1) {//if no movement in x axis and no piece at position (id -1 represent no piece) a forward movemnt with pawn does not allow killing enemy piece
			if (dP[1] == 2 && yPos == 2)return true;
			if (dP[1] == 1) return true;
		}
		if (abs(dP[0]) == 1 && dP[1] == 1 && pieceAtPos.getColor() == Color::Black)
			return true;
		return false;
	}
	if (color == Color::Black) {
		if (dP[0] == 0 && pieceAtPos.getId() == -1) {//if no movement in x axis and no piece at position (id -1 represent no piece)
			if (dP[1] == -2 && yPos == 7)return true;
			if (dP[1] == -1) return true;
		}
		if (abs(dP[0]) == 1 && dP[1] == -1 && pieceAtPos.getColor() == Color::White)
			return true;
		return false;
	}
	return false;
}


bool MovementCheck::allowedRookMovement(int dP[], Color color, int newPos[], Piece pieceAtPos) {
	if (dP[0] > 0 && dP[1] == 0 + dP[0] == 0 && dP[1] > 0) {
		if (pieceAtPos.getColor() != color)return true;//if piece at pos is not the same as piece moving
	}
	return false;

}


bool MovementCheck::allowedBishopMovement(int dP[], Color color, int newPos[], Piece pieceAtPos) {
	if (abs(dP[0]) > 0 && abs(dP[0]) == abs(dP[1]) && pieceAtPos.getColor() != color)
		return true;
	return false;
}


bool MovementCheck::allowedKnighMovement(int dP[], Color color, int newPos[], Piece pieceAtPos) {
	if (pieceAtPos.getColor() != color) {
		if (abs(dP[0]) == 1 && abs(dP[1]) == 2)return true;
		else if (abs(dP[0]) == 2 && abs(dP[1]) == 1)return true;
	}
	return false;
}

bool MovementCheck::allowedQueenMovement(int dP[], Color color, int newPos[], Piece pieceAtPos){
	if (dP[0] > 0 && dP[1] == 0 + dP[0] == 0 && dP[1] > 0) {
		if (pieceAtPos.getColor() != color)return true;//if piece at pos is not the same as piece moving
	}
	if (abs(dP[0]) > 0 && abs(dP[0]) == abs(dP[1]) && pieceAtPos.getColor() != color)
		return true;
	return false;
}

bool MovementCheck::allowedKingMovement(int dP[], Color color, int newPos[], Piece pieceAtPos) {
	return true;
}

