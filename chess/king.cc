#include <iostream>
#include <string>
#include "king.h"
#include "board.h"
using namespace std;

King::King(char name, int x, int y, string player): Piece(name, x, y, player) {
}

King::~King() {

}

vector<int> King::DOgetPathCoords(int x, int y, Board *b) {
    vector<int> path;
    path.emplace_back(this->x);
    path.emplace_back(this->y);
    return path;
}

bool King::DOcheckValidMove(int x, int y) {
    if (x < 0 || x >= 8 || y < 0 || y >= 8) {
        return false;
    } else if (this->x == x && this->y == y) {
        return false;
    }
    
    if (this->x == x && this->y == y + 1) { // could put all these conditions in one if statement but separated them to be more human-readable
        return true;
    } else if (this->x == x && this->y == y - 1) { 
        return true;
    } else if (this->y == y && this->x == x + 1) { 
        return true;
    } else if (this->y == y && this->x == x - 1) { 
        return true;
    } else if (this->y == y + 1 && this->x == x + 1) { 
        return true;
    } else if (this->y == y + 1 && this->x == x - 1) { 
        return true;
    } else if (this->y == y - 1 && this->x == x + 1) { 
        return true;
    } else if (this->y == y - 1 && this->x == x - 1) { 
        return true;
    }

    // remember to check for castling

    return false;
}

bool King::DOcheckCaptureMove(int x, int y, Board *b) {
}

bool King::DOcheckBlockingPiece(int x, int y, Board *b) { // cannot get blocked
    return false;
}

