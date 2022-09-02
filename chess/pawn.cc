#include <iostream>
#include <string>
#include "pawn.h"
#include "board.h"
using namespace std;

Pawn::Pawn(char name, int x, int y, string player): Piece(name, x, y, player), hasMoved{false} {
}

Pawn::~Pawn() {

}

vector<int> Pawn::DOgetPathCoords(int x, int y, Board *b) {
    vector<int> path;
    path.emplace_back(this->x);
    path.emplace_back(this->y);
    if (absValue(this->y - y) >= 2) {
        if (y < this->y) {
            path.emplace_back(this->x);
            path.emplace_back(this->y - 1);
        } else {
            path.emplace_back(this->x);
            path.emplace_back(this->y + 1);
        }
    }
    return path;
}

void Pawn::DOupdatehasMoved(bool moved) {
    hasMoved = moved;
}

bool Pawn::DOcheckValidMove(int x, int y) {
    if (x < 0 || x >= 8 || y < 0 || y >= 8) {
        return false;
    } else if (this->x == x && this->y == y) {
        return false;
    }

    if (player == "white") {
        if (hasMoved) {
            if (this->x == x && this->y == y - 1) {
                return true;
            }
        } else {
            if (this->x == x && (this->y == y - 1 || this->y == y - 2)) {
                return true;
            }
        }
    } else if (player == "black") {
        if (hasMoved) {
            if (this->x == x && this->y == y + 1) {
                return true;
            }
        } else {
            if (this->x == x && (this->y == y + 1 || this->y == y + 2)) {
                return true;
            }
        }
    }
    return false;
}

bool Pawn::DOcheckCaptureMove(int x, int y, Board *b) { // assumes valid move 
    if (player == "white") {
        if ((this->x == x - 1 && this->y == y - 1) || (this->x == x + 1 && this->y == y - 1)) {
            if (b->getPlayerAt(x, y) == "black") {
                return true;
            }
        } 
    } else if (player == "black") {
        if ((this->x == x - 1 && this->y == y + 1) || (this->x == x + 1 && this->y == y + 1)) {
            if (b->getPlayerAt(x, y) == "white") {
                return true;
            }
        }
    }
    return false;
}

bool Pawn::DOcheckBlockingPiece(int x, int y, Board *b) { 
    if (this->x == x) {
        for (int i = minimum(this->y, y)+1; i < maximum(this->y, y); i++) {
            if (b->getPlayerAt(x, i) != "none") {
                return true;
            }
        }
        return false;
    }
    return (b->getPlayerAt(x, y) != "none");
}

int absValue(int x) {
    if (x < 0) {
        return x * -1;
    }
    return x;
}