#ifndef _QUEEN_H_
#define _QUEEN_H_
#include <iostream>
#include <string>
#include <vector>
#include "piece.h"

class Queen: public Piece {
    bool DOcheckValidMove(int x, int y);
    bool DOcheckCaptureMove(int x, int y, Board *b);
    bool DOcheckBlockingPiece(int x, int y, Board *b);
    std::vector<int> DOgetPathCoords(int x, int y, Board *b);
    public:
    Queen(char name, int x, int y, std::string player);
    ~Queen();
};

#endif
