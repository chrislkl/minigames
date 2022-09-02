#include <iostream>
#include <string>
#include "queen.h"
#include "board.h"
using namespace std;

Queen::Queen(char name, int x, int y, string player): Piece(name, x, y, player) {
}

Queen::~Queen() {

}

vector<int> Queen::DOgetPathCoords(int x, int y, Board *b) {
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

    if (this->x > x) {
        if (this->y > y) {
            for (int i = 1; i < this->x - x; i++) {
                path.emplace_back(x+i);
                path.emplace_back(y+i);
            }
        } else {
            for (int i = 1; i < this->x - x; i++) {
                path.emplace_back(x+i);
                path.emplace_back(y-i);
            }
        }
    } else {
        if (this->y > y) {
            for (int i = 1; i < x - this->x; i++) {
                path.emplace_back(this->x+i);
                path.emplace_back(this->y-i);
            }
        } else {
            for (int i = 1; i < x - this->x; i++) {
                path.emplace_back(this->x+i);
                path.emplace_back(this->y+i);
            }
        }
    }

    return path;
}

bool Queen::DOcheckValidMove(int x, int y) {
    if (x < 0 || x >= 8 || y < 0 || y >= 8) {
        return false;
    } else if (this->x == x && this->y == y) {
        return false;
    }

    int diffX = x - this->x;
    int diffY = y - this->y;
    if (diffX < 0) {
        diffX = diffX * -1;
    }
    if (diffY < 0) {
        diffY = diffY * -1;
    }
    if (diffX == diffY) { // checking diagonal
        return true;
    }

    if (this->x == x || this-> y == y) { // checking lateral
        return true;
    }
    return false;
}


bool Queen::DOcheckCaptureMove(int x, int y, Board *b) {
}

bool Queen::DOcheckBlockingPiece(int x, int y, Board *b) {
    if (this->x == x) {
        for (int i = minimum(this->y, y)+1; i < maximum(this->y, y); i++) {
            if (b->getPlayerAt(x, i) != "none") {
                return true;
            }
        }
        return false;
    } else if (this->y == y) { 
        for (int i = minimum(this->x, x)+1; i < maximum(this->x, x); i++) {
            if (b->getPlayerAt(i, y) != "none") {
                return true;
            }
        }
        return false;
    }

    if (this->x > x) {
        if (this->y > y) {
            for (int i = 1; i < this->x - x; i++) {
                if (b->getPlayerAt(x+i, y+i) != "none") {
                    return true;
                }
            }
        } else {
            for (int i = 1; i < this->x - x; i++) {
                if (b->getPlayerAt(x+i, y-i) != "none") {
                    return true;
                }
            }
        }
    } else {
        if (this->y > y) {
            for (int i = 1; i < x - this->x; i++) {
                if (b->getPlayerAt(this->x+i, this->y-i) != "none") {
                    return true;
                }
            }
        } else {
            for (int i = 1; i < x - this->x; i++) {
                if (b->getPlayerAt(this->x+i, this->y+i) != "none") {
                    return true;
                }
            }
        }
    }
    return false;
}

