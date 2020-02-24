#include "AllowedPath.h"







void getPositionsToScan(vector <Cordinate>&, int deltaPos[], Cordinate curPos);
bool scanPosition(Cordinate);
bool piecesBlocking(vector<Cordinate>&);

extern vector <Piece> pieces;





bool AllowedPath::allowedPath(int deltaPos[], Piece& piece, Cordinate newPos) {
	//cout << piece.getId() << endl;
	 
		if (piece.getKind() == Kind::Knight)return true;
		Cordinate curPos = {piece.getCordinate()};
		vector <Cordinate> scanningPos;
		getPositionsToScan(scanningPos, deltaPos, curPos);
		if (scanningPos.size() == 0) {
			return true;
		}
		if (piecesBlocking(scanningPos) == false) {
			cout << "No piece blocking the path" << endl;
			return true;

		}
		cout << "Piece is blocking the path" << endl;

	
	return false;
}

bool AllowedPath::allowedPosition(Cordinate newPos, const Piece& piece, Piece* pieceAtPos) {
	if (newPos.xPos > 0 && newPos.xPos <= 8 && newPos.yPos > 0 && newPos.yPos <= 8) {
		if (pieceAtPos == nullptr)return true;
		else if (piece.getColor() != pieceAtPos->getColor()) {
			return true;
		}
	}
	return false;
}




void getPositionsToScan(vector <Cordinate>& scanningPos, int deltaPos[], Cordinate curPos) {

	if (deltaPos[0] == 0 && deltaPos[1] > 0) { //moving positive y axis
		for (int i = 1; i < deltaPos[1]; i++) {
			Cordinate cord(curPos.xPos, curPos.yPos + i);
			scanningPos.push_back(cord);
		}
	}
	else if (deltaPos[0] == 0 && deltaPos[1] < 0) { //moving negative y axis
		for (int i = 1; i < abs(deltaPos[1]); i++) {
			Cordinate cord(curPos.xPos, curPos.yPos - i);
			scanningPos.push_back(cord);
		}
	}
	else if (deltaPos[0] > 0 && deltaPos[1] == 0) { //moving positive x axis
		for (int i = 1; i < deltaPos[0]; i++) {
			Cordinate cord(curPos.xPos + i, curPos.yPos);
			scanningPos.push_back(cord);
		}
	}
	else if (deltaPos[0] < 0 && deltaPos[1] == 0) { //moving negative x axis
		for (int i = 1; i < abs(deltaPos[0]); i++) {
			Cordinate cord(curPos.xPos - i, curPos.yPos);
			scanningPos.push_back(cord);
		}
	}
	else if (deltaPos[0] > 0 && deltaPos[0] == deltaPos[1]) { //diagonal movement positive x and y axis
		for (int i = 1; i < deltaPos[0]; i++) {
			Cordinate cord(curPos.xPos + i, curPos.yPos + i);
			scanningPos.push_back(cord);
		}
	}
	else if (deltaPos[0] < 0 && deltaPos[1] > 0 && abs(deltaPos[0]) == deltaPos[1]) {  //diagonal movement negative x axis positive y axis
		for (int i = 1; i < abs(deltaPos[0]); i++) {
			Cordinate cord(curPos.xPos - i, curPos.yPos + i);
			scanningPos.push_back(cord);
		}
	}
	else if (deltaPos[0] > 0 && deltaPos[1] < 0 && deltaPos[0] == abs(deltaPos[1])) {  //diagonal movement positive x axis negative y axis
		for (int i = 1; i < deltaPos[0]; i++) {
			Cordinate cord(curPos.xPos + i, curPos.yPos - i);
			scanningPos.push_back(cord);
		}
	}
	else if (deltaPos[0] < 0 && deltaPos[1] < 0 && deltaPos[0] == deltaPos[1]) {  //diagonal movement negative x axis negative y axis
		for (int i = 1; i < deltaPos[0]; i++) {
			Cordinate cord(curPos.xPos - i, curPos.yPos - i);
			scanningPos.push_back(cord);
		}
	}


}


bool piecesBlocking(vector<Cordinate>& scanningPositions) {
	for (int i = 0; i < scanningPositions.size(); i++) {
		if (scanPosition(scanningPositions[i])) return true;
	}
	return false;
}



bool scanPosition(Cordinate pos) {
	for (int i = 0; i < pieces.size(); i++) {
		Cordinate pieceCord(pieces[i].getCordinate().xPos, pieces[i].getCordinate().yPos);
		if (pos == pieceCord) {
			/*cout << pos.xPos << " " << pos.yPos << endl;
			cout << pieces[i].getId() << endl;
			cout << pieces[i] << endl;
			cout << pieces[i].getXPos() << " " << pieces[i].getYPos() << endl;*/
			return true;
		}
	}
	return false;
}



