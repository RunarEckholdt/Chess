#include "AllowedPath.h"





void getPositionsToScan(vector <Cordinates>&,int deltaPos[], int curPos[]);
bool scanPosition(Cordinates, vector <Piece>&);
bool piecesBlockcing(vector<Cordinates>&, vector <Piece>&);




bool piecesBlocking(vector<Cordinates>& scanningPositions, vector <Piece>& pieces) {
	for (int i = 0; i < scanningPositions.size(); i++) {
		if (scanPosition(scanningPositions[i], pieces)) return true;
	}
	return false;
}

bool AllowedPath::allowedPath(int deltaPos[], Piece& piece, int newPos[], vector <Piece>& pieces) {
	if (newPos[0] > 0 && newPos[0] <= 8 && newPos[1] > 0 && newPos[1] <= 8) {
		if (piece.getKind() == Kind::Knight)return true;
		int curPos[] = { piece.getXPos(),piece.getYPos() };
		vector <Cordinates> scanningPos;
		getPositionsToScan(scanningPos,deltaPos,curPos);
		if (scanningPos.size() == 0) {
			return true;
		}
		if (piecesBlocking(scanningPos, pieces) == false) { 
			cout << "No piece blocking the path"<< endl;
			return true; 
			
		}
		cout << "Piece is blocking the path" << endl;
		
	}
	return false;
}




void getPositionsToScan(vector <Cordinates>& scanningPos,int deltaPos[],int curPos[]) {
	
	if (deltaPos[0] == 0 && deltaPos[1] > 0) { //moving positive y axis
		for (int i = 1; i < deltaPos[1]; i++) {
			Cordinates cord(curPos[0], curPos[1] + i);
			scanningPos.push_back(cord);
		}
	}
	else if (deltaPos[0] == 0 && deltaPos[1] < 0) { //moving negative y axis
		for (int i = 1; i < abs(deltaPos[1]); i++) {
			Cordinates cord(curPos[0], curPos[1] - i);
			scanningPos.push_back(cord);
		}
	}
	else if (deltaPos[0] > 0 && deltaPos[1] == 0) { //moving positive x axis
		for (int i = 1; i < deltaPos[0]; i++) {
			Cordinates cord(curPos[0] + i, curPos[1]);
			scanningPos.push_back(cord);
		}
	}
	else if (deltaPos[0] < 0 && deltaPos[1] == 0) { //moving negative x axis
		for (int i = 1; i < abs(deltaPos[0]); i++) {
			Cordinates cord(curPos[0] - i, curPos[1]);
			scanningPos.push_back(cord);
		}
	}else if (deltaPos[0] > 0 && deltaPos[0] == deltaPos[1]) { //diagonal movement positive x and y axis
		for (int i = 1; i < deltaPos[0]; i++) {
			Cordinates cord(curPos[0] + i, curPos[1] + i);
			scanningPos.push_back(cord);
		}
	}
	else if (deltaPos[0] < 0 && deltaPos[1] > 0 && abs(deltaPos[0]) == deltaPos[1]) {  //diagonal movement negative x axis positive y axis
		for (int i = 1; i < abs(deltaPos[0]); i++) {
			Cordinates cord(curPos[0] - i, curPos[1] + i);
			scanningPos.push_back(cord);
		}
	}
	else if (deltaPos[0] > 0 && deltaPos[1] < 0 && deltaPos[0] == abs(deltaPos[1])) {  //diagonal movement positive x axis negative y axis
		for (int i = 1; i < deltaPos[0]; i++) {
			Cordinates cord(curPos[0] + i, curPos[1] - i);
			scanningPos.push_back(cord);
		}
	}
	else if (deltaPos[0] < 0 && deltaPos[1] < 0 && deltaPos[0] == deltaPos[1]) {  //diagonal movement negative x axis negative y axis
		for (int i = 1; i < deltaPos[0]; i++) {
			Cordinates cord(curPos[0] - i, curPos[1] - i);
			scanningPos.push_back(cord);
		}
	}
	

}




bool scanPosition(Cordinates pos, vector <Piece>& pieces) {
	for (int i = 0; i < pieces.size(); i++) {
		Cordinates pieceCord(pieces[i].getXPos(), pieces[i].getYPos());
		if (pos == pieceCord) { 
			cout << pos.xPos << " " << pos.yPos << endl;
			cout << pieces[i] << endl;
			return true;
		}
	}
	return false;
}




bool operator==(Cordinates p1, Cordinates p2) {
	if (p1.xPos = p2.xPos && p1.yPos == p2.yPos)return true;
	return false;
}