#ifndef _KNIGHT_H_
#define _KNIGHT_H_
#include <iostream>
#include <string>
#include <vector>
#include "piece.h"

class Knight: public Piece {
    bool DOcheckValidMove(int x, int y);
    bool DOcheckCaptureMove(int x, int y, Board *b);
    bool DOcheckBlockingPiece(int x, int y, Board *b);
    std::vector<int> DOgetPathCoords(int x, int y, Board *b);
    public:
    Knight(char name, int x, int y, std::string player);
    ~Knight();
};

#endif
