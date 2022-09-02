#ifndef _PAWN_H_
#define _PAWN_H_
#include <iostream>
#include <string>
#include <vector>
#include "piece.h"

class Pawn: public Piece {
    bool hasMoved;
    void DOupdatehasMoved(bool) override;
    bool DOcheckValidMove(int x, int y);
    bool DOcheckCaptureMove(int x, int y, Board *b);
    bool DOcheckBlockingPiece(int x, int y, Board *b);
    std::vector<int> DOgetPathCoords(int x, int y, Board *b);
    public:
    Pawn(char name, int x, int y, std::string player);
    ~Pawn();
};

int absValue(int x);

#endif
