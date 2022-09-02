#include <iostream>
#include <string>
#include "rook.h"
#include "board.h"
using namespace std;

Rook::Rook(char name, int x, int y, string player): Piece(name, x, y, player) {
}

Rook::~Rook() {}

vector<int> Rook::DOgetPathCoords(int x, int y, Board *b) {
    vector<int> path;
    path.emplace_back(this->x);
    path.emplace_back(this->y);
    if (this->x == x) {
        for (int i = minimum(this->y, y)+1; i < maximum(this->y, y); i++) {
            path.emplace_back(x);
            path.emplace_back(i);
        }
    } else { 
        for (int i = minimum(this->x, x)+1; i < maximum(this->x, x); i++) {
            path.emplace_back(i);
            path.emplace_back(y);
        }
    }
    return path;
}

bool Rook::DOcheckValidMove(int x, int y) {
    if (x < 0 || x >= 8 || y < 0 || y >= 8) {
        return false;
    } else if (this->x == x && this->y == y) {
        return false;
    }
    return (this->x == x || this-> y == y);
}

bool Rook::DOcheckCaptureMove(int x, int y, Board *b) {
}

bool Rook::DOcheckBlockingPiece(int x, int y, Board *b) { 
    if (this->x == x) {
        for (int i = minimum(this->y, y)+1; i < maximum(this->y, y); i++) {
            if (b->getPlayerAt(x, i) != "none") {
                return true;
            }
        }
        return false;
    } else { 
        for (int i = minimum(this->x, x)+1; i < maximum(this->x, x); i++) {
            if (b->getPlayerAt(i, y) != "none") {
                return true;
            }
        }
        return false;
    }
}
