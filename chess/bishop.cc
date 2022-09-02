#include <iostream>
#include <string>
#include "bishop.h"
#include "board.h"
using namespace std;

Bishop::Bishop(char name, int x, int y, string player): Piece(name, x, y, player) {
}

Bishop::~Bishop() {

}

bool Bishop::DOcheckValidMove(int x, int y) {
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
    return diffX == diffY;
}

bool Bishop::DOcheckCaptureMove(int x, int y, Board *b) {
}

vector<int> Bishop::DOgetPathCoords(int x, int y, Board *b) {
    vector<int> path;
    path.emplace_back(this->x);
    path.emplace_back(this->y);
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

bool Bishop::DOcheckBlockingPiece(int x, int y, Board *b) {
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

