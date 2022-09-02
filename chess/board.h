#ifndef _BOARD_H_
#define _BOARD_H_
#include <iostream>
#include <string>
#include <vector>
#include "piece.h"
#include "rook.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
#include "pawn.h"
#include "knight.h"
#include "nopiece.h"

class Piece;

class Board {
    std::vector<std::vector<Piece*>> grid;
    int col;
    int row;
    public:
    Board(bool setup);
    ~Board();
    void printBoard();

    int getRow();
    int getCol();
    bool twoKingsExist();
    bool noPawnsFirstandLastRow();
    int locateKingX(std::string player);
    int locateKingY(std::string player); //assumes exactly 1 king exists (of each side)
    bool kingValidMoveExists(std::string player);
    bool isPinned(int x, int y); 
    bool isThreatened(int x, int y);
    bool checkValidMove(int fromX, int fromY, int toX, int toY);
    bool checkPreventThreat(int x, int y, int threatX, int threatY);
    void place(char name, int x, int y, std::string player);
    void remove(int x, int y);
    void move(int fromX, int fromY, int toX, int toY);
    void checkPawnPromotion(int x, int y);
    void promotePawnComp(int x, int y);
    std::string getPlayerAt(int x, int y);
    std::vector<int> getPathCoords(int fromX, int fromY, int toX, int toY);
    std::vector<int> getRandomLegalMove(int x, int y);
    std::vector<int> getRandomCaptureMoveofPiece(int x, int y); // gets random capture move for a piece at (x,y)
    std::vector<int> getRandomCaptureMove(std::string player); // above but for whole board
    std::vector<int> getRandomCheckMoveofPiece(int x, int y);
    std::vector<int> getRandomCheckMove(std::string player);
    std::vector<int> getRandomThreatenedPiece(std::string player);
    std::vector<int> getRandomAvoidCaptureMove(int x, int y); // assumes (x,y) is threatened

    std::string checkCheckmate(std::string player);
    bool checkStalemate(std::string player);

    friend bool Piece::isPinned(Board *b);
    friend bool Piece::checkMoveRemovesPin(int x, int y, Board *b);
    friend bool Piece::checkMoveMakesThreatened(int x, int y, Board *b);
    friend bool Piece::checkMoveMakesCheck(int x, int y, Board *b);
};

std::string coordsToString(int x, int y);

#endif
