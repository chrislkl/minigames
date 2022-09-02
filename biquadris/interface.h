#ifndef _INTERFACE_H_
#define _INTERFACE_H_
#include <iostream>
#include <string>
#include <vector>
#include "block.h"
#include "board.h"
#include "level.h"
#include "one.h"
#include "two.h"
#include "zero.h"
#include "three.h"
#include "four.h"


class Interface {
    Board *board;
    Block *currBlock;
    Block *nextBlock;
    Level *level;
    int intLevel;
    int score;
    int highScore;
    std::string file;
    void updateLevel(int);
    int seed;
    bool endGame;
    public:
    int getScore();
    int gethighScore();
    bool blind;
    bool heavy;
    bool force;
    void activateForce(std::string);
    bool specialAction;
    bool heavySwitch;
    bool getEndGame();
    void printBoardInterfaceLine(int, bool);
    void printNextBlockLine(int, bool);
    void printOverheadLine(int, bool);
    void updateNoRandomLevel(std::string); // for norandom and random commands
    void updateRandomLevel(); // for norandom and random commands
    Interface(int, int, std::string, int, int);
    ~Interface();

    int getRowTotal();

    void action(std::string, int);
};

#endif
