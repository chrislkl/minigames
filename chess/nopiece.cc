#include <iostream>
#include <string>
#include "nopiece.h"
#include "board.h"
using namespace std;

NoPiece::NoPiece(char name, int x, int y, string player): Piece(name, x, y, player) {
}

NoPiece::~NoPiece() {

}

bool NoPiece::DOcheckValidMove(int x, int y) { 
    return false;
}


bool NoPiece::DOcheckCaptureMove(int x, int y, Board *b) {
}

bool NoPiece::DOcheckBlockingPiece(int x, int y, Board *b) {
    return false; // will never run
}

vector<int> NoPiece::DOgetPathCoords(int x, int y, Board *b) { // never runs
    vector<int> path;
    return path;
}

