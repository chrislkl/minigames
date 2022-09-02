#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_
#include <iostream>
#include <string>
#include "board.h"

class Controller {
    Board *b;
    std::string black; //human or comp
    std::string white; //human or comp
    std::string turn; //black or white
    double blackScore;
    double whiteScore;
    public:
    explicit Controller(std::string black, std::string white, bool setup);
    void updateBlack(std::string);
    void updateWhite(std::string);
    std::string getBlack();
    std::string getWhite();
    void updateTurn(std::string);
    void addOneScore(std::string);
    void addHalfScore();
    double getBlackScore();
    double getWhiteScore();
    std::string getTurn();
    void replaceBoard(bool setup);
    bool isValidSetup();
    void printBoard();
    void action(std::string);
    void compAction(std::string);
    void setup(std::string);
    std::string checkCheckmate(std::string);
    bool checkStalemate(std::string);
    bool checkCheck(std::string);
    ~Controller();
};

int coordsToXInt(std::string s);
int coordsToYInt(std::string s);
bool validPieceName(char);

#endif
