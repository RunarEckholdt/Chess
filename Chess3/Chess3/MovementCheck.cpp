#include "MovementCheck.h"

bool MovementCheck::allowedPawnMovement(int dP[], Color color, int yPos, Piece* pieceAtPos) {
	if (color == Color::White) {
		if (pieceAtPos == nullptr) {
			if (dP[0] == 0) {//if no movement in x axis and no piece at position (id -1 represent no piece) a forward movemnt with pawn does not allow killing enemy piece
				if (dP[1] == 2 && yPos == 2 && pieceAtPos == nullptr)return true;
				if (dP[1] == 1 && pieceAtPos == nullptr) return true;
			}
		}
		if (abs(dP[0]) == 1 && dP[1] == 1 && pieceAtPos->getColor() == Color::Black)
			return true;
		return false;
	}
	if (color == Color::Black) {
		if (dP[0] == 0) {
			if (dP[1] == -2 && yPos == 7)return true;
			if (dP[1] == -1) return true;
		}
		if (abs(dP[0]) == 1 && dP[1] == -1 && pieceAtPos->getColor() == Color::White)
			return true;
		return false;
	}
	return false;
}

bool MovementCheck::allowedRookMovement(int dP[]) {
	if (abs(dP[0]) > 0 && dP[1] == 0 || dP[0] == 0 && abs(dP[1]) > 0) { //just movement in x axis or just movement in y axis
		return true;
	}
	return false;
}

bool MovementCheck::allowedKnightMovement(int dP[]) {
	if (abs(dP[0]) == 1 && abs(dP[1]) == 2)return true; //1 in x axis and two in y axis or
	if (abs(dP[0]) == 2 && abs(dP[1]) == 1)return true;//2 in x axis and 1 in y axis
	return false;
}

bool MovementCheck::allowedBishopMovement(int dP[]) {
	if (abs(dP[0]) > 0 && abs(dP[0]) == abs(dP[1]))//there is a movement and movement in x and y axis is the same (diagonal movement)
		return true;
	return false;
}

bool MovementCheck::allowedQueenMovement(int dP[]) {
	if (abs(dP[0]) > 0 && dP[1] == 0 || dP[0] == 0 && abs(dP[1]) > 0) {
		return true;
	}
	if (abs(dP[0]) > 0 && abs(dP[0]) == abs(dP[1]))
		return true;
	return false;
}

bool MovementCheck::allowedKingMovement(int dP[]) {
	if ((abs(dP[0]) > 0 || abs(dP[1]) > 0) && (abs(dP[0] <= 1 && dP[1] <= 1)))return true; //there is movement in atleast one if the axis and none of the axis movement is larger than one
	return false;
}