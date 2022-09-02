#ifndef _PIECE_H_
#define _PIECE_H_
#include <iostream>
#include <string>
#include <vector>

class Board;

class Piece {
    protected:
    char name;
    int x;
    int y;
    std::string player;
    virtual void DOupdatehasMoved(bool moved);
    virtual bool DOcheckValidMove(int x, int y) = 0 ; // checks if a piece can move to a certain tile, BUT does NOT check state of the board. ie: won't check for blocking pieces, or friendly pieces, etc
    virtual bool DOcheckBlockingPiece(int x, int y, Board *b) = 0; // checks if by moving to x, y, it is blocked by another piece && // assumes move is already valid (from checkValidMove())
    virtual bool DOcheckCaptureMove(int x, int y, Board *b) = 0;
    virtual std::vector<int> DOgetPathCoords(int x, int y, Board *b) = 0; //assumes move is valid
    public:
    Piece(char name, int x, int y, std::string player);
    virtual ~Piece() = 0;
    void printPiece();
    char getName();
    std::string getPlayer();
    bool isThreatened(Board *b);
    std::vector<int> findThreatening(Board *b);
    bool isPinned(Board *b);
    bool checkMoveRemovesPin(int x, int y, Board *b); // assumes move is valid. assumes Piece is pinned before moving
    bool checkMoveMakesThreatened(int x, int y, Board *b); // assumes move is valid 
    bool checkMoveMakesCheck(int x, int y, Board *b);
    void updateX(int n);
    void updateY(int n);
    int getX();
    int getY();
    void updatehasMoved(bool moved);
    bool checkValidMove(int x, int y);
    bool checkBlockingPiece(int x, int y, Board *b);
    bool checkCaptureMove(int x, int y, Board *b);
    std::vector<int> getPathCoords(int x, int y, Board *b);
};

int minimum(int a, int b);
int maximum(int a, int b);

#endif
