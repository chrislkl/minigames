#include <iostream>
#include <string>
#include "knight.h"
#include "board.h"
using namespace std;

Knight::Knight(char name, int x, int y, string player): Piece(name, x, y, player) {
}

Knight::~Knight() {

}

vector<int> Knight::DOgetPathCoords(int x, int y, Board *b) {
    vector<int> path;
    path.emplace_back(this->x);
    path.emplace_back(this->y);
    return path;
}

bool Knight::DOcheckValidMove(int x, int y) {
    if (x < 0 || x >= 8 || y < 0 || y >= 8) {
        return false;
    } else if (this->x == x && this->y == y) {
        return false;
    }

    if (this->x == x + 1 && this->y == y + 2) { // could put all these conditions in one if statement but separated them to be more human-readable
        return true;
    } else if (this->x == x - 1 && this->y == y + 2) { 
        return true;
    } else if (this->x == x + 2 && this->y == y + 1) { 
        return true;
    } else if (this->x == x + 2 && this->y == y - 1) { 
        return true;
    } else if (this->x == x + 1 && this->y == y - 2) { 
        return true;
    } else if (this->x == x - 1 && this->y == y - 2) { 
        return true;
    } else if (this->x == x - 2 && this->y == y + 1) { 
        return true;
    } else if (this->x == x - 2 && this->y == y - 1) { 
        return true;
    }

    return false;
}


bool Knight::DOcheckCaptureMove(int x, int y, Board *b) {
}

bool Knight::DOcheckBlockingPiece(int x, int y, Board *b) {
    return false;
}

