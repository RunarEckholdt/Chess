#include "AllowedPath.h"
class Cordinates {
public:
	int xPos;
	int yPos;
	Cordinates(int x,int y):xPos(x),yPos(y){}
};

bool AllowedPath::allowedPath(int deltaPos[], Piece& piece, int newPos[]) {
	if (newPos[0] > 0 && newPos[0] <= 8 && newPos[1] > 0 && newPos[1] <= 8) {
		if (piece.getKind() == Kind::Knight)return true;

	}
	else return false;
}




vector<Cordinates> getPositionsToScan(int deltaPos[], int newPos[], int curPos[]);
bool scanPositions(vector <Cordinates>&);

vector<Cordinates> getPositionsToScan(int deltaPos[],int newPos[],int curPos[]) {
	vector <Cordinates> scanningPos;
	if (deltaPos[0] == 0 && deltaPos[1] > 0) { //moving positive y axis
		for (int i = 0; i < deltaPos[1]; i++) {
			Cordinates cord(curPos[0], curPos[1] + i + 1);
			scanningPos.push_back(cord);
		}
	}
	else if (deltaPos[0] == 0 && deltaPos[1] < 0) { //moving negative y axis
		for (int i = 0; i < abs(deltaPos[1]); i++) {
			Cordinates cord(curPos[0], curPos[1] - i - 1);
			scanningPos.push_back(cord);
		}
	}
	else if (deltaPos[0] > 0 && deltaPos[1] == 0) { //moving positive x axis
		for (int i = 0; i < deltaPos[0]; i++) {
			Cordinates cord(curPos[0]+i+1, curPos[1]);
			scanningPos.push_back(cord);
		}
	}
	else if (deltaPos[0] < 0 && deltaPos[1] == 0) { //moving negative x axis
		for (int i = 0; i < abs(deltaPos[0]); i++) {
			Cordinates cord(curPos[0] - i - 1, curPos[1]);
			scanningPos.push_back(cord);
		}
	}

}