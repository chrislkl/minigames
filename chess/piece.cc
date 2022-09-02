#include <iostream>
#include <string>
#include "piece.h"
#include "board.h"

using namespace std;

Piece::Piece(char name, int x, int y, std::string player): name{name}, x{x}, y{y}, player{player} {}

void Piece::printPiece() {
    cout << name;
}

char Piece::getName() {
    return name;
}

string Piece::getPlayer() {
    return player;
}

Piece::~Piece() {}

void Piece::updateX(int n) {
    x = n;
}

void Piece::updateY(int n) {
    y = n;
}

int Piece::getX() {
    return x;
}

int Piece::getY() {
    return y;
}

bool Piece::isThreatened(Board *b) {
    for (int i = 0; i < b->getRow(); i++) {
        for (int j = 0; j < b->getCol(); j++) {
            if ((b->getPlayerAt(j, i) != player) && (b->getPlayerAt(j, i) != "none")) {
                if (b->checkValidMove(j, i, x, y)) {
                    return true;
                } 
            }
        }
    }
    return false;
}



bool Piece::checkValidMove(int x, int y) {
    return DOcheckValidMove(x,y);
}
bool Piece::checkBlockingPiece(int x, int y, Board *b) {
    return DOcheckBlockingPiece(x,y,b);
}
bool Piece::checkCaptureMove(int x, int y, Board *b) {
    return DOcheckCaptureMove(x,y,b);
}
std::vector<int> Piece::getPathCoords(int x, int y, Board *b) {
    return DOgetPathCoords(x,y,b);
}

vector<int> Piece::findThreatening(Board *b) {
    vector<int> coords;
    for (int i = 0; i < b->getRow(); i++) {
        for (int j = 0; j < b->getCol(); j++) {
            if ((b->getPlayerAt(j, i) != player) && (b->getPlayerAt(j, i) != "none")) {
                if (b->checkValidMove(j, i, x, y)) {
                    coords.emplace_back(j);
                    coords.emplace_back(i);
                } 
            }
        }
    }
    return coords;
}

bool Piece::isPinned(Board *b) {
    Piece *tmp = this;
    b->grid[x][y] = new NoPiece(' ', x, y, "none");
    if (b->grid[b->locateKingX(player)][b->locateKingY(player)]->isThreatened(b)) {
        delete b->grid[x][y];
        b->grid[x][y] = tmp;
        return true;
    }
    delete b->grid[x][y];
    b->grid[x][y] = tmp;
    return false;
}



bool Piece::checkMoveRemovesPin(int x, int y, Board *b) {
    Piece *tmp = b->grid[x][y];
    b->grid[x][y] = b->grid[this->x][this->y];
    b->grid[this->x][this->y] = new NoPiece(' ', x, y, "none");
    if (b->grid[b->locateKingX(player)][b->locateKingY(player)]->isThreatened(b)) {
        delete b->grid[this->x][this->y];
        b->grid[this->x][this->y] = b->grid[x][y];
        b->grid[x][y] = tmp;
        return false;
    }

    delete b->grid[this->x][this->y];
    b->grid[this->x][this->y] = b->grid[x][y];
    b->grid[x][y] = tmp;
    return true;
}

void Piece::DOupdatehasMoved(bool moved) {
}

void Piece::updatehasMoved(bool moved) {
    this->DOupdatehasMoved(moved);
}

bool Piece::checkMoveMakesThreatened(int x, int y, Board *b) {
    Piece *tmp = b->grid[x][y];
    b->grid[x][y] = b->grid[this->x][this->y];
    b->grid[this->x][this->y] = new NoPiece(' ', x, y, "none");
    int tmpX = b->grid[x][y]->x;
    int tmpY = b->grid[x][y]->y;
    b->grid[x][y]->x = x;
    b->grid[x][y]->y = y;
    if (b->isThreatened(x,y)) {
        b->grid[x][y]->x = tmpX;
        b->grid[x][y]->y = tmpY;
        delete b->grid[this->x][this->y];
        b->grid[this->x][this->y] = b->grid[x][y];
        b->grid[x][y] = tmp;
        return true;
    }

    b->grid[x][y]->x = tmpX;
    b->grid[x][y]->y = tmpY;
    delete b->grid[this->x][this->y];
    b->grid[this->x][this->y] = b->grid[x][y];
    b->grid[x][y] = tmp;
    return false;
}

bool Piece::checkMoveMakesCheck(int x, int y, Board *b) {
    string oppoPlayer = "none";
    if (player == "white") {
        oppoPlayer = "black";
    } else {
        oppoPlayer = "white";
    }

    Piece *tmp = b->grid[x][y];
    b->grid[x][y] = b->grid[this->x][this->y];
    b->grid[this->x][this->y] = new NoPiece(' ', x, y, "none");
    int tmpX = b->grid[x][y]->x;
    int tmpY = b->grid[x][y]->y;
    b->grid[x][y]->x = x;
    b->grid[x][y]->y = y;
    if (b->grid[b->locateKingX(oppoPlayer)][b->locateKingY(oppoPlayer)]->isThreatened(b)) {
        b->grid[x][y]->x = tmpX;
        b->grid[x][y]->y = tmpY;
        delete b->grid[this->x][this->y];
        b->grid[this->x][this->y] = b->grid[x][y];
        b->grid[x][y] = tmp;
        return true;
    }

    b->grid[x][y]->x = tmpX;
    b->grid[x][y]->y = tmpY;
    delete b->grid[this->x][this->y];
    b->grid[this->x][this->y] = b->grid[x][y];
    b->grid[x][y] = tmp;
    return false;
}

int minimum(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int maximum(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}